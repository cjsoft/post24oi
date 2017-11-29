#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define N 200005
using namespace std;
char s[N];
int S,cnt,last;
int a[N],b[N],f[N],t[N],fa[N],l[N],r[N],ch[N][26];
void add(int x)
{
	int c=a[x];
	int p=last,np=++cnt;last=np;
	l[np]=x;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p)fa[np]=S;
	else 
	{
		int q=ch[p][c];
		if(l[p]+1==l[q])fa[np]=q;
		else 
		{
			int nq=++cnt;l[nq]=l[p]+1;
			memcpy(ch[nq],ch[q],sizeof ch[q]);
			fa[nq]=fa[q];
			fa[np]=fa[q]=nq;
			for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
		}
	}
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int k;
        scanf("%d", &k);
        memset(s, 0, sizeof(s));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(f, 0, sizeof(f));
        memset(t, 0, sizeof(t));
        memset(fa, 0, sizeof(fa));
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(ch, 0, sizeof(ch));
        S = cnt = last = 0;
        scanf("%s",s+1);
        last=S=++cnt;
        int len=strlen(s+1);
        for(int i=1;i<=len;i++)a[i]=s[i]-'a';
        for(int i=1;i<=len;i++)add(i);
        for(int i=1,p=S;i<=len;i++)
        {
            p=ch[p][a[i]];r[p]++;
        }
        for(int i=1;i<=cnt;i++)b[l[i]]++;
        for(int i=1;i<=len;i++)b[i]+=b[i-1];
        for(int i=1;i<=cnt;i++)t[b[l[i]]--]=i;
        for(int i=cnt;i;i--)r[fa[t[i]]]+=r[t[i]];
        int fresu = 0;
        for(int i=1;i<=cnt;i++) if (r[i] == k) fresu += k;
        printf("%d\n", fresu);
    }
	// scanf("%s",s+1);
	// last=S=++cnt;
	// int len=strlen(s+1);
	// for(int i=1;i<=len;i++)a[i]=s[i]-'a';
	// for(int i=1;i<=len;i++)add(i);
	// for(int i=1,p=S;i<=len;i++)
	// {
	// 	p=ch[p][a[i]];r[p]++;
	// }
	// for(int i=1;i<=cnt;i++)b[l[i]]++;
	// for(int i=1;i<=len;i++)b[i]+=b[i-1];
	// for(int i=1;i<=cnt;i++)t[b[l[i]]--]=i;
	// for(int i=cnt;i;i--)r[fa[t[i]]]+=r[t[i]];
	// for(int i=1;i<=cnt;i++)printf("%d %d\n",r[i], l[i]);
	return 0;
}
