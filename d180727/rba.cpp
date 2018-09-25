#include <cstring>
#include <iostream>
#include <cstdio>
#define N 100007

#define SPTMXN 200007

#define mid(l, r) (((l) + (r)) >> 1)

using namespace std;
struct SPTTP {
    int id;
    int data;
    SPTTP() {
        id = data = 0;
    }
    SPTTP(int data, int id) : data(data), id(id) {}
    bool operator<(const SPTTP &b) const {
        if (data == b.data) {
            return id < b.id;
        } else return data < b.data;
    }
    bool operator>(const SPTTP &b) const {
        return b < *this;
    }
    bool operator==(const SPTTP &b) const {
        return (data == b.data && id == b.id);
    }
};
struct SplayTree {
    struct node {
        node *s[2];
        node *parent;
        int sz;
        char isrev;
        SPTTP data;
        node *minson;
    } NIL[SPTMXN];
    node *root, *cur;
    SplayTree(): root(NULL), cur(NIL + 1) {
        memset(NIL, 0, sizeof(NIL));
        NIL->parent = NIL->s[0] = NIL->s[1] = NIL;
        NIL->data.data = 0x3f3f3f3f;
        NIL->data.id = 0;
        NIL->minson = NIL;
        NIL->sz = 0;
    }
    inline node *newnode(SPTTP value, node *p) {
        cur->data = value;
        cur->minson = cur;
        cur->sz = 1;
        cur->isrev = 0;
        cur->parent = p;
        cur->s[0] = cur->s[1] = NIL;
        return cur++;
    }
    inline void rev(node *x) {
        if (x != NIL) {
            std::swap(x->s[0], x->s[1]);
            x->isrev ^= 1;
        }
    }
    inline void pushdown(node *x) {
        if (x == NIL) return;
        if (x->isrev) rev(x->s[0]), rev(x->s[1]), x->isrev = 0;
    }
    inline void update(node *x) {
        pushdown(x->s[0]);
        pushdown(x->s[1]);
        x->sz = x->s[0]->sz + 1 + x->s[1]->sz;
        int d = x->s[0]->minson->data > x->s[1]->minson->data;
        x->minson = x->s[d]->minson;
        if (x->data < x->minson->data) x->minson = x;
        if (x->data == x->minson->data && d == 1) x->minson = x;
    }
    inline int sonid(node *x) {
        if (x->parent == NIL) return -1;
        if (x->parent->s[1] == x) return 1;
        if (x->parent->s[0] == x) return 0;
        else return -1;
    }
    inline void rotate(node *x) {
        /* if (x == root || x == NIL) return; */
        /* node *p = x->parent, *z = p->parent; */
        /* int fx = sonid(x), fp = sonid(p); */
        /* if (root == p) root = x; */
        /* else z->s[fp] = x; */
        /* p->s[fx] = x->s[fx ^ 1]; */
        /* x->s[fx ^ 1] = p; */
        /* x->parent = z; */
        /* p->s[fx]->parent = p; */
        /* p->parent = x; */
        /* update(p); */
        /* update(x); */
        node *p = x->parent, *z = p->parent;
        int fx = sonid(x), fp = sonid(p);
        if (fx == -1) return;
        if (fp == -1) root = x;
        else z->s[fp] = x;
        p->parent = x;
        p->s[fx] = x->s[fx ^ 1];
        x->s[fx ^ 1] = p;
        if (p->s[fx] != NIL) p->s[fx]->parent = p;
        p->parent = x;
        x->parent = z;
        update(p);
    }
    node *stk[SPTMXN], *pcur; int tot;
    void splay(node *x, node *y) {
        tot = 0;
        for (pcur = x; sonid(pcur) != -1 && pcur != NIL; pcur = pcur->parent) stk[tot++] = pcur;
        for (stk[tot] = pcur; tot >= 0; --tot) pushdown(stk[tot]);
        for (; sonid(x) != -1 && x->parent != y; rotate(x)) 
            if (sonid(x->parent) != -1 && x->parent->parent != y) {
                if (sonid(x) == sonid(x->parent)) rotate(x->parent);
                else rotate(x);
            }
        update(x);
    }
    void dfs(node *p) {
        if (!p || p == NIL) return;
        dfs(p->s[0]);
        cout << " " << (p->data.data);
        dfs(p->s[1]);
    }
    void swim(int k, node *y) {
        pushdown(root);
        node *x = root; int dir = k > (x->s[0]->sz + 1);
        for (; k != x->s[0]->sz + 1; dir = k > (x->s[0]->sz + 1)) {
            if (dir) k-= x->s[0]->sz + 1;
            x = x->s[dir];
            pushdown(x);
        }
        splay(x, y);
    }
    node *build_from_sequence(SPTTP seq[], int l, int r, node *p) {
        if (l > r) return NIL;
        if (l == r) return newnode(seq[l], p);
        node *x = newnode(seq[mid(l, r)], p);
        x->s[0] = build_from_sequence(seq, l, mid(l, r) - 1, x);
        x->s[1] = build_from_sequence(seq, mid(l, r) + 1, r, x);
        update(x);
        return x;
    }
    inline void init() {
        cur = NIL + 1;
        memset(NIL, 0, sizeof(NIL));
        NIL->parent = NIL->s[0] = NIL->s[1] = NIL;
        NIL->data.data = 0x3f3f3f3f;
        NIL->minson = NIL;
        NIL->isrev = 0;
        NIL->sz = 0;
        root = newnode(SPTTP(0x3f3f3f3f, -1), NIL);
        root->s[1] = newnode(SPTTP(0x3f3f3f3f, 0x3f3f3f3f), root);
        update(root);
    }
};

SPTTP seq[N];
int n;
SplayTree spt;
int main() {
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &seq[i].data);
            seq[i].id = i + 1;
        }
        spt.init();
        spt.root->s[1]->s[0] = spt.build_from_sequence(seq, 0, n - 1, spt.root->s[1]);
        spt.update(spt.root->s[1]);
        spt.update(spt.root);
        for (int i = 1; i <= n; ++i) {
            spt.swim(i, spt.NIL);
            /* spt.dfs(spt.root); */
            spt.splay(spt.root->s[1]->minson, spt.root);
            
            /* printf("  %d\n", spt.root->s[1]->data.data); */
            /* spt.dfs(spt.root); */
            /* putchar('\n'); */
            spt.swim(spt.root->s[0]->sz + 1 + spt.root->s[1]->s[0]->sz + 2, spt.root);
            /* printf("  %d\n", spt.root->s[1]->data.data); */
            /* spt.dfs(spt.root); */
            /* putchar('\n'); */
            int ans = spt.root->s[1]->s[0]->sz + i - 1;
            spt.rev(spt.root->s[1]->s[0]);
            printf("%d ", ans);
        }
        putchar('\n');
            
    }

}
