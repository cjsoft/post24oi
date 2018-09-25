#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


struct bivec {
    int x, y;
    bivec() : x(0), y(0) {}
    bivec(int x, int y) : x(x), y(y) {}
    bivec operator+(bivec b) {
        return bivec(x + b.x, y + b.y);
    }
    bivec operator-(bivec b) {
        return bivec(x - b.x, y - b.y);
    }
    int cross(bivec b) {
        return x * b.y - y * b.x;
    }
};
struct segment {
    bivec s, e;
    segment() : s(bivec()), e(bivec()) {}
    segment(bivec s, bivec e) : s(s), e(e) {}
    segment(int x1, int y1, int x2, int y2) : s(x1, y1), e(x2, y2) {}
    bool rejects(segment b) {
        return (
                max(s.x, e.x) >= min(b.s.x, b.e.x) &&
                max(b.s.x, b.e.x) >= min(s.x, e.x) &&
                max(s.y, e.y) >= min(b.s.y, b.e.y) &&
                max(b.s.y, b.e.y) >= min(s.y, e.y)
           );
    }
    bool strides(segment b) {
        return (s - b.s).cross(b.e - b.s) * (b.e - b.s).cross(e - b.s) >= 0;
    }
    bool intersects(segment b) {
        return strides(b) && b.strides(*this);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        if (x3 > x4) swap(x3, x4);
        if (y3 > y4) swap(y3, y4);
        segment seg(x1, y1, x2, y2);
        segment r1(x3, y3, x4, y3);
        segment r2(x3, y3, x3, y4);
        segment r3(x4, y3, x4, y4);
        segment r4(x3, y4, x4, y4);
        segment r5(x3, y4, x4, y3);
        segment r(x3, y3, x4, y4);
        swap(y3, y4);
        if (
                (seg.rejects(r5) && seg.intersects(r5)) ||
                (seg.rejects(r) && seg.intersects(r)) ||
                /* (seg.rejects(r3) && seg.intersects(r3)) || */
                /* (seg.rejects(r4) && seg.intersects(r4)) || */
                (
                 x3 <= x1 && x3 <= x2 && x1 <= x4 && x2 <= x4 &&
                 y3 <= y1 && y3 <= y2 && y1 <= y4 && y2 <= y4
                )
           ) puts("T");
        else puts("F");
    }
    return 0;
}
