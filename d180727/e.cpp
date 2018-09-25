#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int N=100010;
const int inf=2000000007;
struct node
{
    int ch[2],size,fa;
    bool rev;
}tr[N];
struct data
{
    int id,h,num;
}a[N];
bool cmp(const data &A,const data &B)
{
    return (A.h!=B.h)?A.h<B.h:A.id<B.id;
};
bool cmp_id(const data &A,const data &B)
{
    return A.id<B.id;
}
int n,root,ans[N],cnt=0;
void update(int nd)
{
    int ls=tr[nd].ch[0]; int rs=tr[nd].ch[1];
    tr[nd].size=1;
    if(ls) tr[nd].size+=tr[ls].size;
    if(rs) tr[nd].size+=tr[rs].size;
}
void build(int fa,int &nd,int lf,int rg)
{
    int mid=(lf+rg)>>1; nd=a[mid].num;
    tr[nd].size=1; tr[nd].rev=0; tr[nd].fa=fa;
    if(lf==rg) return;
    if(lf<mid) build(nd,tr[nd].ch[0],lf,mid-1);
    if(rg>mid) build(nd,tr[nd].ch[1],mid+1,rg);
    update(nd);
}
void pushdown(int x)
{
    if(tr[x].rev)
    {
        swap(tr[x].ch[0],tr[x].ch[1]);
        if(tr[x].ch[0]) tr[tr[x].ch[0]].rev^=1;
        if(tr[x].ch[1]) tr[tr[x].ch[1]].rev^=1;
        tr[x].rev^=1;
    }
}
void push(int x)
{
    if(x!=root) push(tr[x].fa);
    pushdown(x);
}
void rotate(int x,int &top)
{
    int y=tr[x].fa; int z=tr[y].fa;
    if(y==top) top=x;
    else 
    {
        if(tr[z].ch[0]==y) tr[z].ch[0]=x;
        else tr[z].ch[1]=x;
    }
    tr[x].fa=z;
    int l= tr[y].ch[0]==x? 0:1; int r=l^1;
    tr[y].ch[l]=tr[x].ch[r]; tr[tr[x].ch[r]].fa=y;
    tr[x].ch[r]=y; tr[y].fa=x;
    update(y); update(x);
}
void splay(int x,int &top)
{
    push(x);
    while(x!=top)
    {
        int y=tr[x].fa; int z=tr[y].fa;
        if(y!=top)
        {
            if((tr[z].ch[0]==y)^(tr[y].ch[0]==x))
            rotate(x,top);
            else rotate(y,top);
        }
        rotate(x,top);
    }
}
int query(int x)
{
    splay(x,root);
    int ret=tr[tr[x].ch[0]].size;
    return ret;
}
int findnxt(int x)
{
    pushdown(x); int tmp=tr[x].ch[1]; pushdown(tmp);
    while(tr[tmp].ch[0])
    {
        tmp=tr[tmp].ch[0];
        pushdown(tmp);
    }
    return tmp;
}
void modify(int x)
{
    int pre=x-1; int nxt=findnxt(x);
    splay(pre,root); splay(nxt,tr[root].ch[1]);
    tr[tr[nxt].ch[0]].rev=1;
}
int main()
{
    scanf("%d",&n);n+=2;
    for(int i=2;i<n;i++) scanf("%d",&a[i].h);
    a[0].h=-inf; a[n].h=inf;
    for(int i=1;i<=n;i++) a[i].id=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) a[i].num=i;
    sort(a+1,a+n+1,cmp_id);
    build(0,root,1,n);
    for(int i=2;i<n;i++)
    {
        ans[++cnt]=query(i);
        modify(i);
    }
    for(int i=1;i<=cnt;i++)
    printf("%d\n",ans[i]);
    return 0;
}

