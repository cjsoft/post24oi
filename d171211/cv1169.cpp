#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
// dp[x1][x2][l] = max{dp[x1 - 1][x2][l - 1], dp[x1][x2][l - 1], dp[x1 - 1][x2 - 1][l -1], dp[x1][x2 - 1][l - 1]} + a[x1][l - x1 + 2] + a[x2][l - x2 + 2];
int dp[57][57][57 >> 1 | 1];
int a[57][57];
int n, m;
inline int smax(int &a, int b) {
    if (b > a) return a = b;
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int l = 1; l < m + n - 2; ++l) {
        for (int x1 = 1; x1 <= n && x1 <= l + 1; ++x1) {
            for (int x2 = 1; x2 <= n && x2 <= l + 1; ++x2) {
                if (x1 != x2) {
                    smax(dp[x1][x2][l], dp[x1 - 1][x2][l - 1]);
                    smax(dp[x1][x2][l], dp[x1 - 1][x2 - 1][l - 1]);
                    smax(dp[x1][x2][l], dp[x1][x2 - 1][l - 1]);
                    smax(dp[x1][x2][l], dp[x1][x2][l - 1]);
                    dp[x1][x2][l] += a[l - x1 + 2][x1] + a[l - x2 + 2][x2];
                }
            }
        }
    }
    smax(dp[n][n][m + n - 2], dp[n - 1][n][m + n - 3]);
    smax(dp[n][n][m + n - 2], dp[n - 1][n - 1][m + n - 3]);
    smax(dp[n][n][m + n - 2], dp[n][n - 1][m + n - 3]);
    smax(dp[n][n][m + n - 2], dp[n][n][m + n - 3]);
    printf("%d\n", dp[n][n][m + n - 2]);
    return 0;
}