#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 100007
#define update(a) stree[a] = stree[a << 1 | 1] + stree[a << 1];
#define lson (root << 1)
#define rson (root << 1 | 1)
#define mid(l, r) (((l) + (r)) >> 1)
using namespace std;
typedef long long ll;

ll raw[MXN], stree[MXN << 2 | 1], atag[MXN << 2 | 1];
void init() {
    memset(raw, 0, sizeof(raw));
    memset(stree, 0, sizeof(stree));
    memset(atag, 0, sizeof(atag));
}
void build(int root, int l, int r) {
    if (l == r) {
        stree[root] = raw[l];
        return;
    }
    build(lson, l, mid(l, r));
    build(rson, mid(l, r) + 1, r);
    atag[root] = 0;
    update(root);
}
void pushdown(int root, int l, int r) {
    atag[lson] += atag[root];
    atag[rson] += atag[root];
    stree[lson] += atag[root] * (mid(l, r) - l + 1);
    stree[rson] += atag[root] * (r - mid(l, r));
    atag[root] = 0;
}
ll query(int root, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) {
        return stree[root];
    }
    pushdown(root, l, r);
    return query(lson, l, mid(l, r), ql, qr) + query(rson, mid(l, r) + 1, r, ql, qr);
}
void add(int root, int l, int r, int al, int ar, ll data) {
    if (al > r || ar < l) return;
    if (al <= l && ar >= r) {
        stree[root] += data * (r - l + 1);
        atag[root] += data;
        return;
    }
    pushdown(root, l, r);
    add(lson, l, mid(l, r), al, ar, data);
    add(rson, mid(l, r) + 1, r, al, ar, data);
    update(root);
}
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", raw + i);
    }
    build(1, 1, n);
    scanf("%d", &m);
    int a, b, c; ll data;
    while (m--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d %d %lld", &b, &c, &data);
            add(1, 1, n, b, c, data);
        } else {
            scanf("%d", &b);
            printf("%lld\n", query(1, 1, n, b, b));
        }
    }
    return 0;
}
