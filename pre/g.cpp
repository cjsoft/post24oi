#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MXN 100007
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int T;
int n, t;
ull q[MXN], x[MXN];
ull tmpp[100];
ull huancun[1000007];
ull find_min_num(int begin, int end);
ull cal(int pos) {
    if (huancun[pos] != (ull)-1LL) return huancun[pos];
    huancun[pos] = 0;
    for (int i = 1; i <= n; ++i) {
        ull a = x[i], b = pos;
        if (a < b) swap(a, b);
        huancun[pos] += q[i] * (a - b);
    }
    return huancun[pos];
}
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(huancun, 0xff, sizeof(huancun));
        scanf("%d %d", &n, &t);
        ull pos = 0;
        ull tmp = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%llu %llu", q + i, x + i);
            switch (t) {
                case 3:
                q[i] = q[i] * q[i] * q[i];
                break;
                case 4:
                q[i] = q[i] * q[i];
                case 2:
                q[i] = q[i] * q[i];
                case 1:;
            }
            // tmp += q[i];
            // pos += q[i] * x[i];
        }
        
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 0; j < 100; ++j) {
        //         ull a = x[i], b = j;
        //         if (a < b) swap(a, b);
        //         tmpp[j] += q[i] * (a - b);
        //     }
        // }
        // for (int j = 0; j < 100; ++j) {
        //     cout << j << '-' << tmpp[j] << endl;
        // }
        cout << find_min_num(0, 1000001) << endl;
        // cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << endl;
        // cout << min(tmp1, min(tmp2, tmp3)) << endl;
    }
    return 0;
}

ull find_min_num(int begin, int end)  
{  
    int mid, midmid, mmm;  
    while (begin < end) {  
        if (begin + 1 == end) {  
            mmm = cal(begin) < cal(end) ? cal(begin) : cal(end);  
            return mmm;  
        }  
        mid = (begin + end) / 2;  
        if (mid + 1 == end) {  
            midmid = (mid + end) / 2 + 1;  
        } else {  
            midmid = (mid + end) / 2;  
        }  
           
        if (midmid == end) {  
            mmm = cal(begin) < cal(mid) ? cal(begin) : cal(mid);  
            mmm = mmm < cal(end) ? mmm : cal(end);  
            return mmm;  
        }  
   
        if (cal(mid) <= cal(midmid))   
            end = midmid;  
        else  
            begin = mid;  
    }  
   
    return cal(mid);  
}