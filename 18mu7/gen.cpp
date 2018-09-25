#include <bits/stdc++.h>

using namespace std;


int main() {
    srand(19260817);
    int T = 5;
    freopen("input.txt", "w", stdout);
    printf("%d\n", T);
    while (T--) {
        int n = 200, k = 5;
        printf("%d %d\n", n, k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j)
                printf("%d ", rand() % 1000000);
            for (int j = 0; j < k; ++j)
                printf("%d ", rand() % 1000000);
            putchar('\n');
        }

    }
    return  0;
}
