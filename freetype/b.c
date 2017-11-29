#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    puts("The result is:");
    printf("The 'char' variable is %c, it takes 1 byte.\n", getchar());
    short a; int b; long c; long long d; float e; double f;
    scanf("%hd%d%ld%lld%f%lf", &a, &b, &c, &d, &e, &f);
    printf("The 'short' variable is %hd, it takes 2 bytes.\n", a);
    printf("The 'int' variable is %d, it takes 4 bytes.\n", b);
    printf("The 'long' variable is %ld, it takes 4 bytes.\n", c);
    printf("The 'long long' variable is %lld, it takes 8 bytes.\n", d);
    printf("The 'float' variable is %f, it takes 4 bytes.\n", e);
    printf("The 'double' variable is %lf, it takes 8 bytes.\n", f);
    return 0;
}