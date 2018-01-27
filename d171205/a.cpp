#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
int n;
struct pos {
    int x, y;
    pos(int a, int b) {
        x = a;
        y = b;
    }
    pos() {
        x = y = 0;
    }
    pos operator-(const pos b) {
        return pos(x - b.x, y - b.y);
    }
    pos operator+(const pos b) {
        return pos(x + b.x, y + b.y);
    }
} stt, arr[100007];
stack <pos> tubao;
stack <pos> stp;
int cmp(pos a, pos b) {
    return a.x * b.y - b.x * a.y;
}
double Abs(pos x) {
    return sqrt(double(x.x * x.x + x.y * x.y));
}
bool cpp(pos a, pos b) {
    int delt = cmp(a - stt, b - stt);
    if (delt > 0) {
        return true;
    } else if (delt == 0) {
        pos q = a - stt;
        pos w = b - stt;
        return q.x * q.x + q.y * q.y < w.x * w.x + w.y * w.y;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    int ppp = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        if (arr[ppp].y < arr[i].y) {
            ppp = i;
        } else if (arr[ppp].y == arr[i].y) {
            if (arr[ppp].x > arr[i].x) {
                ppp = i;
            }
        }
    }
    swap(arr[ppp], arr[0]);
    stt = arr[0];
    sort(arr + 1, arr + n, cpp);
    for (int i = 2; i < n; ++i) {
        if (cmp(arr[i] - stt, arr[i - 1] - stt) == 0) {
            // printf("    %d %d %d %d\n", arr[4].x, arr[4].y, arr[i - 1].x, arr[i - 1].y);
            std::swap(arr[i - 1], arr[n - 1]);
            --n;
            // puts("ss");
        }
    }
    sort(arr + 1, arr + n, cpp);
    tubao.push(stt);
    stp.push(stt);
    for (int i = 1; i < n; ++i) {
        pos qwe, asd;
        qwe = arr[i] - stp.top();
        asd = tubao.top() - stp.top();
        int dir = cmp(qwe, asd);
        while (dir > 0 || (dir == 0 && (qwe.x * asd.x + qwe.y * asd.y < 0))) {
            stp.pop();
            tubao.pop();
            dir = cmp(arr[i] - stp.top(), tubao.top() - stp.top());
        }
        qwe = arr[i] - stp.top();
        asd = tubao.top() - stp.top();
        stp.push(tubao.top());
        tubao.push(arr[i]);
    }
    double ans = 0;
    while (!tubao.empty()) {
        // printf("   %d %d\n", tubao.top().x, tubao.top().y);
        ans += Abs(tubao.top() - stt);
        stt = tubao.top();
        tubao.pop();
    }
    printf("%.1lf\n", ans);
    return 0;
}