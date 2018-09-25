#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>


using namespace std;

int arr[100007];
int main() {
    int n;
    cin >> n;
    int blk = sqrt(n), ct = 1, i;
    for (i = 0; i + blk <= n; i += blk) {
        for (int j = i + blk - 1; j >= i; --j) {
            arr[j] = ct++;
        }
    }
    for (int j = n - 1; j >= i; --j)
        arr[j] = ct++;
    for (int i = 0; i < n; ++i)
        (i ? putchar(' ') : 1), cout << arr[i];
    putchar('\n');
    return 0;
}
