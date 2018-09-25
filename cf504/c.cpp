#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

string s, opt;
int main() {
    int n, k, x = 0;
    cin >> n >> k;
    cin >> s;
    int j = 0, i;
    for (i = 0; i < n, j < k / 2; ++i) {
        if (s[i] == '(') ++j;
    }
    cout << s.substr(0, i);
    for (j = 0; j < k - i; ++j)
        putchar(')');
    putchar('\n');
}