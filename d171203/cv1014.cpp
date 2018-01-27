#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[37][20007];

int v, n, av[37];

int main() {
    scanf("%d %d", &v, &n);
    for (int i = 1; i <= n; ++i) scanf("%d", av + i);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < av[i]; ++j) dp[i][j] = dp[i - 1][j];
        for (int j = v; j >= av[i]; --j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - av[i]] + av[i]);
        }
    }
    printf("%d\n", v - dp[n][v]);
    return 0;
}