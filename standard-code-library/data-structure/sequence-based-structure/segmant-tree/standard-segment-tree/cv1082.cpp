#include <iostream>
#include <cstdio>

#define MXN 200007
using namespace std;
typedef long long ll;
#define lson (root << 1)
#define rson (root << 1 | 1)
#define update(x) (stree[x] = stree[(x) << 1] + stree[(x) << 1 | 1])
#define mid(x, y) (((x) + (y)) >> 1)
ll raw[MXN];
ll stree[MXN << 2 | 1];
ll atag[MXN << 2 | 1];

inline void pushdown(int root, int l, int r) {
    if (atag[root]) {
        atag[lson] += atag[root];
        atag[rson] += atag[root];
        stree[lson] += atag[root] * (mid(l, r) - l + 1);
        stree[rson] += atag[root] * (r - mid(l, r));
        atag[root] = 0;
    }
}

void build(int root, int l, int r) {
    if (l == r) {
        stree[root] = raw[l];
        return;
    }
    build(lson, l, mid(l, r));
    build(rson, mid(l, r) + 1, r);
    update(root);
}

ll query(int root, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (l >= ql && r <= qr) return stree[root];
    pushdown(root, l, r);
    return
        query(lson, l, mid(l, r), ql, qr) +
        query(rson, mid(l, r) + 1, r, ql, qr);
}

void add(int root, int l, int r, int al, int ar, ll adata) {
    if (al > r || ar < l) return;
    if (l >= al && r <= ar) {
        stree[root] += adata * (r - l + 1);
        atag[root] += adata;
        return;
    }
    pushdown(root, l, r);
    add(lson, l, mid(l, r), al, ar, adata);
    add(rson, mid(l, r) + 1, r, al, ar, adata);
    update(root);
}

int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", raw + i);
    build(1, 1, n);
    scanf("%d", &q);
    int a, b, c;
    ll x;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            scanf("%lld", &x);
            add(1, 1, n, b, c, x);
        } else {
            printf("%lld\n", query(1, 1, n, b, c));
        }
    }
}
