#include <cstdio>
#include <iostream>
#include <cstring>
#define MXL 107

using namespace std;

template <typename T>
inline void checkmin(T &a, T b) {
    if (b < a) a = b;
}
inline void checkmax(T &a, T b) {
    if (b > a) a = b;
}

struct pp {
    int l, r;
    pp(int x = 0) : l(x), r(x) {}
    pp(int l, int r) : l(l), r(r) {}
    pp operator+(pp b) {
        return pp(l + b.l, r + b.r);
    }
    pp operator-(pp b) {
        return pp(l - b.r, r - b.l);
    }
    pp operator*(pp b) {
        pp tmp;
        int a = l * b.l,
            b = l * b.r,
            c = r * b.l,
            d = r * b.r;
        tmp.l = tmp.r = a;
        checkmin(tmp.l, b);
        checkmin(tmp.l, c);
        checkmin(tmp.l, d);
        checkmax(tmp.r, b);
        checkmax(tmp.r, c);
        checkmax(tmp.r, d);
        return tmp;
    }
    pp d(pp b) {
        return pp(l, r * b.r);
    }
};

char input[MXL];

int main() {
    while (~scanf("%s", input)) {
        pp ans = parse(input);
        printf("%d %d\n", ans.l, ans.r);
    }
}