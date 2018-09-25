#include<stdio.h>
#include<algorithm>
using namespace std;
#define uint unsigned int
uint n, cnt, root[200005], tre[6400005], lt[6400005], rt[6400005], lazy[6400005];
void Update2(uint &now, uint l, uint r, uint L, uint R)
{
	uint m;
	if(now==0)
		now = ++cnt;
	if(l>=L && r<=R)
	{
		lazy[now]++;
		tre[now] += r-l+1;
		return;
	}
	m = (l+r)/2;
	if(L<=m)
		Update2(lt[now], l, m, L, R);
	if(R>=m+1)
		Update2(rt[now], m+1, r, L, R);
	tre[now] = tre[lt[now]]+tre[rt[now]]+lazy[now]*(r-l+1);
}
void Update1(uint l, uint r, uint x, uint L, uint R, uint k)
{
	uint m;
	Update2(root[x], 1, n, L, R);
	if(l==r)
		return;
	m = (l+r)/2;
	if(k<=m)
		Update1(l, m, x*2, L, R, k);
	else
		Update1(m+1, r, x*2+1, L, R, k);
}
uint Query2(uint now, uint l, uint r, uint L, uint R)
{
	uint m, sum;
	sum = 0;
	if(now==0)
		return 0;
	if(l>=L && r<=R)
		return tre[now];
	m = (l+r)/2;
	if(L<=m)
		sum += Query2(lt[now], l, m, L, R);
	if(R>=m+1)
		sum += Query2(rt[now], m+1, r, L, R);
	return sum+lazy[now]*(min(R, r)-max(L, l)+1);
}
uint Query1(uint l, uint r, uint x, uint L, uint R, uint k)
{
	uint m, sum;
	if(l==r)
		return l;
	m = (l+r)/2;
	sum = Query2(root[x*2], 1, n, L, R);
	if(sum>=k)
		return Query1(l, m, x*2, L, R, k);
	else
		return Query1(m+1, r, x*2+1, L, R, k-sum);
}
int main(void)
{
	uint m, opt, L, R, k;
	scanf("%d%d", &n, &m);
	n += 1;
	while(m--)
	{
		scanf("%d%d%d%d", &opt, &L, &R, &k);
		if(opt==1)
		{
			k = n-k;
			Update1(1, n, 1, L, R, k);
		}
		else
			printf("%d\n", n-Query1(1, n, 1, L, R, k));
	}
	return 0;
}
