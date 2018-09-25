#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int main() {
    long long n, k;
    cin >> n >> k;
    if (n >= k) {
        cout << max((k / 2) - ((k & 1) ? 0 : 1), 0LL) << endl;
    } else {
        cout << max(n - k / 2 - ((k & 1) ? 0 : 1), 0LL) << endl;
    }
    return 0;
}