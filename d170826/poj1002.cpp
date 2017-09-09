#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;
string tmp;
map<string, int> asd;
int casecount, slen, pcnt;
char iptstr[37], mapping[257];
map<string, int>::iterator cursor;
int main() {
    memset(mapping, 0, 257);
    for (char i = 'A'; i < 'Q'; ++i) mapping[i] = (i - 'A') / 3 + '2';
    for (char i = 'R'; i < 'Z'; ++i) mapping[i] = (i - 'Q') / 3 + '7';
    for (char i = '0'; i <= '9'; ++i) mapping[i] = i;
    scanf("%d", &casecount);
    while (casecount--) {
        memset(iptstr, 0, 37);
        scanf("%s", iptstr);
        tmp = "";
        pcnt = 0;
        slen = strlen(iptstr);
        for (int i = 0; i < slen; ++i) {
            if (iptstr[i] != '-') {
                tmp.append(1, mapping[iptstr[i]]);
                ++pcnt;
                if (pcnt == 3) tmp.append(1, '-');
            }
        }
        // cout << tmp << endl;
        cursor = asd.find(tmp);
        if (cursor != asd.end()) ++cursor->second;
        else asd[tmp] = 1;
    }
    bool flag = false;
    for (map<string, int>::iterator i = asd.begin(); i != asd.end(); i++) {
        if (i->second > 1) {
            printf("%s %d\n", i->first.c_str(), i->second);
            flag = true;
        }
    }
    if (!flag) printf("No duplicates.\n");
    return 0;
}