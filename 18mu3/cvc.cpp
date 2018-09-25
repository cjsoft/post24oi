#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

inline int read() {
    register int a = 0, f = 1;
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

vector<int > v;
vector<vector<int > > pre[7];
vector<int > influ[7][60];
bool vis[20];
int id[15][15];

void dfs(int n, int num, int lim) {
    if(num > 6 || lim > n) {
        return;
    }
    pre[num].push_back(v);
    for(register int i = lim;i <= n;i++) {
        if(vis[i]) continue;
        for(register int j = i+1; j <= n; j++) {
            if(!vis[j]) {
                vis[i] = vis[j] = 1;
                v.push_back(id[i][j]);
                dfs(n, num+1, i+1);
                vis[i] = vis[j] = 0;
                v.pop_back();
            }
        }
    }
}

int visnum[7][5000];
long long prenum[7][5000];

void init(int n) {
//    double tt = clock();
    register int cnt = 0;
    for(register int i = 1; i <= n; i++) {
        for(register int j = i+1; j <= n; j++) {
            id[i][j] = ++cnt;
        }
    }
    v.clear();
    for(register int i = 1;i <= n/2; i++) {
        pre[i].clear();
        for(register int j = 0; j <= cnt; j++) {
            influ[i][j].clear();
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(n, 0, 1);
    for(register int i = 1; i <= n/2; i++) {
        //cout<<"num "<<i<<", count = "<< pre[i].size() << endl;
        for(register int j = 0 ; j < pre[i].size(); j++) {
            for(register int k = 0; k < pre[i][j].size() ; k++) {
            //    printf("(%d, %d) ", pre[i][j][k].first, pre[i][j][k].second); 
                influ[i][pre[i][j][k]].push_back(j);
            }
        //    puts("");
        }
    }
    for(register int i = 2; i<= n/2; i++) {
        for(register int j = 0 ; j < pre[i].size(); j++) {
            visnum[i][j] = pre[i][j].size();
            prenum[i][j] = 1;
        }
    }
//    cout<<clock()-tt<<endl;
}
long long num[50];
long long ans[10];

inline void print(register int x)
{
     if(x>9) print(x/10);
     putchar(x%10+'0');
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int n = read(), m = read(), sum = 0;
        //cin >> n;
        init(n);
        memset(num, 0, sizeof(num));
        memset(ans, 0, sizeof(ans));
//        double ct = clock();
        
        register int co=0;
        for(register int i = 1, x, y; i <= m; i++) {
            char ch[4];
//            cin >> ch >> x >> y;
            scanf("%s%d%d", ch, &x, &y);
            if(x > y) {
                swap(x, y);
            }
            register int eid = id[x][y];
            register int t = -1;
            if(ch[0] == '+') {
                t = 1;
                sum++;
            }
            else {
                sum--;
            }
            //printf("%d ",sum);
            print(sum); putchar(' ');
            for(register int k = 2;k <= n/2; k++) {    
                    //co = max(co, (int)influ[k][eid].size());
                register int szz = influ[k][eid].size();
                for(register int j = 0; j < szz; j++) {
                    register int jid = influ[k][eid][j];
                    
                    if(visnum[k][jid]==0)
                        ans[k] = (ans[k] - prenum[k][jid]);
                        
                    if(num[eid] == 0 && t==1){
                        visnum[k][jid]--;
                    }
                    else if(num[eid]==1 && t==-1){
                        visnum[k][jid]++;
                    }
                    else {
                        prenum[k][jid] = prenum[k][jid]/num[eid]*(num[eid]+t);
                    }
                    
                    if(visnum[k][jid]==0)
                        ans[k] = (ans[k] + prenum[k][jid]) ;
                    
                    
                //    ans[k] = (ans[k] + prenum[k][jid]*(visnum[k][jid]==0)) % mod;
                    
//                    #define tv pre[k][jid]
//                    long long ret = 1;
//                    for(int p = 0; p < tv.size() && ret != 0; p++) {
//                        int pid = tv[p];
//                        if(eid == pid) continue;
//                        ret = (ret * num[pid]) % mod;
//                        //co++;
//                    }
//                    ans[k] = (ans[k] + t*ret)%mod;
                }
            //    printf("%lld ", (ans[k] % mod + mod) % mod);
                print((ans[k] % mod + mod) % mod);
                putchar(' ');
            }
            puts("");
            num[eid] += t;
        }
        //cout<<clock()-ct<<" " << co<<endl;
    }
    return 0;
}
/*
2
4 8    
+ 1 2
+ 3 4
+ 1 3
+ 2 4
- 1 2
- 3 4
+ 1 2
+ 3 4

6 30
+ 1 4
+ 2 4
+ 3 5
+ 1 2
- 2 4
+ 1 5
- 3 5

*/
