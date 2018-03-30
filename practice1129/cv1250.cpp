#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int q;
int a[5][2][2];
int resu[2][2];
int mul(int a, int b) {
    int tmp = 0;
    for (; b; b >>= 1, a = (a << 1) % q) if (b & 1) tmp = (tmp + a) % q;
    return tmp;
}
inline void matmul(int d[2][2], int b_[2][2], int c_[2][2]) {
    static int b[2][2], c[2][2];
    memcpy(b, b_, sizeof(b));
    memcpy(c, c_, sizeof(c));
    d[0][0] = (mul(b[0][0], c[0][0]) + mul(b[0][1], c[1][0])) % q;
    d[0][1] = (mul(b[0][0], c[0][1]) + mul(b[0][1], c[1][1])) % q;
    d[1][0] = (mul(b[1][0], c[0][0]) + mul(b[1][1], c[1][0])) % q;
    d[1][1] = (mul(b[1][0], c[0][1]) + mul(b[1][1], c[1][1])) % q;
}
void matqpow(int m[2][2], int y) {
    int tmp[2][2][2];
    resu[0][0] = 1;
    resu[0][1] = 0;
    resu[1][0] = 0;
    resu[1][1] = 1;
    int t = 1;
    memcpy(tmp[1], m, sizeof(tmp[1]));
    for (; y; y >>= 1, matmul(tmp[t ^ 1], tmp[t], tmp[t]), t ^= 1) if (y & 1) {
        matmul(resu, resu, tmp[t]);
    }
}
int main() {
    a[0][0][0] = a[0][0][1] = a[0][1][0] = 1;
    a[0][1][1] = 0;
    int n;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        matqpow(a[0], n);
        printf("%d\n", (resu[1][0] + resu[1][1]) % q);
    }
    
    return 0;
}