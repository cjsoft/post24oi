#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MXN 1000007
#define MD 1000000007LL
using namespace std;
typedef long long ll;
typedef unsigned int uint;
uint seq[MXN];
ll twopow[MXN];
int T;
int n, m;
int main() {
    twopow[0] = 1;
    for (int i = 1; i < MXN; ++i)
        twopow[i] = (twopow[i - 1] << 1) % MD;
    scanf("%d", &T);
    while (T--) {
        memset(seq, 0, sizeof(seq));
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%ud", seq + i);
            seq[i] ^= seq[i - 1];
        }
        ll resu = 0;
        for (int i = 1; i <= m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (seq[b] ^ seq[a - 1]) {
                resu += twopow[m - i];
                resu %= MD;
            }
        }
        printf("%lld\n", resu);
    }
    return 0;
}