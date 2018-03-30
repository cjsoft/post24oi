#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dat1[507], dat2[507];
int len1 = 0, len2 = 0;
char raw[507];
bool cmp() {
    if (len1 == len2)
        for (int i = len1; i; --i)
            if (dat1[i] != dat2[i])
                return dat1[i] < dat2[i];
    return len1 < len2;
}
int main() {
    scanf("%s", raw);
    len1 = strlen(raw);
    for (int i = 0; i < len1; ++i)
        dat1[len1 - i] = raw[i] - '0';
    memset(raw, 0, sizeof(raw));
    scanf("%s", raw);
    len2 = strlen(raw);
    for (int i = 0; i < len2; ++i)
        dat2[len2 - i] = raw[i] - '0';
    bool tag = cmp();
    int *p1 = dat1, *p2 = dat2;
    if (tag) swap(p1, p2), swap(len1, len2);
    int len = max(len1, len2);
    for (int i = len; i; --i) {
        p1[i] -= p2[i];
    }
    for (int i = 1; i <= len; ++i) {
        while (p1[i] < 0) {
            p1[i] += 10;
            --p1[i + 1];
        }
    }
    while (!p1[len]) --len;
    if (tag) putchar('-');
    for (int i = len; i; --i) putchar('0' + p1[i]);
    putchar('\n');
}