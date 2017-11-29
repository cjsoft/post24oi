#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

ll cbnd[10007];
int main() {
    for (ll i = 0; i < 10007; ++i) cbnd[i] = (i + 2) * (i + 2) * (i + 2) - (i + 1) * (i + 1) * (i + 1);
    int T;
    scanf("%d", &T);
    while (T--) {
        ll tmp, *t;
        scanf("%lld", &tmp);
        t = lower_bound(cbnd, cbnd + 10007, tmp);
        if (*t == tmp) puts("YES");
        else puts("NO");
    }
    return 0;
}