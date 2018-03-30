#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    float x = 0.0, inpt;
    for (int i = 0; i < 12; ++i) {
        scanf("%f", &inpt);
        x += inpt;
    }
    printf("$%.2f\n", x / 12);
}