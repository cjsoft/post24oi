#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 200007
using namespace std;
 
int nxt[maxn][26],pre[maxn],step[maxn],dp[maxn],g[maxn],Q[maxn],cnt[maxn];
int N,last,p,q,np,nq;
char s[maxn];
 
void insert(int x,int m)
{
    p=last,np=++N,step[np]=m,last=np,g[np]++;
    while (p!=-1 && nxt[p][x]==0)
        nxt[p][x]=np,p=pre[p];
    if (p==-1) return ;
    q=nxt[p][x];
    if (step[q]==step[p]+1)
        { pre[np]=q; return; }
    nq=++N,step[nq]=step[p]+1,pre[nq]=pre[q];
    for (int i=0; i<26; i++)
        nxt[nq][i]=nxt[q][i];
        pre[np]=pre[q]=nq;
    while (p!=-1 && nxt[p][x]==q)
        nxt[p][x]=nq,p=pre[p];
}
 
int main()
{
    int T;
    scanf("%d", &T);
    for (int oi = 0; oi < T; ++oi) {
        memset(nxt, 0, sizeof(nxt));
        memset(pre, 0, sizeof(pre));
        memset(step, 0, sizeof(step));
        memset(dp, 0, sizeof(dp));
        memset(g, 0, sizeof(g));
        memset(Q, 0, sizeof(Q));
        memset(cnt, 0, sizeof(cnt));
        memset(s, 0, sizeof(s));
        N = last = p = q = np = nq = 0;
        pre[0]=-1;
        int k = 0;
        scanf("%d", &k);
        scanf("%s",s);
        for (int i=0; s[i]; i++) insert(s[i]-'a',i+1);
        for (int i=1; i<=N; i++) cnt[step[i]]++;
        for (int i=1; i<=N; i++) cnt[i]+=cnt[i-1];
        for (int i=1; i<=N; i++) Q[cnt[step[i]]--]=i;
        for (int i=N; i>=1; i--) g[pre[Q[i]]]+=g[Q[i]];
        int fresu = 0;
        for (int i=N; i>=1; i--) if (g[Q[i]] == k) fresu += k;
        printf("%d\n",fresu);

    }
    return 0;
}