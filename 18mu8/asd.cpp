#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;


namespace Primal_Dual_Vec {
    #define ft first
    #define sd second
    #define mkpr make_pair
    typedef long long LL;
    typedef pair<int, int> PII;
    const int MAXN=5111, MAXM=50011;
    const int INF=0x7f7f7f7f;
    const LL LNF=0x7f7f7f7f7f7f7f7f;

    struct edge {
        int y, c, w;
    } E[MAXM<<1];
    vector<int> G[MAXN];
    PII pre[MAXN];
    int h[MAXN], dis[MAXN], vis[MAXN], cur[MAXN], inque[MAXN];
    int S, T, n, tot=-1, max_flow, min_cost;
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    deque<int> U;

    inline void init(int _s, int _t, int _n) {
        S=_s; T=_t; n=_n;
        for(int i=0;i<=n;++i)
            G[i].clear();
        tot=-1;
    }

    inline void addedge(int x, int y, int c, int w) {
        E[++tot]=(edge){y, c, w};
        G[x].push_back(tot);
        E[++tot]=(edge){x, 0, -w};
        G[y].push_back(tot);
    }

    inline bool SPFA() {
        memset(dis, 0x7f, sizeof dis);
        memset(vis, 0, sizeof vis);
        dis[S]=0; U.push_back(S);
        while(!U.empty()) {
            int now=U.front(); U.pop_front();
            inque[now]=0;
            for(int i=0;i<(int)G[now].size();++i) {
                edge &e=E[G[now][i]];
                int to=e.y;
                if(e.c>0 && dis[to]>dis[now]+h[now]-h[to]+e.w) {
                    dis[to]=dis[now]+h[now]-h[to]+e.w;
                    if(!inque[to]) {
                        inque[to]=1;
                        if(dis[U.empty() ? 0 : U.front()]>dis[to]) {
                            U.push_front(to);
                        } else {
                            U.push_back(to);
                        }
                    }
                }
            }
        }
        return dis[T]!=INF;
    }

    inline bool Dijkstra() {
        memset(dis, 0x7f, sizeof dis);
        // memset(vis, 0, sizeof vis);
        fill(vis, vis+1+n, 0);
        while(!Q.empty()) Q.pop();
        dis[S]=0; Q.push(mkpr(0, S));
        while(!Q.empty()) {
            PII now=Q.top(); Q.pop();
            if(vis[now.sd]) continue;
            vis[now.sd]=1;
            for(int i=0;i<(int)G[now.sd].size();++i) {
                edge &e=E[G[now.sd][i]];
                int to=e.y;
                if(e.c>0 && dis[to]>dis[now.sd]+h[now.sd]-h[to]+e.w) {
                    dis[to]=dis[now.sd]+h[now.sd]-h[to]+e.w;
                    // pre[to]=mkpr(now.sd, i); // is used with Single Way Aug
                    Q.push(mkpr(dis[to], to));
                }
            }
        }
        return dis[T]!=INF;
    }

    inline int DFS(int now, int fl) { // is used with Multi Way Aug
        if(now==T || fl<=0) return max(fl, 0);
        int nowf=0; vis[now]=1;
        for(int &i=cur[now];i<(int)G[now].size();++i) {
            edge &e=E[G[now][i]];
            int to=e.y;
            if(e.c>0 && !vis[to] && dis[to]==dis[now]+h[now]-h[to]+e.w) {
                int nxtf=DFS(to, min(fl, e.c));
                nxtf=min(nxtf, fl);
                if(nxtf) {
                    e.c-=nxtf;
                    E[G[now][i]^1].c+=nxtf;
                    fl-=nxtf;
                    nowf+=nxtf;
                    if(fl<=0) break;
                }
            }
        }
        vis[now]=0;
        return nowf;
    }

    // inline void solve() { // Single Way Aug
    //     max_flow=min_cost=0;
    //     int f=INF;
    //     while(Dijkstra()) {
    //         for(int i=1;i<=n;++i) {
    //             h[i]+=dis[i];
    //         }
    //         int newf=f;
    //         for(int i=T;i!=S;i=pre[i].ft) {
    //             newf=min(newf, E[pre[i].sd].c);
    //         }
    //         f-=newf;
    //         max_flow+=newf;
    //         min_cost+=newf*h[T];
    //         for(int i=T;i!=S;i=pre[i].ft) {
    //             E[pre[i].sd].c-=newf;
    //             E[pre[i].sd^1].c+=newf;
    //         }
    //         if(f<=0) break;
    //     }
    // }

    inline void solve2() { // Multi Way Aug
        max_flow=min_cost=0;
        int f=INF;
        // if(!SPFA()) return;
        while(Dijkstra()) {
            fill(cur+1, cur+1+n, 0);
            fill(vis+1, vis+1+n, 0);
            int newf=DFS(S, INF);
            f-=newf;
            for(int i=1;i<=n;++i) {
                h[i]+=dis[i];
            }
            max_flow+=newf;
            min_cost+=newf*h[T];
            if(f<=0) break;
        }
    }
}

int n, m, s, t;

int main() {
    scanf("%d%d", &n, &m);
    // scanf("%d%d", &s, &t);
    s=1; t=n;
    Primal_Dual_Vec::init(s, t, n);
    for(int i=1, u, v, x, y;i<=m;++i) {
        scanf("%d%d%d%d", &u, &v, &x, &y);
        Primal_Dual_Vec::addedge(u, v, x, y);
    }
    Primal_Dual_Vec::solve2();
    printf("%d %d\n", Primal_Dual_Vec::max_flow, Primal_Dual_Vec::min_cost);
    return 0;
}