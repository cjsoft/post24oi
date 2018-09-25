#include <random>
#include <iterator>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 2000
#define CN 47
using namespace std;
vector<int> vc[N + 7], vr[N + 7];

bool vis[N + 7];
int globalcnt = 0;
int mp[N + 7][N + 7];
int raw[N + 7], fin[N + 7];
int main() {
    srand(1999);
    for (int i = 1; i <= N; ++i) {
        raw[i] = i;
        fin[i] = i;
    }
    for (int i = 1; i <= CN; ++i) {
        mp[i][1] = 1;
        vc[1].push_back(i);
        vr[i].push_back(1);
    }
    for (int i = 2; i <= N; ++i) {
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        reverse(fin + 1, fin + 1 + N);
        /* sample(raw + 1, raw + 1 + N, fin + 1, fin + 1 + N); */
        for (int j = 1; j <= N; ++j) {
            if (vr[fin[j]].size() >= CN) continue;
            if (!vis[fin[j]]) {
                ++cnt;
                ++globalcnt;
                mp[fin[j]][i] = 1;
                for (auto k : vr[fin[j]]) {
                    for (auto l : vc[k]) {
                        vis[l] = 1;
                    }
                }
                vr[fin[j]].push_back(i);
                vc[i].push_back(fin[j]);
                if (cnt >= CN) break;
            }
        }
        printf("%d\n", cnt);
    }
    printf("%d\n", globalcnt);
    return 0;
}

