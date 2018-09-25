#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int s = a * 2 + b * 2 + 1;
        int tmp = 0;
        for (int i = 1; i <= b; ++i) {
            for (int j = 0; j <= 2 * b - i * 2 + 1; ++j) putchar('.'), tmp++;
            for (int j = 1; j <= a; ++j) printf("+-"), tmp += 2;
            printf("+"), tmp++;
            for (int j = 1; j < min(i, c + 1); ++j) printf(".+"), tmp += 2;
            for (; tmp < s; ++tmp) putchar('.');
            putchar('\n');
            tmp = 0;
            for (int j = 1; j <= 2 * b - i * 2; ++j) putchar('.'), tmp++;
            for (int j = 0; j <= a; ++j) printf("./"), tmp += 2;
            for (int j = 1; j < min(i, c + 1); ++j) printf("|/"), tmp += 2;
            if (i <= c) printf("|"), tmp++;
            for (; tmp < s; ++tmp) putchar('.');
            putchar('\n');
            tmp = 0;
            
        }
        for (int i = 1; i <= c - b; ++i) {
            for (int j = 1; j <= a; ++j) printf("+-"), tmp += 2;
            for (int j = 1; j <= b; ++j) printf("+."), tmp += 2;
            printf("+"), tmp++;
            for (; tmp < s; ++tmp) putchar('.');
            putchar('\n');
            tmp = 0;
            for (int j = 1; j <= a; ++j) printf("|."), tmp += 2;
            for (int j = 1; j <= b; ++j) printf("|/"), tmp += 2;
            printf("|"), tmp++;
            for (; tmp < s; ++tmp) putchar('.');
            putchar('\n');
            tmp = 0;
        }
        for (int i = 1; i <= min(b, c); ++i) {
            for (int j = 1; j <= a; ++j) printf("+-"), tmp += 2;
            putchar('+'), tmp++;
            for (int j = 0; j <= min(b - i, c - i); ++j) printf(".+"), tmp += 2;
            for (int j = 1; j < i; ++j) printf(".."), tmp += 2;
            for (; tmp < s; ++tmp) putchar('.');
            putchar('\n');
            tmp = 0;
            for (int j = 1; j <= a; ++j) printf("|."), tmp += 2;
            for (int j = 0; j <= min(b - i, c - i); ++j) printf("|/"), tmp += 2;
            for (int j = 1; j < i; ++j) printf(".."), tmp += 2;
            putchar('.'), tmp++;
            for (; tmp < s; ++tmp) putchar('.');
            putchar('\n');
            tmp = 0;

        }
        for (int i = 1; i <= a; ++i) printf("+-"), tmp += 2;
        putchar('+'), tmp ++;
        for (int i = 1; i <= b; ++i) printf(".."), tmp += 2;
        for (; tmp < s; ++tmp) putchar('.');
        putchar('\n');
        tmp = 0;
    }
    return 0;
}
