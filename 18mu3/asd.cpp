#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 10000005;

int n, m, k, p, q, r, mod;
long long a[N];

inline int read() {
    int a = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = a * 10 + c - '0';
        c = getchar();
    }
    return a * f;
}

int que[N*2],stk[N],nxt[N];
int vis[N];

int main() {
    int testcase = read();
    int vi = 0;
    while (testcase--) {
        vi++;
        n = read(); m = read(); k = read(); p = read(); q = read(); r = read(); mod = read();
        for (int i = 1; i <= k; i++)
            a[i] = read();
        for (int i = k + 1; i <= n; i++) 
            a[i] = (p * a[i - 1] + q * i + r) % mod;
        stack<int> s;
        for (int i = 1; i <= n; i++) {
            while (!s.empty() && a[s.top()] < a[i]) {
                nxt[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int l = n, r = n-1; que[r] = -1;
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            if(a[i] > que[r]) {
                que[++r] = a[i];
                cnt++;
                vis[i] = vi;
            }
        }
        long long A = 0, B = 0;
        int tn = n-m+1;
        for(int i = 1; i <= tn; i++) {
            int t = i+m-1;
            if(a[t] > que[r]) {
                que[++r] = a[t];
                cnt++;
                vis[t] = vi;
            }
            if(vis[i-1] == vi) {
                l++;
                cnt--;
            }
            int top = 0;
            for(int j = i; vis[j] != vi; j = nxt[j]) {
                stk[++top] = j;
            }
            for(int j = top; j > 0; j--) {
                que[--l] = a[stk[j]];
                cnt++;
                vis[stk[j]] = vi;
            }
            A += que[r] ^ i;
            B += cnt ^ i;
        //    cout << que[r] << " " << cnt << " top: " << top << endl;
        }
        cout << A << " " << B <<endl;
    }    
    return 0;
}
/*
3
1000000 500000 10 5 5 5 1000007
3 2 2 1 5 7 6 8 2 9
10 6 10 5 5 5 5
3 1 2 3 5 7 6 8 2 9
10 6 10 5 5 5 5
3 1 3 2 5 7 6 8 2 9
*/
