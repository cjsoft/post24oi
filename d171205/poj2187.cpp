#include <iostream>
#include <cstdio>
#include <algorithm>
#define MXN 50007
using namespace std;
int n, top, p, resu;
struct pos {
    int x, y;
    pos() { x = y = 0; }
    pos(int _x, int _y) { x = _x; y = _y; }
    pos operator+(pos b) { return pos(x + b.x, y + b.y); }
    pos operator-(pos b) { return pos(x - b.x, y - b.y); }
} raw[MXN], stk[MXN];
int cross(pos a, pos b) { return a.x * b.y - a.y * b.x; }
int norm2(pos x) { return x.x * x.x + x.y * x.y; }
int suc(int x) { return (x + 1) % top; }
bool cmp(pos a, pos b) {
    int w = cross(a - raw[0], b - raw[0]);
    if (w == 0) return norm2(a - raw[0]) < norm2(b - raw[0]);
    return w > 0;
}
int main() {
    while (~scanf("%d", &n)) {
        top = resu = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &raw[i].x, &raw[i].y);
        p = 0;
        for (int i = 1; i < n; ++i)
            if (raw[i].y == raw[p].y && raw[i].x < raw[p].x)
                p = i;
            else if (raw[i].y < raw[p].y) p = i;
        swap(raw[0], raw[p]);
        sort(raw + 1, raw + n, cmp);
        for (int i = 2; i < n; ++i)
            if (cross(raw[i] - raw[0], raw[i - 1] - raw[0]) == 0)
                swap(raw[i - 1], raw[n - 1]), --n;
        sort(raw + 1, raw + n, cmp);
        stk[top++] = raw[0];
        stk[top++] = raw[1];
        for (int i = 2; i < n; ++i) {
            for (; top > 1 && cross(stk[top - 1] - stk[top - 2], raw[i] - stk[top - 1]) <= 0; --top);
            stk[top++] = raw[i];
        }
        for (int i = 0, q = 1; i < top; ++i) {
            for (; cross(stk[suc(i)] - stk[i], stk[q] - stk[i]) < cross(stk[suc(i)] - stk[i], stk[suc(q)] - stk[i]); q = suc(q));
            resu = max(resu, max(norm2(stk[q] - stk[i]), norm2(stk[q] - stk[suc(i)])));
        }
        printf("%d\n", resu);
    }
}