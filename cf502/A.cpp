#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct st {
    int sc, id;
    bool operator<(const st b) const {
        if (sc == b.sc) return id < b.id;
        return sc > b.sc;
    }
} arr[1007];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i].id = i;
        arr[i].sc = a + b + c + d;
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; ++i) {
        if (arr[i].id == 1) {
            cout << i << endl;
            return 0;
        }
    }
}
