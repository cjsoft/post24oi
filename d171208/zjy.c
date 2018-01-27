#include <stdio.h>
int a[] = {100, 50, 20, 10, 5, 2, 1};
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; n && i < sizeof(a) / sizeof(int); ++i) {
        if (n / a[i]) {
            printf("%d:%d\n", a[i], n / a[i]);
            n %= a[i];
        }
    }
}