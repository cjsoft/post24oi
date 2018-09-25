#include <bits/stdc++.h>

using namespace std;

const int STRSIZE=int(4e7);
char in1[STRSIZE];
char *in=in1, *tempend;
void Input() {
    tempend=in+STRSIZE;
    fread(in,1,STRSIZE,stdin);
}
inline void scan(int &x) {
    char c=*(in++);
    while(!(c>='0' && c<='9')) c=*(in++);
    x=c-'0';
    c=*(in++);
    while(c>='0' && c<='9') {
        x=x*10+c-'0';
        c=*(in++);
    }
}

int main() {
    /* freopen("asd", "r", stdin); */
    Input();
    int x = 100;
    scan(x);
    while (x) {
        cout << x;
        scan(x);
    }
}
