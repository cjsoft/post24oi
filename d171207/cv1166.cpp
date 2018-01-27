#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct bnum {
    int dat[37], len;
    bnum() { memset(dat, 0, sizeof(dat)); len = 1; }
    bnum(int x) {
        memset(dat, 0, sizeof(dat));
        len = 0;
        for (; x; x /= 10) dat[++len] = x % 10;
    }
    bool operator<(const bnum &b) const {
        if (len == b.len)
            for (int i = len; i; --i)
                if (dat[i] != b.dat[i])
                    return dat[i] < b.dat[i];
        return len < b.len;
    }
    bnum operator+(bnum b) {
        bnum rtn;
        rtn.len = max(len, b.len);
        for (int i = 1; i <= rtn.len; ++i)
            rtn.dat[i] = dat[i] + b.dat[i];
        for (int i = 1; i <= rtn.len; ++i)
            rtn.dat[i + 1] += rtn.dat[i] / 10, rtn.dat[i] %= 10;
        if (rtn.dat[rtn.len + 1]) ++rtn.len;
        return rtn;
    }
    bnum operator*(bnum b) {
        bnum rtn;
        rtn.len = len + b.len;
        for (int i = 1; i <= len; ++i)
            for (int j = 1; j <= b.len; ++j)
                rtn.dat[i + j - 1] += dat[i] * b.dat[j];
        for (int i = 1; i <= rtn.len; ++i)
            rtn.dat[i + 1] += rtn.dat[i] / 10, rtn.dat[i] %= 10;
        for (; !rtn.dat[rtn.len]; --rtn.len);
        return rtn;
    }
    void print() {
        for (int i = len; i; --i) putchar('0' + dat[i]);
    }
} dp[87][87], a[87], b2(2), qpow[87], sum;

int main() {
    qpow[0] = bnum(1);
    for (int i = 1; i < 87; ++i)
        qpow[i] = qpow[i - 1] * b2;
    int n, m, tmp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &tmp);
            a[j] = bnum(tmp);
            dp[j][j] = a[j] * qpow[m];
        }
        for (int j = 2; j <= m; ++j) {
            for (int k = j - 1; k; --k) {
                dp[k][j] = max(dp[k + 1][j] + a[k] * qpow[m - j + k], dp[k][j - 1] + a[j] * qpow[m - j + k]);
            }
        }
        sum = sum + dp[1][m];
    }
    sum.print();
    putchar('\n');
    return 0;
}