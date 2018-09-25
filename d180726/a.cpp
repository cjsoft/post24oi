#include <cstdio>
#include <cstring>
#include <iostream>
#define mid ((l + r) >> 1)
#define lson (root << 1)
#define rson (root << 1 | 1)
#define f(x) ((x) > 0 ? 1 : 0)
#define N 400007
using namespace std;
typedef long long ll;
int n;
ll a[N], p[N];
struct node {
    node *c[2];
} buffer[N << 5 | 7], *cur, *root;
node *newnode() {
    cur->c[0] = cur->c[1] = NULL;
    return cur++;
}
void insert(ll dta) {
    node *p = root;
    for (int i = 30; i >= 0; --i) {
        int d = f(dta & (1 << i));
        if (!p->c[d]) p->c[d] = newnode();
        p = p->c[d];
    }
}
ll query(ll dta) {
    node *p = root;
    ll rtn = 0;
    for (int i = 30; i >= 0 && p; --i) {
        int d = f(dta & (1 << i));
        if (p->c[d ^ 1]) {
            rtn += 1 << i;
            p = p->c[d ^ 1];
        } else p = p->c[d];
    }
    return rtn;
}
ll lbest[N], rbest[N];
int main() {
    scanf("%d", &n);
    cur = buffer;
    root = newnode();
    insert(0);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i), p[i] = p[i - 1] ^ a[i];
    for (int i = 1; i <= n; ++i) {
        lbest[i] = max(lbest[i - 1], query(p[i]));
        insert(p[i]);
    }
    cur = buffer;
    root = newnode();
    insert(0);
    for (int i = n; i > 0; --i) {
        rbest[i] = max(rbest[i + 1], query(p[i - 1] ^ p[n]));
        insert(p[i - 1] ^ p[n]);
    }
    ll resu = 0;
    for (int i = 1; i < n; ++i) {
        resu = max(resu, lbest[i] + rbest[i + 1]);
    }
    /* for (int i = 1; i <= n; ++i) */
    /*     cout << lbest[i] << ' '; */
    /* cout << endl; */
    /* for (int i = 1; i <= n; ++i) */
    /*     cout << rbest[i] << ' '; */
    /* cout << endl; */
    /* printf("%lld\n", resu); */
    cout << resu << endl;
    /* puts("A"); */
    return 0;
}
