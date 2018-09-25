#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1007

using namespace std;

int arr[N], tmp[N];
int f[N], g[N];
int n;

int lis() {
    int rtn = 0;
    fill_n(f, N, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                f[j] = max(f[j], f[i] + 1);
                rtn = max(rtn, f[j]);
            }
        }
    }
    return rtn;
}
int lds() {
    int rtn = 0;
    fill_n(f, N, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[i]) {
                f[j] = max(f[j], f[i] + 1);
                rtn = max(rtn, f[j]);
            }
        }
    }
    return rtn;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        arr[i] = tmp[i] = i + 1;
    }
    int TMP = lis() + lds();
    while (next_permutation(arr, arr + n)) {
        int s = lis() + lds();
        if (s < TMP) {
            TMP = s;
            for (int i = 0; i < n; ++i) tmp[i] = arr[i];
        }
    }
    for (int i = 0; i < n; ++i) cout << tmp[i] << ' ';
}
