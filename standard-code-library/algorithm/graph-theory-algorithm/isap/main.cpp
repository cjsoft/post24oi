#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstring>
#include <climits>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MXFN 207

typedef int TPMXF;

int cur(1), m, n; // m the total count of arcs, n the total count of vertices
int DIS[MXFN], GAP[MXFN];
struct edge {
    edge *prev;
    int to, w;
    edge() {
        prev = NULL;
        to = w = 0;
    }
} egs[407];
edge *head[207];    

void mxfinit() {
    cur = 1;
    memset(head, 0, sizeof(head));
    memset(egs, 0, sizeof(egs));
    memset(DIS, 0, sizeof(DIS));
    memset(GAP, 0, sizeof(GAP));
}
void add_edge(int from, int to, int weight) {
    egs[cur].prev = head[from];
    egs[cur].to = to;
    egs[cur].w = weight;
    head[from] = egs + cur++;
}
TPMXF dfs(int root, TPMXF current_flow) {
    if (root == n) return current_flow;
    TPMXF other_flow = 0;
    int min_dis = m - 1;
    for (edge *i = head[root]; i; i = i->prev) {
        if (i->w) {
            if (DIS[root] == DIS[i->to] + 1) {
                TPMXF temp = dfs(i->to, std::min(current_flow - other_flow, i->w));
                i->w -= temp;
                (egs + ((i - egs) ^ 1))->w += temp;
                other_flow += temp;
                if (DIS[1] >= m) return other_flow;
                if (current_flow == other_flow) break;
            }
            min_dis = std::min(min_dis, DIS[i->to]);
        }
    }
    if (!other_flow) {
        --GAP[DIS[root]];
        if (!GAP[DIS[root]]) DIS[1] = m;
        DIS[root] = min_dis + 1;
        ++GAP[DIS[root]];
    }
    return other_flow;
}
TPMXF max_flow() {
    TPMXF resu(0);
    GAP[0] = m;
    while(DIS[1] < m) resu += dfs(1, INF);
    return resu;
}
int main() {
    scanf("%d %d", &m, &n);
    int s, e, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &s, &e, &c);
        add_edge(s, e, c);
        add_edge(e, s, 0);
    }
    printf("%d\n", max_flow());
    return 0;
}
