#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (1 << (a + b + c + d)) - (((1 << d) - d - 1) * (1 << (a + b + c)) + d * ((1 << b) - 1) * (1 << (a + c)) + ((1 << b) - 1 - b) * ((1 << c) - 1) * (1 << a));

}