/**--------------------
 * Standard Segment Tree Template
 *
 * Time Consumption: N \log{N}
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/27
 * --------------------
 */
#include <iostream>
#include <cstdio>

#define MXN 200007
using namespace std;
typedef long long TP;

#define TP0 0
#define lson (root << 1)
#define rson (root << 1 | 1)
#define update(x) (stree[x] = stree[(x) << 1] + stree[(x) << 1 | 1])
#define mid(x, y) (((x) + (y)) >> 1)
TP raw[MXN];
TP stree[MXN << 2 | 1];
TP atag[MXN << 2 | 1];

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

TP query(int root, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return TP0;
    if (l >= ql && r <= qr) return stree[root];
    pushdown(root, l, r);
    return
        query(lson, l, mid(l, r), ql, qr) +
        query(rson, mid(l, r) + 1, r, ql, qr);
}

void add(int root, int l, int r, int al, int r, TP adata) {
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


