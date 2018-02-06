/**--------------------
 * Splay Tree (array editipon)
 *
 * Time Consumption: \log{n} (average, per operatoion)
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/02/02
 * --------------------
 */

#define NIL 0
#define N nodelist
typedef int SPTTP;
struct SplayTree {
    struct node {
        int ls, rs;
        int par;
        int sz;
        SPTTP data;
    } nodelist[SPTMXN];
    int root, cur;
    SplayTree(): root(0), nil(0), cur(1) {
        memset(nodelist, 0, sizeof(nodelist));
    }
    inline int newnode(SPTTP value, int parent) {
        N[cur].data = value;
        N[cur].sz = 1;
        N[cur].ls = N[cur].rs = 0;
        N[cur].par = parent;
        return cur++;
    }
    
};
