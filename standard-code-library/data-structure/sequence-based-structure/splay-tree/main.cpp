/**--------------------
 * Splay Tree (no array edition)
 *
 * Time Consumption: \log{n} (average, per operatoion)
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/02/02
 * --------------------
 */
#include <cstring>
#include <iostream>
#include <cstdio>


#define SPTMXN 200007

#define mid(l, r) (((l) + (r)) >> 1)

typedef long long SPTTP;
struct SplayTree {
    struct node {
        node *s[2];
        node *parent;
        int sz;
        char isrev;
        SPTTP tag;
        SPTTP data;
        SPTTP sum;
    } NIL[SPTMXN];
    node *root, *cur;
    SplayTree(): root(NULL), cur(NIL + 1) {
        memset(NIL, 0, sizeof(NIL));
        NIL->parent = NIL->s[0] = NIL->s[1] = NIL;
        NIL->data = NIL->sum = NIL->tag = 0;
        NIL->sz = 0;
    }
    inline node *newnode(SPTTP value, node *p) {
        cur->data = value;
        cur->tag = 0;
        cur->sum = value;
        cur->sz = 1;
        cur->isrev = 0;
        cur->parent = p;
        cur->s[0] = cur->s[1] = NIL;
        return cur++;
    }
    inline void add(node *x, SPTTP value) {
        if (x != NIL) {
            x->tag += value;
            x->data += value;
            x->sum += value * x->sz;
        }
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
        if (x->tag) add(x->s[0], x->tag), add(x->s[1], x->tag), x->tag = 0;
    }
    inline void update(node *x) {
        pushdown(x->s[0]);
        pushdown(x->s[1]);
        x->sz = x->s[0]->sz + 1 + x->s[1]->sz;
        x->sum = x->s[0]->sum + x->data + x->s[1]->sum;
    }
    inline int sonid(node *x) {
        if (x->parent->s[1] == x) return 1;
        if (x->parent->s[0] == x) return 0;
        else return -1;
    }
    inline void rotate(node *x) {
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
    void swim(int k, node *y) {
        pushdown(root);
        node *x = root; int dir = k > (x->s[0]->sz + 1);
        for (; k != x->s[0]->sz + 1; dir = k > (x->s[0]->sz + 1)) {
            if (dir) k-= x->s[0]->sz + 1;
            x = x->s[dir];
            pushdown(root);
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
        NIL->data = NIL->sum = NIL->tag = 0;
        NIL->isrev = 0;
        NIL->sz = 0;
        root = newnode(0, NIL);
        root->s[1] = newnode(0, root);
        update(root);
    }
};
