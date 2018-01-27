#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[107][107];
int s[107];
/* 
    dp[j][i] = min{dp[j][k] + dp[k + 1][i] + s[i] - s[j - 1]}
*/
int main() {
    int n;
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", s + i);
        s[i] += s[i - 1];
        dp[i][i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i - 1; j > 0; --j) {
            for (int k = j; k < i; ++k) {
                dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + s[i] - s[j - 1]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}