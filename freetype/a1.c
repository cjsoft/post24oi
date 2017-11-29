#include <stdio.h>

char a;
long long b,c,d,e;
double f,g;

int main() {
    printf("The result is:\n");
    scanf("%c", &a);
    printf("The 'char' variable is %c, it takes 1 byte.\n", a);
    scanf("%lld%lld%lld%lld", &b,&c,&d,&e);
    printf("The 'short' variable is %lld, it takes 2 bytes.\n", b);
    printf("The 'int' variable is %lld, it takes 4 bytes.\n", c);
    printf("The 'long' variable is %lld, it takes 4 bytes.\n", d);
    printf("The 'long long' variable is %lld, it takes 8 bytes.\n",e);
    scanf("%lf%lf",&f,&g);
    printf("The 'float' variable is %lf, it takes 4 bytes.\n", f);
    printf("The 'double' variable is %lf, it takes 8 bytes.\n", g);
    return 0;
}