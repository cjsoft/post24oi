/**--------------------
 * Splay Tree (no array editipon)
 *
 * Time Consumption: \log{n} (average, per operatoion)
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/02/02
 * --------------------
 */
#include <cstring>
#include <iostream>


#define SPTMXN 200007

#define mid(l, r) (((l) + (r)) >> 1)

#define NIL 0
#define N nodelist
typedef long long SPTTP;
struct SplayTree {
    struct node {
        int s[2];
        int par;
        int sz;
        char isrev;
        SPTTP tag;
        SPTTP data;
        SPTTP sum;
    } nodelist[SPTMXN];
    int root, cur;
    int stk[SPTMXN], pcur, tot; // for splay()
    SplayTree(): root(0), cur(1) {
        memset(nodelist, 0, sizeof(nodelist));
    }
    inline void rev(int x) {
        if (!x) return;
        std::swap(N[x].s[0], N[x].s[1]);
        N[x].isrev ^= 1;
    }
    inline void add(int x, SPTTP adata) {
        N[x].data += adata;
        N[x].sum += adata * N[x].sz;
        N[x].tag += adata;
    }
    inline void pushdown(int x) {
        if (!x) return;
        if (N[x].tag) {
            add(N[x].s[0], N[x].tag);
            add(N[x].s[1], N[x].tag);
            N[x].tag = 0;
        }
        if (N[x].isrev) {
            rev(N[x].s[0]);
            rev(N[x].s[1]);
            N[x].isrev = 0;
        }
    }
    inline int newnode(SPTTP value, int parent) {
        N[cur].data = value;
        N[cur].sz = 1;
        N[cur].s[0] = N[cur].s[1] = 0;
        N[cur].par = parent;
        N[cur].tag = 0;
        N[cur].sum = value;
        return cur++;
    }
    int build_from_sequence(SPTTP seq[], int l, int r, int parent) {
        if (l == r) {
            return newnode(seq[l], parent);
        }
        if (l > r) return 0;
        int m = mid(l, r), t = newnode(seq[m], parent);
        N[t].s[0] = build_from_sequence(seq, l, m - 1, t);
        N[t].s[1] = build_from_sequence(seq, m + 1, r, t);
        update(t);
        return t;
    }
    inline void update(int x) {
        if (!x) return;
        pushdown(N[x].s[0]);
        pushdown(N[x].s[1]);
        N[x].sz = N[N[x].s[0]].sz + N[N[x].s[1]].sz + 1;
        N[x].data = N[N[x].s[0]].data + N[N[x].s[1]].data;
    }
    inline int isson(int x) {
        if (N[N[x].par].s[0] == x) return 0;
        else if (N[N[x].par].s[1] == x) return 1;
        else return -1;
    }
    inline void rotate(int x) {
        int p = N[x].par, z = N[p].par;
        int fx = isson(x), fp = isson(p);
        if (!p) return;
        if (!z) N[z].s[fp] = x;
        else root = x;
        N[p].s[fx] = N[x].s[fx ^ 1];
        N[x].s[fx ^ 1] = p;
        N[N[p].s[fx]].par = p;
        N[p].par = x;
        N[x].par = z;
        update(p);
        update(x);
    }
    inline void splay(int x) {
        tot = 0;
        for (pcur = x; isson(pcur) != -1; pcur = N[pcur].par) stk[tot++] = pcur;
        for (stk[tot] = pcur; tot >= 0; --tot) pushdown(stk[tot]);
        for (; isson(x) != -1; rotate(x))
            if (isson(N[x].par) != -1) {
                if (isson(x) == isson(N[x].par)) rotate(N[x].par);
                else rotate(x);
            }
        update(x);
    }
    inline void swim(int k) {
        int x = root, dir = k > N[N[x].s[0]].sz;
        while (k != N[N[x].s[0]].sz + 1) {
            k -= dir ? (N[N[x].s[0]].sz + 1) : 0;
            x = N[x].s[dir];
        }
        splay(x);
    }
    inline void init() {
        root = 0;
        cur = 1;
        memset(nodelist, 0, sizeof(nodelist));
        root = newnode(0, NIL);
        N[root].s[1] = newnode(0, root);
        update(root);
    }
};

SplayTree spt;
#include <cstdio>
int n, q;
SPTTP arr[200007];
#define NN spt.nodelist
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", arr + i);
    spt.init();
    NN[NN[spt.root].s[1]].s[0] = spt.build_from_sequence(arr, 1, n, NN[spt.root].s[1]);
    spt.update(NN[spt.root].s[1]);
    spt.update(spt.root);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d %d %d", &b, &c, &d);
            spt.swim(c + 2);
            spt.swim(b);
            spt.add(NN[NN[spt.root].s[1]].s[0], d);
            spt.update(NN[spt.root].s[1]);
            spt.update(spt.root);
        } else {
            scanf("%d %d", &b, &c);
            spt.swim(c + 2);
            spt.swim(b);
            printf("%lld\n", NN[NN[NN[spt.root].s[1]].s[0]].sum);
        }
    }
    return 0;
}
