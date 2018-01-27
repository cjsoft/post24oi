#include <stdio.h>
int p[1001][2];
int main() {
    int a = 0, b, n;
    scanf("%d", n);
    while (n--) {
        b = a;
        scanf("%d", &a);
        p[a][0] = b;
        p[b][1] = a;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (p[a][0]) printf("%d", p[a][0]);
        if (p[a][1]) printf(p[a][0] ? " %d\n" : "%d\n", p[a][1]);
        if (!(p[a][0] && !p[a][1])) puts("NULL");
    }
    return 0;
}