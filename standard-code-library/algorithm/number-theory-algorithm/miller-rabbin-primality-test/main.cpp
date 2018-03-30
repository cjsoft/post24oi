/**--------------------
 * Miller-Rabbin Primality Test
 *
 * Time Consumption: S \log_3{P}
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/27
 * --------------------
 */

typedef long long MRTP;

MRTP qpow(MRTP x, MRTP y, MRTP MOD) {
    MRTP resu = 1;
    for (; y; y >>= 1, x = (x * x) % MOD)
        if (y & 1) resu = (resu * x) % MOD;
    return resu;
}

char MillerRabbinTest(MRTP a, MRTP n, MRTP d, MRTP s) {
    if (n == 2 || n == a) return 1;
    if (!(n & 1)) return 0;
    if (qpow(a, d, n) == 1) return 1;
    for (int i = 0; i < s; ++i)
        if (qpow(a, (1 << i) * d, n) == n - 1)
            return 1;
    return 0;
}

char isprime(MRTP x) {
#ifndef I64SUP
#define I64SUP
#define TESTCASESZ 3
    const MRTP testCase[] = {2, 7, 61};
#else
#define TESTCASESZ 7
    const MRTP testCase[] ={2, 325, 9375, 28178, 450775, 9780504, 1795265022};
#endif
    if (x < 2) return 0;
    MRTP tint = x - 1;
    MRTP s = 0;
    for (; !(tint & 1); tint >>= 1, ++s);
    for (int i = 0; i < TESTCASESZ; ++i)
        if (!MillerRabbinTest(testCase[i], x, tint, s))
            return 0;
    return 1;
}

