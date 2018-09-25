#include <bits/stdc++.h>
#define N 100007
#define M 200007

using namespace std;

int n, m, a, b, c;
struct edge {
    edge *prev;
    int v, w;
} buffer[(6 * M) | 7], *head[(2 * N + M) | 7], *cur;

int dis[(2 * N + M) | 7];
int vis[(2 * N + M) | 7];
edge *fd[1000007];
int ver[1000007];
inline void addedge(int a, int b, int w) {
    cout << "   " <<  a - n << ' ' << b - n<< ' ' << w << endl;
    cur->v = b;
    cur->prev = head[a];
    cur->w = w;
    head[a] = cur++;
}

void init() {
    cur = buffer;
    memset(head, 0, sizeof(head));
    memset(ver, 0, sizeof(ver));
}
void dijkstra(int S, int T) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, S));
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[S] = 0;
    while (!q.empty()) {
        int x = q.top().second; q.pop();
        if (vis[x]) continue; vis[x] = true;
        for (edge *i = head[x]; i; i = i->prev) {
            if (dis[i->v] > dis[x] + i->w) {
                dis[i->v] = dis[x] + i->w;
                q.push(make_pair(dis[i->v], i->v));
            }
        }
    }
}
int tot;
int tim[1000007], pi[1000007];
int main() {
    while (~scanf("%d %d", &n, &m)) {
        init();
        for (int i = 1; i <= m; ++i) {
           scanf("%d %d %d", &a, &b, &c);
           addedge(a, b, c);
        }
        tot = 2 * n ;
        for (int i = 1; i <= n; ++i) {
            for (edge *j = head[i]; j; j = j->prev) {
                if (tim[j->w] != i) {
                    tot++;
                    addedge(i + n, tot, 1);
                    addedge(tot, i + n, 1);
                    addedge(j->v + n, tot, 1);
                    addedge(tot, j->v + n, 1);
                }
            }
        }
        dijkstra(1 + n, 2 * n);
        if (dis[2 * n] == 0x3f3f3f3f) {
            puts("-1");
        } else {
            printf("%d\n", dis[n * 2] / 2);
        }
    }
    return 0;
}
