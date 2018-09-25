#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int a[107];
int main() {
    int n, m;
    int fp = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    /* for (int i = 0; i < m; ++i) { */
    /*     if (!a[i]) a[i] = 0x3f3f3f3f; */
    /* } */
    sort(a, a + 101);
    reverse(a, a + 101);
    int resu = 0;
    for (fp = 1; fp <= 100; ++fp) {
        int j = 0;
        int pb = n;
        while (a[j] >= fp && pb > 0) {
            pb -= a[j] / fp;
            ++j;
        }
        if (pb <= 0) {
            resu = max(resu, fp);
        } else {

        }
    }
    
    printf("%d\n", resu);
    return 0;
}
