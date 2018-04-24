/**--------------------
 * adjacency list
 *
 * Time Consumption: linear
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/27
 * --------------------
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define EMXN 10007
#ifdef PLENTYMEMORY
 #define iterate(NODEN, _I) for (edge *(_I) = ehead[NODEN]; _I; _I = (_I)->prev)
struct edge {
    edge *prev;
    int v, w;
    int u;
    edge(): v(0), w(0), u(0), prev(NULL) {}
    edge(int uu, int vv, int ww): u(uu), v(vv), w(ww), prev(NULL) {};
    edge(int vv, int ww): u(0), v(vv), w(ww), prev(NULL) {}
} eglist[EMXN << 1 | 1], *ehead[EMXN | 1], *ecur;

inline void einit() {
    memset(eglist, 0, sizeof(eglist));
    memset(ehead, 0, sizeof(ehead));
    ecur = eglist;
}

inline void addedge(int u, int v, int w) {
    ecur->v = v;
    ecur->w = w;
    ecur->u = u;
    ecur->prev = ehead[u];
    ehead[u] = ecur++;
}
#else
 #define E eglist
 #define iterate(NODEN, _I) for (int _I = ehead[NODEN]; _I != -1; _I = eglist[_I].prev)
struct edge {
    int prev, v, w;
    edge(): prev(-1), v(0), w(0) {}
} eglist[EMXN << 1 | 1];

int ehead[EMXN | 1], ecur;

inline void einit() {
    ecur = 0;
    eglist[0] = edge();
    for (int i = 1; i < (EMXN << 1 | 1); ++i)
        eglist[i] = eglist[i - 1];
    for (int i = 0; i < EMXN; ++i)
        ehead[i] = -1;
}

inline void addedge(int u, int v, int w) {
    E[ecur].v = v;
    E[ecur].w = w;
    E[ecur].prev = ehead[u];
    ehead[u] = ecur++;
}
#endif
