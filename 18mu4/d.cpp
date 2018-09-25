#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[107], b[107];
int n, m, T;
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        sort(b, b + n);
        long long tmp = 1;
        for (int i = 0; i < n; ++i)
        {
            if (tmp * b[i] + tmp > m) {
                cout << i << endl;
                goto ED;
            }
            tmp *= b[i] + 1;
        }
        cout << n << endl;
ED:;
    }
}
