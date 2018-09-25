#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int s[1007];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", s + i);
    while (1) {
        int a, b;
        scanf("%d %d", &a, &b);
        reverse(s + a, s + b + 1);
        for (int i = 1; i <= n; ++i) printf("%d ", s[i]);
        putchar('\n');
    }
}
