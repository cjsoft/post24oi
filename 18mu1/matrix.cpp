#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 3007
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll fac[N], inv[N], invfac[N];
ll bpow[N * N | 7];
ll C[N][N];
ll comb(int n, int m) {
    if (m == 0) return 1;
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int main() {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    bpow[0] = 1;
    for (int i = 1; i < (N * N | 7); ++i)
        bpow[i] = (bpow[i - 1] << 1) % MOD;
    fac[0] = fac[1] = inv[0] = inv[1] = invfac[0] = invfac[1] = 1;
    for (int i = 2; i < N; ++i)
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD, fac[i] = fac[i - 1] * i % MOD, invfac[i] = invfac[i - 1] * inv[i] % MOD;
    /* for (int i = 0; i < N; ++i) */
    /*     assert(fac[i] * invfac[i] % MOD == 1); */
    /* for (int i = 1; i < N; ++i) */
    /*     C[1][i] = bpow[i] - 2; */
    /*         /1* C[1][i] = (C[1][i] + comb(i, j)) % MOD; *1/ */
    /* for (int i = 2; i < N; ++i) */
    /*     for (int j = i + 1; j < N; ++j) */
    /*         C[i][j] = (C[i - 1][j] - comb(j, i - 1) + MOD) % MOD; */
    for (int i = a; i <= n; ++i)
        for (int j = a; j < i; ++j)
            C[a][i] = (C[a][i] + comb(i, j)) % MOD;
    for (int i = b; i <= m; ++i)
        for (int j = b; j < i; ++j)
            C[b][i] = (C[b][i] + comb(i, j)) % MOD;
    ll ans = 0;
    for (int i = a; i <= n; ++i) {
        ll tmpans = 0;
        for (int j = b; j <= m; ++j) {
            tmpans = (tmpans + (1 - C[b][j]) * comb(m, j) % MOD * bpow[(n - i) * (m - j)] % MOD) % MOD;
        }
        ans = (ans + (1 - C[a][i]) * comb(n, i) % MOD * tmpans % MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
