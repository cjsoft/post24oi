#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pa;

const int N=4000005;
const int INF=0x3f3f3f3f;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int n,m,cnt,S,T;
char str[2005][2005];
int head[N],dis[N];
int Next[N<<2],List[N<<2],key[N<<2];
bool vis[N];

inline int read()
{
    int a=0,f=1; char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
    while (c>='0'&&c<='9') {a=a*10+c-'0'; c=getchar();}
    return a*f;
}

inline void insert(int x,int y,int z)
{
    Next[++cnt]=head[x];
    head[x]=cnt;
    List[cnt]=y;
    key[cnt]=z;
}

inline int id(int x,int y)
{
    return (x-1)*m+y;
}

inline bool judge(int x,int y)
{
    if (x<1||x>n||y<1||y>m||str[x][y]=='#') return false;
    return true;
}
/*
inline int dijkstra(int S,int T)
{
    priority_queue<pa,vector<pa>,greater<pa> > q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    q.push(make_pair(0,S));
    dis[S]=0;
    while (!q.empty())
    {
        int x=q.top().second; q.pop();
        if (vis[x]) continue; vis[x]=true;
        for (int i=head[x];i;i=Next[i])
            if (dis[List[i]]>dis[x]+key[i])
            {
                dis[List[i]]=dis[x]+key[i];
                q.push(make_pair(dis[List[i]],List[i]));
            }
    }
    return dis[T]==INF?-1:dis[T];
}*/

inline int spfa(int S,int T)
{
    queue<int> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    vis[S]=true; dis[S]=0; q.push(S);
    while (!q.empty())
    {
        int x=q.front(); q.pop();
        for (int i=head[x];i;i=Next[i])
            if (dis[List[i]]>dis[x]+key[i])
            {
                dis[List[i]]=dis[x]+key[i];
                if (!vis[List[i]])
                {
                    vis[List[i]]=true;
                    q.push(List[i]);
                }
            }
        vis[x]=false;
    }
    return dis[T]==INF?-1:dis[T];
}

int main()
{
    n=read(); m=read();
    while (n||m)
    {
        cnt=0;
        memset(head,0,sizeof(head));
        for (int i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (str[i][j]=='#') continue;
                if (str[i][j]=='.'||str[i][j]=='S')
                    for (int k=0;k<4;k++)
                    {
                        int nx=i+dx[k],ny=j+dy[k];
                        if (judge(nx,ny))
                            insert(id(i,j),id(nx,ny),1);
                    }
                if (str[i][j]=='S') S=id(i,j);
                if (str[i][j]=='T') T=id(i,j);
            }
        for (int i=1;i<=n;i++)
        {
            int now=-1;
            for (int j=1;j<=m;j++)
            {
                if (str[i][j]=='L')
                {
                    if (now==-1) continue;
                    insert(id(i,j),id(i,now),0);
                }
                if (str[i][j]=='#') now=j+1;
                else if (str[i][j]!='.'&&str[i][j]!='S') now=j;
            }
            now=-1;
            for (int j=m;j;j--)
            {
                if (str[i][j]=='R')
                {
                    if (now==-1) continue;
                    insert(id(i,j),id(i,now),0);
                }
                if (str[i][j]=='#') now=j-1;
                else if (str[i][j]!='.'&&str[i][j]!='S') now=j;
            }
        }
        for (int i=1;i<=m;i++)
        {
            int now=-1;
            for (int j=1;j<=n;j++)
            {
                if (str[j][i]=='U')
                {
                    if (now==-1) continue;
                    insert(id(j,i),id(now,i),0);
                }
                if (str[j][i]=='#') now=j+1;
                else if (str[j][i]!='.'&&str[j][i]!='S') now=j;
            }
            now=-1;
            for (int j=n;j;j--)
            {
                if (str[j][i]=='D')
                {
                    if (now==-1) continue;
                    insert(id(j,i),id(now,i),0);
                }
                if (str[j][i]=='#') now=j-1;
                else if (str[j][i]!='.'&&str[j][i]!='S') now=j;
            }
        }
        cout<<spfa(S,T)<<endl;
        n=read(); m=read();
    }
    return 0;
}