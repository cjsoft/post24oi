#include <cstdio>
#include <cstring>
#include <iostream>
#define N 2000
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &mp[i][j]);
        }
    }
    for (int i = 1; i < N; ++i) {
        int flag1 = 2, flag2 = 2;
        for (int j = i + 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                if (mp[k][i] == mp[k][j] && mp[k][i] == 1 && !(--flag1)) {
                    puts("NO1");
                    assert(false);
                }
                if (mp[i][k] == mp[j][k] && mp[i][k] == 1 && !(--flag2)) {
                    puts("NO2");
                    assert(false);
                }
            }
        }
    }
}
