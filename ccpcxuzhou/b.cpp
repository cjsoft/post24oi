#include <cstdio>
// #include <cassert>
#include <cstring>
#include <iostream>
#define MXN 1007
#define offset 200
using namespace std;
int n, m, k, l;
int A[MXN], B[MXN], C[MXN];
bool cnt[MXN][offset * 2];
bool resu1, resu2;
int main() {
    scanf("%d %d %d %d", &n, &m, &k, &l);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", A + i, B + i, C + i);
        A[i] %= offset;
        B[i] %= offset;
    }
    int lp = 0;
    for (int i = k; i <= 100; ++i) {
        cnt[n + 1][i + offset] = true;
    }
    for (int i = n; i > 0; --i) {
        // memset(cnt[i], 0, sizeof(cnt[i]));
        if (i & 1) {
            for (int j = -100; j <= 100; ++j) {
                bool tag = false;
                if (A[i]) {
                    if (cnt[i + 1][min(100, j + A[i]) + offset])
                        tag = true;
                }
                if (B[i]) {
                    if (cnt[i + 1][max(-100, j - B[i]) + offset])
                        tag = true;
                }
                if (C[i]) {
                    if (cnt[i + 1][-j + offset])
                        tag = true;
                }
                cnt[i][j + offset] = tag;
            }
        } else {
            for (int j = -100; j <= 100; ++j) {
                bool tag = true;
                if (A[i]) {
                    if (!cnt[i + 1][min(100, j + A[i]) + offset])
                        tag = false;
                }
                if (B[i]) {
                    if (!cnt[i + 1][max(-100, j - B[i]) + offset])
                        tag = false;
                }
                if (C[i]) {
                    if (!cnt[i + 1][-j + offset])
                        tag = false;
                }
                cnt[i][j + offset] = tag;
            }
        }
    }
    resu1 = cnt[1][offset + m];
    memset(cnt, 0, sizeof(cnt));
    for (int i = -100; i <= l; ++i) {
        cnt[n + 1][i + offset] = true;
    }
    for (int i = n; i > 0; --i) {
        // memset(cnt[i], 0, sizeof(cnt[i]));
        if ((i & 1) == 0) {
            for (int j = -100; j <= 100; ++j) {
                // assert(j != 7);
                bool tag = false;
                if (A[i]) {
                    if (cnt[i + 1][min(100, j + A[i]) + offset])
                        tag = true;
                }
                if (B[i]) {
                    if (cnt[i + 1][max(-100, j - B[i]) + offset])
                        tag = true;
                }
                if (C[i]) {
                    if (cnt[i + 1][-j + offset])
                        tag = true;
                }
                cnt[i][j + offset] = tag;
            }
        } else {
            for (int j = -100; j <= 100; ++j) {
                bool tag = true;
                if (A[i]) {
                    if (!cnt[i + 1][min(100, j + A[i]) + offset])
                        tag = false;
                }
                if (B[i]) {
                    if (!cnt[i + 1][max(-100, j - B[i]) + offset])
                        tag = false;
                }
                if (C[i]) {
                    if (!cnt[i + 1][-j + offset])
                        tag = false;
                }
                cnt[i][j + offset] = tag;
            }
        }
    }
    resu2 = cnt[1][offset + m];
    if (resu1) {
        puts("Good Ending");
    } else {
        if (resu2) {
            puts("Bad Ending");
        } else {
            puts("Normal Ending");
        }
    }
    return 0;
}