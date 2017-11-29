#include <stdio.h>
#include <string.h>
#include <ctype.h>
inline int getint() {
    static int tmp, f;
    static char ch;
    tmp = 0, f = 1;
    for (ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
    for (; isdigit(ch); ch = getchar()) tmp = tmp * 10 + ch - '0';
    return f * tmp;
}

int main() {
    int a = getint(), b = getint();
    printf("%d %d\n", a + b, a - b);
}