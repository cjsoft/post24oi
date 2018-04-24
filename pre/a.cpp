#include <algorithm>
#include <cstdio>
#include <algorithm>
typedef long long ll;
ll fib[1000];
using namespace std;
int lb(int x) {
    for (int i = 1; i < 91; ++i) {
        if (fib[i] > x) return i;
    }
}
int main() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 91; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
        // printf("%lld ", fib[i]);
    }
    // putchar('\n');
    int T;
    // scanf("%d", &T);
    ll n;
    while (~scanf("%lld", &n)) {
        // int pos = lb(n);
        int pos = lower_bound(fib, fib + 91, n + 1) - fib;
        printf("%d %lld %lld\n", pos - 1, fib[pos - 1], fib[pos - 2]);
    }
}
// 1293530146158671551