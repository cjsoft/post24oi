#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
ll dp[207][207], a[207];
// dp[j][i] = min{dp[j][k] + dp[k + 1][i] + a[k] * a[k + 1] * a[k + 2]}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        a[n + i] = a[i];
    }
    for (int i = 2; i <= n << 1; ++i) {
        for (int j = i - 1; j > 0; --j) {
            for (int k = j; k < i; ++k) {
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
            }
        }
    }
    ll resu = 0;
    for (int i = 1; i <= n; ++i)
        resu = max(resu, dp[i][i + n - 1]);
    printf("%lld\n", resu);
    return 0;
}