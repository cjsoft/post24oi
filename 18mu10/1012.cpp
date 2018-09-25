#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 605;
const int M = 200005;
const int INF = 0x3f3f3f3f;

int n, m, K, W, S, T, ans, cnt;
int s[N], t[N], op[N], w[N];
int head[N], dis[N], path[N];
int from[M], List[M], Next[M], flow[M], cost[M];
bool vis[N];

inline int read() {
    int a = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = a * 10 + c - '0';
        c = getchar();
    }
    return a * f;
}

inline void ins(int x, int y, int z, int w) {
    Next[++cnt] = head[x];
    head[x] = cnt;
    from[cnt] = x;
    List[cnt] = y;
    flow[cnt] = z;
    cost[cnt] = w;
}

inline void insert(int x, int y, int z, int w) {
    ins(x, y, z, w); ins(y, x, 0, -w);
}

inline bool spfa() {
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    dis[S] = 0; q.push(S); vis[S] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = Next[i]) {
            if (flow[i] && dis[List[i]] < dis[x] + cost[i]) {
                dis[List[i]] = dis[x] + cost[i];
                path[List[i]] = i;
                if (!vis[List[i]]) {
                    vis[List[i]] = true;
                    q.push(List[i]);
                }
            }
        }
        vis[x] = false;
    }
    return dis[T] != -1;
}

inline void mcf() {
    int x = INF;
    for (int i = path[T]; i; i = path[from[i]]) x = min(x, flow[i]);
    for (int i = path[T]; i; i = path[from[i]]) {
        flow[i] -= x; flow[i ^ 1] += x; ans += x * cost[i];
    }
}

inline void init() {
    cnt = 1; ans = 0;
    memset(head, 0, sizeof(head));
}

int main() {
    int testcase = read();
    while (testcase--) {
        n = read(); m = read(); K = read(); W = read();
        init();
        S = 0; T = K + m + m + 1;
        for (int i = 1; i <= m; i++) {
            s[i] = read(); t[i] = read(); w[i] = read(); op[i] = read();
        }
        for (int i = 1; i <= m; i++)
            insert(i + K, i + K + m, 1, w[i]);
        for (int i = 1; i <= m; i++)
            for (int j = i + 1; j <= m; j++) {
                int tmp = (op[i] == op[j]) ? -W : 0;
                if (t[i] <= s[j]) {
                    insert(i + K + m, j + K, 1, tmp);
                }
                if (t[j] <= s[i]) {
                    insert(j + K + m, i + K, 1, tmp);
                }
            }
        for (int i = 1; i <= K; i++)
            for (int j = 1; j <= m; j++) 
                insert(i, j + K, 1, 0);
        for (int i = 1; i <= K; i++)
            insert(S, i, 1, 0);
        for (int i = 1; i <= m; i++)
            insert(i + K + m, T, 1, 0);
        while (spfa()) mcf();
        cout << ans << endl;
    }
}
