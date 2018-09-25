#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a, b;
int a1, b1;
int a2, b2;

int main() {
    scanf("%d %d %d %d %d %d", &a, &b, &a1, &b1, &a2, &b2);
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    if (a > b) swap(a, b);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    swap(a2, b2);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    swap(a, b);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    swap(a2, b2);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    if (b >= a1 + a2 && b1 <= a && b2 <= a) {
        puts("YES");
        return 0;
    }
    swap(a1, b1);
    swap(a, b);
    puts("NO");
    return 0;
}
