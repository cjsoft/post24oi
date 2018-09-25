#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define EPS 1e-7
using namespace std;
const double G = 9.8;
int a, b;
double X, Y;
struct vec {
    double x, y;
    vec() : x(0), y(0) {}
    vec(double x, double y) : x(x), y(y) {}
    vec collision() {
        return vec(
                ((b * b - a * a) * x + 2 * a * b * y) / (a * a + b * b),
                ((a * a - b * b) * y + 2 * a * b * x) / (a * a + b * b)
                );
    }
    vec rev() {
        return vec(-x, -y);
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> X >> Y;
        vec speed(0, 0);
        double t = sqrt((2 * Y + 2 * b * X / a) / G);
        /* cout << t << endl; */
        speed.y = -G * t;
        speed = speed.collision().rev();
        /* cout << X << ' ' << speed.x << ' ' << speed.y << endl; */
        /* cout << speed.x << ' ' << speed.y << endl; */
        int cnt = 0;
        while (X < EPS) {
            ++cnt;
            t = 2 * b * speed.x / a / G + 2 * speed.y / G;
            X += speed.x * t;
            /* Y -= speed.y * t; */
            speed.y -= G * t;
            speed = speed.collision().rev();
            /* cout << X << ' ' << speed.x << ' ' << speed.y << endl; */
        }
        cout << cnt << endl;
    }
}
