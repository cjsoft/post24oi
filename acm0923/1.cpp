#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int p[107], pp[107];
bool tag[107];
int relocator[107];
int main() {
    int n, m, q;
    while (~scanf("%d %d", &n, &m)) {
        memset(p, 0, sizeof(p));
        memset(pp, 0, sizeof(pp));
        memset(tag, 0, sizeof(tag));
        memset(relocator, 0, sizeof(relocator));
        for (int i = 0; i < n; ++i) scanf("%d", p + i);
        scanf("%d", &q);
        int tmp;
        for (int i = 0; i < q; ++i) {
            scanf("%d", &tmp);
            tag[tmp] = true;
        }
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (!tag[i]) {
                relocator[cur] = i;
                pp[cur++] = p[i];
            }
        }
        int fresu = 0x7fffffff;
        int a, b;
        // for (int i = 0; i < n - 1; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         if (j - i >= m) break;
        //         if (p[i] + p[j] < fresu && !tag[i] && !tag[j]) {
        //             fresu = p[i] + p[j];
        //             a = i; b = j;
        //         }
        //     }
        // }
        for (int i = 0; i < cur - m + 1; ++i) {
            for (int j = i + 1; j < cur; ++j) {
                if (j - i >= m) break;
                if (pp[i] + pp[j] < fresu) {
                    fresu = pp[i] + pp[j];
                    a = relocator[i]; b = relocator[j];
                }
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}