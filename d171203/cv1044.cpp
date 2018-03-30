#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dp[27];
int h[27];
int main() {
    int n = 0;
    for (; ~scanf("%d", h + n); ++n);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (h[i] <= h[j]) dp[i] = max(dp[i], dp[j]);
        }
        ++dp[i];
    }
    int mm = 0;
    for (int i = 0; i < n; ++i) mm = max(mm, dp[i]);
    printf("%d\n", mm);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (h[i] > h[j]) dp[i] = max(dp[i], dp[j]);
        }
        ++dp[i];
    }
    mm = 0;
    for (int i = 0; i < n; ++i) mm = max(mm, dp[i]);
    printf("%d\n", mm);
    return 0;
}