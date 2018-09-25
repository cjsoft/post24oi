#include <cstdio>
#include <iostream>
#include <cstring>
#define mid ((l + r) >> 1)
#define M 3100007
3000001.03100001.0
#define N 100007
#define MXA 1000000000
using namespace std;
typedef long long ll;
int ls[M], rs[M], ver[N];
ll stree[M];
ll arr[N];
int n, m;
int tot = 0;
void add(int oroot, int &root, int l, int r, ll dta) {
    root = ++tot;
    stree[root] = stree[oroot];
    if (l >= r) {
        stree[root] += dta;
        return;
    }
    ls[root] = ls[oroot];
    rs[root] = rs[oroot];
    if (dta <= mid) add(ls[oroot], ls[root], l, mid, dta);
    else add(rs[oroot], rs[root], mid + 1, r, dta);
    stree[root] = stree[ls[root]] + stree[rs[root]];
}
ll query(int rootl, int rootr, int l, int r, int ql, int qr) {
    if (ql > r || qr < l || stree[rootr] - stree[rootl] == 0) return 0;
    if (ql <= l && r <= qr) return stree[rootr] - stree[rootl];
    return
        query(ls[rootl], ls[rootr], l, mid, ql, qr) +
        query(rs[rootl], rs[rootr], mid + 1, r, ql, qr);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", arr + i);
        add(ver[i - 1], ver[i], 1, MXA, arr[i]);
    }
    scanf("%d", &m);
    while (m--) {
        int st, ed;
        scanf("%d %d", &st, &ed);
        for (ll i = 1, last;; i = last + 1) {
            last = query(ver[st - 1], ver[ed], 1, MXA, 1, i);
            if (last < i) {
                printf("%lld\n", i);
                break;
            }
        }
    }
}
