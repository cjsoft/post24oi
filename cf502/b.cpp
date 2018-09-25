#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100007
using namespace std;


char A[N], B[N];
long long cnt[2][2];

int main() {
    memset(cnt, 0, sizeof(cnt));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    int n;
    cin >> n;
    cin >> A >> B;
    for (int i = 0; i < n; ++i) {
        if (A[i] == '0' && B[i] == '1') cnt[0][1]++;
        if (A[i] == '1' && B[i] == '1') cnt[1][1]++;
        if (A[i] == '1' && B[i] == '0') cnt[1][0]++;
        if (A[i] == '0' && B[i] == '0') cnt[0][0]++;
    }
    cout << cnt[0][0] * cnt[1][1] + cnt[0][0] * cnt[1][0] + cnt[1][0] * cnt[0][1] << endl;
}
