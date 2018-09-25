#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n;
#define MAXN 400010
int a[MAXN],f[MAXN],g[MAXN];
struct node
{
	int tr[2];
}t[MAXN * 40];
int ptr = 0;
int newnode(){return ++ptr;}
int root = 0;
void insert(int k)
{
	int cur = root;
	for(int i = 30;i >= 0;--i)
	{
		if(t[cur].tr[((k >> i) & 1)] == 0)t[cur].tr[((k >> i) & 1)] = newnode();
		cur = t[cur].tr[((k >> i) & 1)];
	}
	return;
}
int query(int k)
{
	int cur = root;
	int res = 0;
	for(int i = 30;i >= 0;--i)
	{
		if(t[cur].tr[!((k >> i) & 1)] != 0)
		{
			cur = t[cur].tr[!((k >> i) & 1)];
			res += (1 << i);
		}
		else cur = t[cur].tr[((k >> i) & 1)];
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)scanf("%d",&a[i]);
	int presum = 0;
	insert(0);
	for(int i = 1;i <= n;++i)
	{
		presum = presum ^ a[i];
		f[i] = max(f[i - 1],query(presum));
		insert(presum);
	}
	memset(t,0,sizeof(t));ptr = 0;
	int sufsum = 0;
	insert(0);
	for(int i = n;i >= 1;--i)
	{
		sufsum = sufsum ^ a[i];
		g[i] = max(g[i + 1],query(sufsum));
		insert(sufsum);
	}
	long long ans = 0;
	for(int i = 1;i < n;++i)
	{
		ans = max(ans,(long long)f[i] + (long long)g[i + 1]);
	}
    for (int i = 1; i <= n; ++i)
        cout << f[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; ++i)
        cout << g[i] << ' ';
    cout << endl;
	cout << ans << endl;
    puts("B");
	return 0;
} 
