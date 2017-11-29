#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int resv[107];
int main() {
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            puts("*");
            return 0;
        }
        memset(resv, 0, sizeof(resv));
        int s, t, k;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &s, &t, &k);
            resv[s] += k;
            resv[t] -= k;
        }
        int fresu = 0;
        for (int i = 1; i < 107; ++i) {
            resv[i] += resv[i - 1];
            if (resv[i] > fresu) fresu = resv[i];
        }
        printf("%d\n", fresu);
    }
    return 0;
}