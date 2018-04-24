#include <cstdio>
#include <iostream>

using namespace std;
int f(int a, int b) {
    if (a && b) return f(b % a, a) + 1;
    else return 0;
}

int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        printf("%d\n", f(a, b));
    }
    return 0;
}