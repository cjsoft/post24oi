#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[2007], n;
struct line {
    int x, y, c;
    bool operator<(const line &b) const {
        if (y == b.y) return x > b.x;
        return y < b.y;
    }
} raw[1007];
int sss[2007];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &raw[i].x, &raw[i].y, &raw[i].c);
        sss[i << 1] = raw[i].x;
        sss[i << 1 | 1] = raw[i].y;
    }
    sort(sss, sss + (n << 1));
    for (int i = 0; i < n; ++i) {
        raw[i].x = lower_bound(sss, sss + (n << 1), raw[i].x) - sss;
        raw[i].y = lower_bound(sss, sss + (n << 1), raw[i].y) - sss;
    }
    sort(raw, raw + n);
    for (int i = 0; i < n; ++i) {
        for (int j = raw[i].x + 1; j < raw[i].y; ++j) {
            dp[raw[i].y] = max(dp[raw[i].y], dp[j]);
        }
        for (int j = 0; j <= raw[i].x; ++j) {
            dp[raw[i].y] = max(dp[raw[i].y], dp[j] + raw[i].c);
        }
    }
    printf("%d\n", dp[raw[n - 1].y]);
}