/**--------------------
 * SPFA Single-Source Shortest Path Algorithm
 *
 * Time Consumption: V \times E (worst)
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/28
 * --------------------
 */
#include <queue>
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

queue<int> _Q;
char _INQ[VMXN];
int dis[VMXN];
void spfa(int s) {
    memset(_INQ, 0, sizeof(_INQ));
    memset(dis, 0x3f, sizeof(dis));
    while (!_Q.empty()) _Q.pop();
    dis[s] = 0;
    _Q.push(s);
    _INQ[s] = 1;
    int u;
    while (!_Q.empty()) {
        u = _Q.front();
        iterate(u, i) {
            if (dis[u] + E[i].w < dis[E[i].v]) {
                dis[E[i].v] = dis[u] + E[i].w;
                if (!_INQ[E[i].v]) {
                    _Q.push(E[i].v);
                    _INQ[E[i].v] = 1;
                }
            }
        }
        _Q.pop();
        _INQ[u] = 0;
    }
}

