#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n & 1  && m & 1) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    putchar('(');
                }
                putchar('\n');
            }
        } else if (n & 1) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    putchar(j & 1 ? '(' : ')');
                }
                putchar('\n');
            }
        } else if (m & 1) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    putchar(i & 1 ? '(' : ')');
                }
                putchar('\n');
            }
        } else {
            if (n <= m) {
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= m; ++j) {
                        putchar(j & 1 ? '(' : ')');
                    }
                    putchar('\n');
                }
            } else {
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= m; ++j) {
                        putchar(i & 1 ? '(' : ')');
                    }
                    putchar('\n');
                }
            }
        }
    }
}
