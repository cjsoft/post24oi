#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const float DPS = 0.01;
float lens[281];
int main() {
    lens[0] = 0.0;
    for (int i = 1; i < 281; ++i) lens[i] = lens[i - 1] + 1.0 / (i + 1.0);
    float inpt = 1.0;
    while (true) {
        scanf("%f", &inpt);
        if (inpt < DPS) break;
        printf("%d card(s)\n", lower_bound(lens, lens + 281, inpt) - lens);
    }
    return 0;
}