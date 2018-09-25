#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 1000007
using namespace std;

int t = 0, l = 1, r = 1, ans = 1;
struct query {
    int bnl, bnr, l, r, t, id;
    bool operator<(const query &b) const {
        if (bnl == b.bnl) {
            if (bnr == b.bnr) {
                return t < b.t;
            } else return bnr < b.bnr;
        } else return bnl < b.bnl;
    }
} qs[N];
struct edit {
    int pos, oc, nc;
} ets[N];
int clr[N], tmp[N], rtmp[N];
int n, m;
int blksz;
char inpt[8];
void sel(int co, int d) {
    clr[co] += d;
    if (d > 0) ans += (clr[co] == 1);
    if (d < 0) ans -= (clr[co] == 0);
}
void performedit(int id, bool isrev) {
    if (ets[id].pos >= l && ets[id].pos <= r) {
        if (isrev) {
            sel(tmp[ets[id].pos], -1);
            sel(ets[id].oc, 1);
        } else {
            sel(tmp[ets[id].pos], -1);
            sel(ets[id].nc, 1);
        }

    }
    tmp[ets[id].pos] = isrev ? ets[id].oc : ets[id].nc;
}
int ANS[N];
int main() {
    scanf("%d %d", &n, &m);
    blksz = pow(1. * n, 2. / 3);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        rtmp[i] = tmp[i] = x;
    }
    clr[tmp[1]]++;
    int tot1 = 0, tot2 = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%s %d %d", inpt, &x, &y);
        if (inpt[0] == 'Q') {
            qs[tot1].id = tot1;
            qs[tot1].t = tot2;
            qs[tot1].l = x;
            qs[tot1].r = y;
            qs[tot1].bnl = x / blksz + 1;
            qs[tot1++].bnr = y / blksz + 1;
        } else {
            ets[++tot2].pos = x;
            ets[tot2].oc = rtmp[x];
            ets[tot2].nc = y;
            rtmp[x] = y;
        }
    }
    sort(qs, qs + tot1);
    for (int i = 0; i < tot1; ++i) {
        while (t < qs[i].t) performedit(t + 1, false), ++t;
        while (t > qs[i].t) performedit(t, true), --t;
        while (l < qs[i].l) sel(tmp[l++], -1);
        while (l > qs[i].l) sel(tmp[--l], 1);
        while (r < qs[i].r) sel(tmp[++r], 1);
        while (r > qs[i].r) sel(tmp[r--], -1);
        ANS[qs[i].id] = ans;
    }
    for (int i = 0; i < tot1; ++i)
        printf("%d\n", ANS[i]);
}

