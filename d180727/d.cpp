#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int m, n;
int a[37];
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i < n; ++i) {
        puts("1");
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x == 2 || x == 0) return 0;
        if (x == -1) a[i] = 1;
        else a[i] = 0;
    }
    int l = 1, r = m + 1;
    int mid = (l + r) >> 1;
    int x, pp = 0;
    while (l < r) {
        mid = (l + r) >> 1;
        printf("%d\n", mid);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x == 2 || x == 0) return 0;
        if (x == 1) x = 1;
        else x = 0;
        if (x ^ a[pp]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        pp = (pp + 1) % n;
    }
    printf("%d\n", l);
    fflush(stdout);
    return 0;
}
