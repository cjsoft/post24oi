#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define CSZ 26
#define MXN 100007
struct node {
    node *pre, *c[26];
    int step, sz;
} buf[MXN << 1 | 1], *cur, *last, *root, _root;

void init() {
    root = &_root;
    root->pre = NULL;
    root->step = root->sz = 0;
    memset(root->c, 0, sizeof(root->c));
    cur = buf;
    last = root;
}

inline node *newnode(node *parent) {
    cur->step = parent->step + 1;
    memset(cur->c, 0, sizeof(cur->c));
    cur->pre = NULL;
    cur->sz = 0;
    return cur++;
}

void extend(int s) {
    node *p = last;
    node *np = newnode(last);
    np->sz = 1;
    for (; p && !p->c[s]; p = p->pre) p->c[s] = np;
    if (!p) { np->pre = root; }
    else {
        node *q = p->c[s];
        if (q->step == p->step + 1) { np->pre = q; }
        else {
            node *nq = newnode(p);
            memcpy(nq->c, q->c, sizeof(nq->c));
            nq->pre = q->pre;
            q->pre = np->pre = nq;
            for (; p && p->c[s] == q; p = p->pre) p->c[s] = nq;
        }
    }
    last = np;
}
char sss[MXN];
int l;
int b[MXN];
node *a[MXN << 1 | 1];
void topo() {
    int mxstep = 0;
    memset(b, 0, sizeof(b));
    memset(a, 0, sizeof(a));
    for (node *x = buf; x != cur; ++x) ++b[x->step], mxstep = max(mxstep, x->step);
    for (int i = 1; i <= mxstep; ++i) b[i] += b[i - 1];
    for (node *x = buf; x != cur; ++x) a[--b[x->step]] = x;
}
int T, k;
int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &k);
        memset(sss, 0, sizeof(sss));
        scanf("%s", sss);
        l = strlen(sss);
        for (int i = 0; i < l; ++i) extend(sss[i] - 'a');
        topo();
        for (int i = cur - buf - 1; i >= 0; --i) a[i]->pre->sz += a[i]->sz;
        int cnter = 0;
        for (node *x = buf; x != cur; ++x) {
            if (x->sz == k) {
                cnter += x->sz;
            }
        }
        printf("%d\n", cnter);
    }
    return 0;
}
