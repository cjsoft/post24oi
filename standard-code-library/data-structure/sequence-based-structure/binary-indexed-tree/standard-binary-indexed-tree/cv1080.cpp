#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define BMXN 100007
#define lowbit(x) ((x) & (-(x)))
typedef long long TP;

TP _SEQUENCE[BMXN];

void BIT_ADD(int pos, TP adata) {
    for (; pos < BMXN; pos += lowbit(pos))
        _SEQUENCE[pos] += adata;
}

TP BIT_QUERY(int pos) {
    TP rtn = 0;
    for (; pos; pos -= lowbit(pos))
        rtn += _SEQUENCE[pos];
    return rtn;
}

inline void BIT_INIT() {
    memset(_SEQUENCE, 0, sizeof(_SEQUENCE));
}

int main() {
    BIT_INIT();
    int n, m;
    int a, b, c;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        BIT_ADD(i, (scanf("%d", &a), a));
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) BIT_ADD(b, c);
        else printf("%lld\n", BIT_QUERY(c) - BIT_QUERY(b - 1));
    }
}
