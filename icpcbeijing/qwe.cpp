#include <bits/stdc++.h>

using namespace std;

map<char, int> mp = {
    {'0', 9},
    {'A', 0},
    {'2', 1},
    {'3', 2},
    {'4', 3},
    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7},
    {'9', 8},
    {'J', 10},
    {'Q', 11},
    {'K', 12}
};
char lexid[] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 1, 11, 13, 12};
typedef pair<int, int> PII;
vector<PII> stk;
inline int readcard() {
    int ch = getchar();
    if (ch == EOF) return EOF;
    while (!isdigit((char)ch) && ch != 'A' && ch != 'J' && ch != 'Q' && ch != 'K') ch = getchar();
    if (ch == '1') ch = getchar();
    return mp[ch];
}

int cards[4][13];
int smc[4];
string rmp[] = {
    string("A"),
    string("2"),
    string("3"),
    string("4"),
    string("5"),
    string("6"),
    string("7"),
    string("8"),
    string("9"),
    string("10"),
    string("J"),
    string("Q"),
    string("K")
};
void jiesuan() {
    for (int i = 0; i < 4; ++i) {
        bool tag = false;
        for (int j = 0; j < 13; ++j) {
            if (cards[i][j]) {
                for (int k = 0; k < cards[i][j]; ++k) {
                    if (tag) putchar(' ');
                    tag = true;
                    cout << rmp[j];
                }
            }
        }
        putchar('\n');
    }
}

int main() {
    while (1) {
        memset(cards, 0, sizeof(cards));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                int tmp = readcard();
                if (tmp == -1) return 0;
                cards[i][tmp]++;
                smc[i]++;
            }
        }
        int asid, cnt, rid, islie;
        for (int rh = 0, cr = 0; ; rh = (rh + 1) % 4, cr = (cr + 1) % 13) {
            if (rh == 0) {
                if (cards[rh][cr]) {
                    asid = cr;
                    cnt = 1;
                    smc[rh] -= cnt;
                    rid = cr;
                    cards[rh][cr]--;
                    stk.push_back(make_pair(rid, cnt));
                    islie = false;
                } else {
                    int tmp = -1;
                    for (int i = 0; i < 13; ++i) {
                        if (cards[rh][i] && (tmp == -1 || lexid[tmp] > lexid[i]))
                            tmp = i;
                    }
                    asid = cr;
                    rid = tmp;
                    cnt = 1;
                    smc[rh] -= cnt;
                    cards[rh][tmp]--;
                    stk.push_back(make_pair(tmp, cnt));
                    islie = true;
                }
            } else if (rh == 1) {
                if (cards[rh][cr]) {
                    asid = cr;
                    cnt = cards[rh][cr];
                    smc[rh] -= cnt;
                    rid = cr;
                    cards[rh][cr] = 0;
                    stk.push_back(make_pair(rid, cnt));
                    islie = false;
                } else {
                    int tmp = -1;
                    for (int i = 0; i < 13; ++i) {
                        if (cards[rh][i] && (tmp == -1 || lexid[tmp] > lexid[i]))
                            tmp = i;
                    }
                    asid = cr;
                    rid = tmp;
                    cnt = cards[rh][cr];
                    smc[rh] -= cnt;
                    cards[rh][tmp] = 0;
                    stk.push_back(make_pair(tmp, cnt));
                    islie = true;
                }
            } else if (rh == 2) {
                if (cards[rh][cr]) {
                    asid = cr;
                    cnt = cards[rh][cr];
                    smc[rh] -= cnt;
                    rid = cr;
                    cards[rh][cr] = 0;
                    stk.push_back(make_pair(rid, cnt));
                    islie = false;
                } else {
                    int tmp = -1;
                    for (int i = 0; i < 13; ++i) {
                        if (cards[rh][i] && (tmp == -1 || cards[rh][i] < cards[rh][tmp] || (cards[rh][i] == cards[rh][tmp] && lexid[tmp] > lexid[i])))
                            tmp = i;
                    }
                    asid = cr;
                    rid = tmp;
                    cnt = cards[rh][tmp];
                    smc[rh] -= cnt;
                    cards[rh][tmp] = 0;
                    stk.push_back(make_pair(tmp, cnt));
                    islie = true;
                }
            } else if (rh == 3) {

                if (cards[rh][cr] > 2) {
                    asid = cr;
                    cnt = cards[rh][cr];
                    smc[rh] -= cnt;
                    rid = cr;
                    cards[rh][cr] = 0;
                    stk.push_back(make_pair(rid, cnt));
                    islie = false;
                } else {
                    int tmp = -1;
                    for (int i = 0; i < 13; ++i) {
                        if (cards[rh][i] && (tmp == -1 || lexid[tmp] > lexid[i]))
                            tmp = i;
                    }
                    asid = cr;
                    rid = tmp;
                    cnt = cards[rh][cr];
                    stk.push_back(make_pair(cr, cards[rh][cr]));
                    cards[rh][cr] = 0;
                    if (tmp != -1) cnt++, cards[rh][tmp]--, stk.push_back(make_pair(tmp, 1));
                    smc[rh] -= cnt;
                    islie = true;
                }
            }
            for (int chl = (rh + 1) % 4; chl != rh; chl = (chl + 1) % 4) {
                bool chtag = false;
                if (chl == 0) {
                    if (chl == (rh + 1) % 4 && !cards[chl][(asid + 1) % 4]) {
                        chtag = true;
                    }
                    if (cnt + cards[chl][asid] > 4) {
                        chtag = true;
                    }
                } else if (chl == 1) {
                    if (chl == (rh + 1) % 4 && !cards[chl][(asid + 1) % 4]) {
                        chtag = true;
                    }
                } else if (chl == 2) {
                    if (cards[chl][asid] == 4) {
                        chtag = true;
                    }
                } else if (chl == 3) {
                    if (!smc[rh])
                        chtag = true;
                }
                if (chtag == true) {
                    if (islie == true) {
                        for (auto i : stk) {
                            cards[rh][i.first] += i.second;
                            smc[rh] += i.second;
                        }
                    } else {
                        for (auto i : stk) {
                            cards[chl][i.first] += i.second;
                            smc[chl] += i.second;
                        }

                    }
                    stk.clear();
                    break;
                }
            }
            if (!smc[rh]) {
                jiesuan();
                goto NXT;
            }
        }

NXT:;
    }
}
