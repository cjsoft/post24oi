#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define lson (root << 1)
#define rson (root << 1 | 1)
#define mid ((l + r) >> 1)
#define N 100007
using namespace std;
typedef long long ll;
const double PI = acos(-1);
ll v[N], vv[N];
int l[N << 2 | 7], r[N << 2 | 7], loc[N];
int n;
ll stree[N << 2 | 7];
inline void update(int root) {
    stree[root] = max(stree[lson], stree[rson]);
}
void edit(int root, int l, int r, int pos, ll data) {
    if (pos < l || pos > r) return;
    if (l == r) {
        stree[root] = data;
        return;
    }
    edit(lson, l, mid, pos, data);
    edit(rson, mid + 1, r, pos, data);
    update(root);
}
ll query(int root, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return stree[root];
    return max(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        ll r, h;
        scanf("%lld %lld", &r, &h);
        v[i] = vv[i] = r * r * h;
    }
    sort(v + 1, v + 1 + n);
    auto end = unique(v + 1, v + 1 + n);
    int mx = end - v + 1;
    for (int i = 1; i <= n; ++i)
        loc[i] = lower_bound(v + 1, end, vv[i]) - v + 1;
    for (int i = 1; i <= n; ++i) {
        ll tmp = query(1, 1, mx, 1, loc[i] - 1);
        edit(1, 1, mx, loc[i], tmp + vv[i]);
    }
    printf("%.10lf\n", stree[1] * PI);
    return 0;
}
