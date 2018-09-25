#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef set<int>::iterator III;
set<int> s[2];
int n;
typedef long long ll;
III adv(III p, int dis) {
    advance(p, dis);
    return p;
}
int main() {
    scanf("%d", &n);
    int a;
    ll b, resu = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %lld", &a, &b);
        if (s[a].size()) {
            III p1 = s[a].lower_bound(b);
            if (p1 == s[a].end() && distance(s[a].begin(), p1) > 1) p1 = adv(p1, -1);
            if (distance(s[a].begin(), p1)) {
                if (abs(*p1 - b) >= abs(*adv(p1, -1) - b)) p1 = adv(p1, -1);
            }
            resu = (resu + abs(*p1 - b)) % 1000000;
            s[a].erase(p1);
        } else {
            s[a ^ 1].insert(b);
        }

    }
    printf("%lld\n", resu);
    return 0;
}
