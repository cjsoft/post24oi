#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#define MXM 5000007
using namespace std;

const int N = 100005;
const int mod = 1 << 30;

typedef unsigned int uint;

uint x, y, z, w;
int n, m;
uint rng61() {
    x = x ^ (x << 11);
    x = x ^ (x >> 4);
    x = x ^ (x << 5);
    x = x ^ (x >> 14);
    w = x ^ (y ^ z);
    x = y;
    y = z;
    z = w;
    return z;
}
uint tmp[(MXM * 3) | 7];
vector<int> v[N];
multiset<int> s;
int a[N];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        cin >> n >> m >> x >> y >> z;
        for (int i = 1; i <= 3 * m; ++i)
            tmp[i] = rng61();
        for (int i = 1; i <= n + 1; i++) v[i].clear();
        for (int i = 1; i <= m; i++) {
            int l = tmp[3 * i - 2] % n + 1, r = tmp[3 * i - 1] % n + 1;
            if (l > r) swap(l, r);
            int val = tmp[3 * i] % mod;
            v[l].push_back(val); v[r + 1].push_back(-val);
        }
        s.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                int now = v[i][j];
                if (now > 0) s.insert(now);
                else s.erase(s.find(-now));
            }
            a[i] = *--s.end();
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            ans ^= (long long)i * a[i];
        cout << ans << endl;
    }
    return 0;
}
