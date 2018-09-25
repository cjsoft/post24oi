#include<bits/stdc++.h>
using namespace std;

#define FOR(a,b,c) for(int a=(b),a##_end__=(c);a<a##_end__;a++)
#define INF 0x3f3f3f3f
void Rd(int &res){
	char c;res=0;
	while(c=getchar(),c<48);
	do res=(res<<3)+(res<<1)+(c^48);
	while(c=getchar(),c>47);   
}
template<class T>inline bool chkmin(T&a,T const&b){return a>b?a=b,1:0;}
template<class T>inline bool chkmax(T&a,T const&b){return a<b?a=b,1:0;}
const int M=100005;
const int N=30005;
namespace ZKW{
    struct edge{
        int from,to,cap,cost;
    }w[N];
    vector<int> E[M];
    bool vis[M];
    int mcnt,cost,flow,price;
    void add_edge(int u,int v,int cap,int cost){
        w[mcnt]=(edge){u,v,cap,cost};
        E[u].push_back(mcnt++);
        w[mcnt]=(edge){v,u,0,-cost};
        E[v].push_back(mcnt++);
    }
    int aug(int u,int a,int T){
        if(u==T) return cost+=a*price,a;
        vis[u]=1;
        int f=a;
        FOR(i,0,(int)E[u].size()){
            edge e=w[E[u][i]];
            if(!e.cost && e.cap && !vis[e.to]){
                int d=aug(e.to,min(f,e.cap),T);
                w[E[u][i]].cap-=d;
                w[E[u][i]^1].cap+=d;
                if(!(f-=d)) return a;
            }
        }
        return a-f;
    }
    pair<int,int> calc(int S,int T){
        flow=cost=price=0;
        for(;;){
            for(;;){
                memset(vis,0,sizeof(vis));
                int f=aug(S,INF,T);
                if(!f) break;
                flow+=f;
            }
            int d=INF;
            FOR(u,0,M) if(vis[u]) FOR(i,0,(int)E[u].size()){
                edge e=w[E[u][i]];
                if(e.cap && !vis[e.to]) chkmin(d,e.cost);
            }
            if(d==INF) return make_pair(flow,cost);
            FOR(u,0,M) if(vis[u]) FOR(i,0,(int)E[u].size())
                w[E[u][i]].cost-=d,w[E[u][i]^1].cost+=d;
            price+=d;
        }
    }
}
int n,m;
int main(){
	Rd(n);Rd(m);
	FOR(i,0,m){
		int u,v,cap,cost;
		Rd(u),Rd(v),Rd(cap),Rd(cost);
		ZKW::add_edge(u,v,cap,cost);
	}
	pair<int,int> ans=ZKW::calc(1,n);
	printf("%d %d\n",ans.first,ans.second);
	return 0; 
}