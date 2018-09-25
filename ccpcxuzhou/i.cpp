#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define abs(a) (((a) < 0) ? (-(a)) : (a))
#define MXN 1000007

using namespace std;

char input[MXN];
char inpt[7];
int n;
int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s\n%s", &n, inpt, input);
        int l = strlen(input), resu = l * 2;
        for (int i = 0; i < l; ++i) {
            int tmp = abs(inpt[0] - input[i]);
            if (tmp > 0 && tmp < 10) {
                resu--;
                break;
            }
            if (tmp >= 10) break;
            if (tmp == 0) resu -= 2;
        }
        if (resu == 0) resu = 1;
        printf("%d\n", resu);
    }
}