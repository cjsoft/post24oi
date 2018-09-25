#ifndef BZ
#pragma GCC optimize "-O3"
#endif

#include <bits/stdc++.h>

//#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

#define LL long long
#define ll long long
#define uLL unsigned long long
#define ull unsigned long long
#define sqr(x) (x)*(x)
using namespace std;
inline int read() {
    int f = 1, x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

vector<int> num({1, 2, 3, 5, 7, 13, 17, 23, 31, 37, 53, 71, 73, 137, 173, 317});
char s[120];
int main()
{
#ifdef FASTIO
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
    int T = read();
    for(int tt = 1; tt <= T; tt++)  {
        cin >> s;
        int ans = -1;
        if(strlen(s) > 4) {
            ans = 317;
        }
        else {
            int n = atoi(s);
            auto it = upper_bound(num.begin(), num.end(), n);
            ans = *(--it);
        }
        printf("Case #%d: %d\n",tt, ans);
    }
    return 0;
}

