#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define EMXN 10007
#define VMXN 107
#define E eglist
#define iterate(NODEN, _I) for (int _I = ehead[NODEN]; _I != -1; _I = eglist[_I].prev)
struct edge {
    int prev, v, w;
    edge(): prev(-1), v(0), w(0) {}
} eglist[EMXN];

int ehead[VMXN], ecur;

inline void einit() {
    ecur = 0;
    eglist[0] = edge();
    for (int i = 1; i < EMXN; ++i)
        eglist[i] = eglist[i - 1];
    for (int i = 0; i < VMXN; ++i)
        ehead[i] = -1;
}

inline void addedge(int u, int v, int w) {
    E[ecur].v = v;
    E[ecur].w = w;
    E[ecur].prev = ehead[u];
    ehead[u] = ecur++;
}

struct PII {
    int v, dis;
    PII(): v(0), dis(0) {}
    PII(int v, int dis): v(v), dis(dis) {}
    bool operator<(const PII &b) const {
        if (dis == b.dis) return v < b.v;
        return dis > b.dis;
    }
};

priority_queue<PII> npq;
int dis[VMXN];
void dijkstra(int s) {
    while (!npq.empty()) npq.pop();
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    npq.push(PII(s, 0));
    PII tmp;
    while (!npq.empty()) {
        tmp = npq.top(), npq.pop();
        if (tmp.dis > dis[tmp.v]) continue;
        iterate(tmp.v, i) {
            if (dis[E[i].v] > dis[tmp.v] + E[i].w) {
                dis[E[i].v] = dis[tmp.v] + E[i].w;
                npq.push(PII(E[i].v, dis[E[i].v]));
            }
        }
    }
}
