#include <bits/stdc++.h>
#define abs(a) (((-(a)) < 0) ? (-(a)) : (a))
#define MOD 256
using namespace std;

template<typename T>
inline bool checkmin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    } else return false;
}
template<typename T>
inline bool checkmax(T &a, T b) {
    if (b > a) {
        a = b;
        return true;
    } else return false;
}

inline int getint() {
    register int ch;
    register int f, rtn;
    f = 1; rtn = 0;
    for (ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
    for (; isdigit(ch); ch = getchar()) rtn = rtn * 10 + ch - '0';
    return rtn * f;
}
struct operation {
    char op;
    int p1, p2;
    bool vis[271];
    operation() {}
    void load() {
        char tmp[5];
        int a, b;
        scanf("%s %d", tmp, &a);
        if (tmp[1] != 'd') scanf("%d", &b);
        op = tmp[1];
        p1 = a;
        p2 = b;
    }
} ops[10007];
void calc(unsigned char &r, int &i, int opid) {
    if (ops[opid].op == 'd') {
        r += ops[opid].p1;
        i++;
    } else if (ops[opid].op == 'e') {
        if (r == ops[opid].p1) i = ops[opid].p2;
        else i++;
    } else if (ops[opid].op == 'n') {
        if (r != ops[opid].p1) i = ops[opid].p2;
        else i++;
    } else if (ops[opid].op == 'l') {
        if (r < ops[opid].p1) i = ops[opid].p2;
        else i++;
    } else if (ops[opid].op == 'g') {
        if (r > ops[opid].p1) i = ops[opid].p2;
        else i++;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int i;
        int n;
        scanf("%d", &n);
        memset(ops, 0, sizeof(ops));
        for (i = 1; i <= n; ++i) {
            ops[i].load();
        }
        unsigned char r = 0;
        for (i = 1; i <= n && !ops[i].vis[r];) {
            ops[i].vis[r] = true;
            calc(r, i, i);
        }
        if (i == n + 1) puts("Yes");
        else puts("No");
    }
    return 0;
}