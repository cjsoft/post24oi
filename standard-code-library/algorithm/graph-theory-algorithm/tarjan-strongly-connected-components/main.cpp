/**--------------------
 * Tarjan Strongly Connected Components Algorithm
 *
 * Time Consumption: linear
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/31
 * --------------------
 */

#include <cstring>
#include <iostream>

#define SCCMXN 10007

char INSTK[SCCMXN];
int SCCSTK[SCCMXN];
int SCCTOP;
int DFN[SCCMXN], LOW[SCCMXN];
int DEP;

void SCCINIT() {
    DEP = 0;
    SCCTOP = 0;
    memset(INSTK, 0, sizeof(INSTK));
    memset(SCCSTK, 0, sizeof(SCCSTK));
    memset(DFN, 0, sizeof(DFN));
    memset(LOW, 0, sizeof(LOW));
}
inline void SCCSTKPUSH(int x) {
    INSTK[x] = 1;
    SCCSTK[SCCTOP++] = x;
}
inline int SCCSTKPOP() {
    if (SCCTOP > 0) {
        INSTK[SCCSTK[SCCTOP - 1]] = 2;
        return SCCSTK[--SCCTOP];
    }
    else return -1;
}
inline int SCCSTKBACK() {
    if (SCCTOP > 0) return SCCSTK[SCCTOP - 1];
    else return -1;
}
#ifdef PLENTYMEMORY
 #define V(i) ((*(i))->v)
#else
 #define V(i) E[i].v
#endif
void TARJANDFS(int root) {
    DFN[root] = LOW[root] = ++DEP;
    SCCSTKPUSH(root);
    iterate(root, i) {
        if (!INSTK[V(i)]) {
            TARJANDFS(V(i));
            LOW[root] = std::min(LOW[root], LOW[V(i)]);
        } else if (INSTK[V(i)] == 1)
            LOW[root] = std::min(LOW[root], DFN[V(i)]);
    }
    if (LOW[root] == DFN[root]) {
        int VERTICEINSCC;
        while (SCCSTKBACK() != root) {
            VERTICEINSCC = SCCSTKPOP();
            // DO SOMETHING HERE
        }
        VERTICEINSCC = SCCSTKPOP();
        // DO SOMETHING HERE
    }
}

void SCC(int n) { 
    SCCINIT();
    for (int i = 1; i <= n; ++i)
        if (!INSTK[i])
            TARJANDFS(i);
}

