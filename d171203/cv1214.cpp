#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 107
using namespace std;
struct line {
    int x, y;
    line() { x = y = 0; }
    line(int _a, int _b) { x = _a; y = _b; }
    bool operator<(const line &b) const {
        if (y == b.y) return x > b.x;
        return y < b.y;
    }
} lns[MXN];
int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        lns[i] = line(a, b);
    }
    sort(lns, lns + n);
    int cnt = 0;
    int ly = -1000;
    for (int i = 0; i < n; ++i) {
        if (lns[i].x >= ly) ++cnt, ly = lns[i].y;
    }
    printf("%d\n", cnt);
}