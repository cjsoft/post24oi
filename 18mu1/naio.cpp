#include <cstdio>
#include <cstring>
#include <iostream>
#define lson (root << 1)
#define rson (root << 1 | 1)
#define mid ((l + r) >> 1)
#define N 100007
using namespace std;

int a[N], b[N];
int n, q;
int stree[N << 2 | 7], mtree[N << 2 | 7], tag[N << 2 | 7];
void update(int root) {
    mtree[root] = min(mtree[lson], mtree[rson]);
    stree[root] = stree[lson] + stree[rson];
}
void build(int root, int l, int r) {
    tag[root] = 0;
    if (l >= r) {
        stree[root] = 0;
        mtree[root] = a[l];
        return;
    }
    build(lson, l, mid);
    build(rson, mid + 1, r);
    update(root);
}
void pushdown(int root, int l, int r) {
    if (tag[root]) {
        mtree[lson] -= tag[root];
        mtree[rson] -= tag[root];
        tag[lson] += tag[root];
        tag[rson] += tag[root];
        tag[root] = 0;
    }
}
void dec(int root, int l, int r, int dl, int dr) {
    if (l > dr || r < dl) return;
    if (dl <= l && r <= dr && mtree[root]-- > 1) {
        tag[root]++;
        return;
    }
    if (l == r) {
        mtree[root] = b[l];
        stree[root]++;
        return;
    }
    pushdown(root, l, r);
    dec(lson, l, mid, dl, dr);
    dec(rson, mid + 1, r, dl, dr);
    update(root);
}
int query(int root, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return stree[root];
    return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
}
int main() {
    memset(mtree, 0x3f, sizeof(mtree));
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i), a[i] = b[i];
    build(1, 1, n);
    char inpt[15];
    int a, b;
    while (q--) {
        scanf("%s %d %d", inpt, &a, &b);
        if (inpt[0] == 'a') {
            dec(1, 1, n, a, b);
        } else {
            printf("%d\n", query(1, 1, n, a, b));
        }
    }
    build(1, 1, n);
    return 0;
}
