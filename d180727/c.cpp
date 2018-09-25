#include <cstdio>
#include <cstring>
#include <iostream>
#define N 1007
using namespace std;
int n, m;
double a[N], b[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", b + i);
    for (int i = 1; i <= n; ++i)
        if (a[i] <= 1 || b[i] <= 1) {
            puts("-1");
            return 0;
        }
    double f = 1. * m / (b[1] - 1);
    for (int i = n; i > 1; --i) {
        f += (m + f) / (a[i] - 1);
        f += (m + f) / (b[i] - 1);
    }
    f += (m + f) / (a[1] - 1);
    printf("%lf\n", f);
    return 0;
}
