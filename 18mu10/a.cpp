#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define N 100007
#define MXC 1000000003
using namespace std;

int stree[N * 33], sz[N * 33], ll[N * 33], rr[N * 33];
int dp[N];
int tot = 0;

struct coor {
    int x, y, v;
    bool operator<(const coor &b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
} crds[N];

inline void update(int root) {
    stree[root] = max(stree[ll[root]], stree[rr[root]]);
    sz[root] = sz[ll[root]] + sz[rr[root]];
}

void edit(int &root, int l, int r, int pos, int dat) {
    if (!root) {
        root = ++tot;
    }
    if (l == r) {
        stree[root] = max(dat, stree[root]), sz[root] = 1;
        return;
    }
    if (pos > mid) edit(rr[root], mid + 1, r, pos, dat);
    else edit(ll[root], l, mid, pos, dat);
    update(root);
}

int findmax(int root, int l, int r, int ql, int qr) {
    if (ql > r || qr < l || root == 0) return -1;
    if (ql <= l && r <= qr) return stree[root];
    int rtn = 0;
    if (ql <= mid) rtn = max(rtn, findmax(ll[root], l, mid, ql, qr));
    if (qr > mid) rtn = max(rtn, findmax(rr[root], mid + 1, r, ql, qr));
    return rtn;
}

int n, root;
inline void init() {
    root = 0;
    memset(stree, 0, sizeof(stree));
    memset(sz, 0, sizeof(sz));
    memset(ll, 0, sizeof(ll));
    memset(rr, 0, sizeof(rr));
    memset(dp, 0, sizeof(dp));
    memset(crds, 0, sizeof(crds));
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &crds[i].x, &crds[i].y, &crds[i].v);
            crds[i].x++;
            crds[i].y++;
        }
        sort(crds + 1, crds + 1 + n);
        edit(root, 1, MXC, 1, 0);
        int resu = 0;
        for (int lst = 0, i = 1; i <= n; ++i) {
            dp[i] = findmax(root, 1, MXC, 1, crds[i].y - 1) + crds[i].v;
            resu = max(dp[i], resu);
            if (crds[i + 1].x > crds[i].x) {
                for (int j = lst + 1; j <= i; ++j) {
                    // printf("%d %d\n", crds[j].y - 1, dp[j]);
                    edit(root, 1, MXC, crds[j].y, dp[j]);
                }
                lst = i;
            }
        }
        printf("%d\n", resu);
    }
}
/* 
1
10
1 1 3
2 2 4
3 3 5
4 4 6
7 7 8
5 5 9
6 6 10
8 8 11
2 10000 10
100000 100000 10
*/