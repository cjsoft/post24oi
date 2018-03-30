#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
int mx, my, n, m;
ll dp[17][17];
bool check(int x, int y) {
    if (mx == x && my == y || abs(mx - x) == 2 && abs(my - y) == 1 || abs(mx - x) == 1 && abs(my - y) == 2 )
        return true;
    else return false;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &mx, &my);
    dp[0][1] = 1;
    for (int i = 1; i <= m + 1; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            if (!check(j - 1, i - 1)) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    printf("%lld\n", dp[m + 1][n + 1]);
    return 0;
}