#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 5007
using namespace std;

int dp[MXN];
int a[MXN];
int main() {
    int n, resu = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j]);
        }
        ++dp[i];
        resu = max(dp[i], resu);
    }
    printf("%d\n", resu);
}