#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MXN 10007
#define MXM 100007
using namespace std;
typedef long long ll;

inline int readint() {
    static int x, f;
    static char ch;
    x = 0, f = 1;
    ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
class edge {
public:
    int u, v, w;
    edge *prev;
};

edge *hds[MXN], egs[MXM];
edge *revhds[MXN], revegs[MXM];
int rudu[MXN];
int seq[MXN];
int cur = 0;
int revcur = 0;
int n, m, T;
queue<int> q;
inline void addedge(int u, int v, int w) {
    egs[cur].u = u;
    egs[cur].v = v;
    egs[cur].w = w;
    egs[cur].prev = hds[u];
    hds[u] = egs + cur++; 
    rudu[v]++;
    revegs[revcur].u = v;
    revegs[revcur].v = u;
    revegs[revcur].w = w;
    revegs[revcur].prev = revhds[v];
    revhds[v] = revegs + revcur++;
}
void topo() {
    int cc = 1;
    for (int i = 1; i <= n; ++i) {
        if (rudu[i] < 1) q.push(i); 
    }
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        seq[cc++] = tmp;
        for (edge *i = hds[tmp]; i; i = i->prev) {
            rudu[i->v]--;
            if (rudu[i->v] < 1) {
                q.push(i->v);
            }
        }
    }
}
int fresult;
// void dfs(int root, int dep) {
//     fresult = max(fresult, dep);
//     for (edge *i = revhds[root]; i; i = i->prev) {
//         dfs(i->v, dep + i->w);
//     }
// }
int s, t, l;
int dp[MXN];
int main() {
    T = readint();
    while (T--) {
        while (!q.empty()) q.pop();
        memset(hds, 0, sizeof(hds));
        memset(egs, 0, sizeof(egs));
        memset(revhds, 0, sizeof(revhds));
        memset(revegs, 0, sizeof(revegs));
        memset(rudu, 0, sizeof(rudu));
        memset(seq, 0, sizeof(seq));
        memset(dp, 0, sizeof(dp));
        cur = revcur = 0;
        fresult = 0;
        n = readint(); m = readint();
        for (int i = 0; i < m; ++i) {
            s = readint();
            t = readint();
            l = readint();
            addedge(s, t, l);
        }
        topo();
        for (int i = n; i > 0; --i) {
            for (edge *j = hds[n]; j; j = j ->prev) {
                dp[i] = max(dp[i], dp[j->v] + j->w);
            }
        }
        printf("%d\n", fresult);
    }
    return 0;
}