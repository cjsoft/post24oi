#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define MXN 100007
using namespace std;
typedef long long ll;
int n;


struct pos {
    int x, y;
    int id;
    pos operator+(pos b) {
        pos c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }
    pos operator-(pos b) {
        pos c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }
} raw[MXN], stk[MXN];
int top = 0;
ll cross(pos a, pos b) { return a.x * b.y - a.y * b.x; }
ll dot(pos a, pos b) { return a.x * b.x + a.y * b.y; }
int suc(int x) { return (x + 1) % top; }
ll norm2(pos a) { return a.x * a.x + a.y * a.y; }
bool cmp(pos a, pos b) {
    pos x = a - raw[0], y = b - raw[0];
    int w = cross(x, y);
    if (w == 0) return norm2(x) > norm2(y);
    return w > 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        top = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &raw[i].x, &raw[i].y);
            raw[i].id = i + 1;
        }
        int p = 0;
        for (int i = 1; i < n; ++i) {
            if (raw[i].y < raw[p].y) p = i;
            else if (raw[i].y == raw[p].y) {
                if (raw[i].x < raw[p].x) p = i;
            }
        }
        if (p) swap(raw[p], raw[0]);
        sort(raw + 1, raw + n, cmp);
        for (int i = 2; i < n; ++i) {
            /* if (cross(raw[i] - raw[0], raw[i - 1] - raw[0]) == 0) swap(raw[i - 1], raw[n - 1]), --n; */
        }
        sort(raw + 1, raw + n, cmp);
        stk[top++] = raw[0];
        stk[top++] = raw[1];
        for (int i = 2; i < n; ++i) {
            while (cross(stk[top - 1] - stk[top - 2], raw[i] - stk[top - 1]) < 0) --top;
            while (cross(stk[top - 1] - stk[top - 2], raw[i] - stk[top - 1]) == 0 && stk[top - 1].id > raw[i].id) --top;
            stk[top++] = raw[i];
        }
        printf("%d", stk[0].id);
        for (int i = top - 1; i > 0; --i) printf(" %d", stk[i].id);
        putchar('\n');
    }
    return 0;
}
