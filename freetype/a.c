#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", (1 << a + 1)  - 1);
    return 0;
}