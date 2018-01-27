#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dp[41][41][41][41];
int cnts[5];
int w[357];
int n, m;
inline void selmax(int &b, int c) {
    if (c > b) b = c;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", w + i);
    }
    int q;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &q);
        ++cnts[q];
    }
    int tmp;
    dp[0][0][0][0] = w[1];
    for (int i = 0; i <= cnts[1]; ++i) {
        for (int j = 0; j <= cnts[2]; ++j) {
            for (int k = 0; k <= cnts[3]; ++k) {
                for (int l = 0; l <= cnts[4]; ++l) {
                    tmp = w[1 + i + j * 2 + k * 3 + l * 4];
                    if (i) selmax(dp[i][j][k][l], dp[i - 1][j][k][l] + tmp);
                    if (j) selmax(dp[i][j][k][l], dp[i][j - 1][k][l] + tmp);
                    if (k) selmax(dp[i][j][k][l], dp[i][j][k - 1][l] + tmp);
                    if (l) selmax(dp[i][j][k][l], dp[i][j][k][l - 1] + tmp);
                }
            }
        }
    }
    printf("%d\n", dp[cnts[1]][cnts[2]][cnts[3]][cnts[4]]);
    return 0;
}