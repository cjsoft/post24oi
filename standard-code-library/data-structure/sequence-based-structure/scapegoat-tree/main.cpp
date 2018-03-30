/**--------------------
 * Scapegoat Tree (no array edition)
 *
 * Time Consumption: \log{n} (average, per operatoion)
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/02/10
 * Suspended for not quite necessary
 * --------------------
 */

#include <cstring>
#include <cstdio>
#define SGMXN 200007
#define mid(l, r) (((l) + (r)) >> 1)
#define ls s[0]
#define rs s[1]
typedef long long SGTTP;
struct ScapegoatTree {
    const float alpha = 0.75;
    SGTTP datastore[SGMXN];
    struct node {
        node *s[2];
        char exists;
        SGTTP data;
        SGTTP tag;
        int sz;
    } NIL[SGMXN];
    node *stk[SGMXN];
    node *root;
    ScapegoatTree(): root(NULL), tot(0) {
        memset(NIL, 0, sizeof(NIL));
        for (int i = 1; i < SGMXN; ++i)
            stk[tot++] = NIL + i;
        NIL->ls = NIL->rs = NIL;
        NIL->data = NIL->tag = 0;
        NIL->sz = 0;
        NIL->exists = 0;
    }
    inline void add(node *x, SGTTP value) {
        x->data += value;
        x->tag += value;
    }
    inline void rev(node *x) {
        std::swap(x->ls, x->rs);
    }
    inline void pushdown(node *x) {
        if (x->tag) add(x->ls, x->tag), add(x->rs, x->tag), x->tag = 0;
    }
    inline void update(node *x) {
        x->sz = x->ls->sz + 1 + x->rs->sz;
    }
    inline node *newnode(SGTTP value) {
        --tot;
        stk[tot]->sz = 1;
        stk[tot]->ls = stk[tot]->rs = NIL;
        stk[tot]->data = value;
        stk[tot]->tag = 0;
        stk[tot]->exists = 1;
        return stk[tot];
    }
    inline void recycle(node *x) { stk[tot++] = x; }
    inline node *build_from_sequence(SGTTP seq[], int l, int r) {
        if (l > r) return NIL;
        if (l == r) return newnode(seq[l]);
        node *x = newnode(seq[mid(l, r)]);
        x->ls = build_from_sequence(seq, l, mid(l, r) - 1);
        x->rs = build_from_sequence(seq, mid(l, r) + 1, r);
        update(x);
        return x;
    }
};