#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MXN 107

using namespace std;
typedef long long ll;
int a[MXN];
int sum = 0, avg;
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        sum += a[i];
    }
    avg = sum / n;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < avg) {
            a[i + 1] -= avg - a[i];
            ++cnt;
        } else if (a[i] > avg) {
            a[i + 1] += a[i] - avg;
            ++cnt;
        }
    }
    printf("%d\n", cnt);
}