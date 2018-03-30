/**--------------------
 * Chinese Remainder Theorem Algorithm
 *
 * Time Consumption: n \log{m}
 * Mem Consumption:
 * Author: cjsoft
 * Date: 2018/01/29
 * --------------------
 */

int exgcd(int a, int b, int &x, int &y) {
    if (b) {
        int r = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    } else {
        x = 1; y = 0;
        return a;
    }
}

int CRT(int a[], int m[], int n) {
    int M = 1;
    for (int i = 0; i < n; ++i)
        M *= m[i];
    int ans = 0, x, y, tm;
    for (int i = 0; i < n; ++i) {
        tm = M / m[i];
        exgcd(tm, m[i], x, y);
        ans = (ans + tm * x * a[i]) % M;
    }
    return (ans + M) % M;
}