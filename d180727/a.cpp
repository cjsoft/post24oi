#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int a[256];
char s[57];
int dp[256][57][2];
int n, k;
int main() {
    scanf("%d %d\n", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; ++i)
        a[s[i]]++;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 'a'; i <= 'z'; ++i) {
        dp[i][0][0] = 0;
        if (a[i]) dp[i][1][1] = i - 'a' + 1;
    }
    for (int i = 'b'; i <= 'z'; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][1]);
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
            if (a[i]) {
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] + i - 'a' + 1);
            }
        }
    }
    int tmp = 0x3f3f3f3f;
    for (int i = 'a'; i <= 'z'; ++i) {
        tmp = min(tmp, dp[i][k][1]);
    }
    if (tmp < 0x3f3f3f3f) {
        printf("%d\n", tmp);
    } else puts("-1");
    return 0;
}
