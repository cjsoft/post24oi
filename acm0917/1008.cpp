#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
map<string, int> mp;

int main() {
    mp["rat"] = 0;
    mp["ox"] = 1;
    mp["tiger"] = 2;
    mp["rabbit"] = 3;
    mp["dragon"] = 4;
    mp["snake"] = 5;
    mp["horse"] = 6;
    mp["sheep"] = 7;
    mp["monkey"] = 8;
    mp["rooster"] = 9;
    mp["dog"] = 10;
    mp["pig"] = 11;
    int T;
    string a, b;
    int ta, tb;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        ta = 11 - mp[a];
        tb = 11 - mp[b];
        if ((ta - tb) > 0) cout << (ta - tb) << endl;
        else cout << (ta - tb + 12) << endl;
    }
    return 0;
}

/*
*/