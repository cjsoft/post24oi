#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define MXN 107
#define MXM 10007
using namespace std;
int n, xpps[MXN], ypps[MXN];
int m;
struct edge {
    int u, v;
    double w;
    edge *prev;
    bool operator<(const edge &b) const {
        if (w == b.w) {
            if (u == b.u) return v < b.v;
            return u < b.u;
        }
        return w < b.w;
    }
};
edge *hd[MXN], egs[MXM << 1], *cur;
inline void addedge(int a, int b, double w) {
    cur->u = a;
    cur->v = b;
    cur->w = w;
    cur->prev = hd[a];
    hd[a] = cur++;
}
struct pos {
    int no;
    double dis;
    pos() {
        no = 0;
        dis = 0;
    }
    pos(int _a, double _b) {
        no = _a; dis = _b;
    }
    bool operator<(const pos &b) const {
        if (dis == b.dis) return no < b.no;
        return dis > b.dis;
    }
};
priority_queue<pos> sta;
double dis[MXN];
bool tag[MXN];
void dij(int s) {
    for (int i = 0; i < MXN; ++i) {
        if (i == s) dis[i] = 0, tag[i] = true;
        else dis[i] = 5e10, tag[i] = false;
    }
    int cnter = 0;
    sta.push(pos(s, 0));
    while (!sta.empty()) {
        pos tmp = sta.top();
        sta.pop();
        ++cnter;
        tag[tmp.no] = true;
        for (edge *i = hd[tmp.no]; i; i = i->prev) {
            if (!tag[i->v] && dis[i->v] > dis[tmp.no] + i->w) {
                dis[i->v] = dis[tmp.no] + i->w;
                sta.push(pos(i->v, dis[i->v]));
            }
        }
    }
}

int main() {
    cur = egs;
    int ta, tb;
    double tw;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", xpps + i, ypps + i);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &ta, &tb);
        tw = sqrt((xpps[ta] - xpps[tb]) * (xpps[ta] - xpps[tb]) + (ypps[ta] - ypps[tb]) * (ypps[ta] - ypps[tb]));
        addedge(ta, tb, tw);
        addedge(tb, ta, tw);
    }
    scanf("%d %d", &ta, &tb);
    dij(ta);
    printf("%.2lf\n", dis[tb]);
    return 0;
}