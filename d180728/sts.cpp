#include <cstdio>
#include <cstring>
#include <iostream>
#define lson (root << 1)
#define rson (root << 1 | 1)
#define mid ((l + r) >> 1)
#define N 50007
using namespace std;
typedef unsigned int uint; 
uint rt[N << 3 | 7], L[N << 9 | 7], R[N << 9 | 7], tag[N << 9 | 7], stree[N << 9 | 7];
int n, m;
uint cnt = 0;
void inneradd(uint &root, uint l, uint r, uint al, uint ar) {
    if (l > ar || r < al) return;
    if (!root) root = ++cnt;
    if (al <= l && r <= ar) {
        ++tag[root];
        stree[root] += r - l + 1;
        return;
    }
    inneradd(L[root], l, mid, al, ar);
    inneradd(R[root], mid + 1, r, al, ar);
    stree[root] = stree[L[root]] + stree[R[root]] + tag[root] * (r - l + 1);
}
void outeradd(uint root, uint l, uint r, uint al, uint ar, uint dta) {
    if (dta > r || dta < l) return;
    inneradd(rt[root], 1, n, al, ar);
    if (l >= r) return;
    outeradd(lson, l, mid, al, ar, dta);
    outeradd(rson, mid + 1, r, al, ar, dta);
}
uint innerans(uint root, uint l, uint r, uint ql, uint qr) {
    if (!root || l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return stree[root];
    uint tmp = innerans(L[root], l, mid, ql, qr) + innerans(R[root], mid + 1, r, ql ,qr);
    tmp += tag[root] * (min(qr, r) - max(ql, l) + 1);
    return tmp;
}
uint outerans(uint root, uint l, uint r, int ql, int qr, uint k) {
    if (l >= r) return l;
    uint tmp = innerans(rt[rson], 1, n, ql, qr);
    if (tmp >= k) return outerans(rson, mid + 1, r, ql, qr, k);
    else return outerans(lson, l, mid, ql, qr, k - tmp);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        uint o, l, r;
        int c;
        cin >> o >> l >> r >> c;
        if (o == 1) outeradd(1, 1, n * 2 + 2, l, r, c + n + 1);
        else cout << (outerans(1, 1, n * 2 + 2, l, r, c) - n - 1) << endl;
    }
    return 0;
}
