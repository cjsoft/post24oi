#include <bits/stdc++.h>

using namespace std;

int n;
char input[11];
map<string, int> mp;

int main() {
    while (~scanf("%d\n", &n)) {
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            set<string> sst;
            scanf("%s", input);
            int len = strlen(input);
            int pp = 1 << len;
            for (int s = 1; s < pp; ++s) {
                string tmp("");
                int tmplen = 0;
                for (int j = 0; j < len; ++j) {
                    if ((1 << j) & s) {
                        tmplen++;
                        tmp += input[j];
                    }
                }
                sst.insert(tmp);
                for (int j = 1; j < tmplen; ++j) {
                    tmp = tmp.substr(tmplen - 1) + tmp.substr(0, tmplen - 1);
                    sst.insert(tmp);
                }
            }
            for (set<string>::iterator it = sst.begin(); it != sst.end(); it++) 
                mp[*it]++;
        }
        bool flag = false;
        string resu("");
        for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) 
            if (it->second == n) {
                if ((resu.length() < ((it->first).length())) || (resu.length() == (it->first).length() && resu > (it->first))) {
                    resu = it->first;
                }
                flag = true;
            }
        if (!flag) {
            puts("0");
        } else {
            cout << resu << endl;
        }
    }
    return 0;
}
