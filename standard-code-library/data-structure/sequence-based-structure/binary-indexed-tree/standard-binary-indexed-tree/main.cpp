/**--------------------
 * Standard Binary Indexed Tree
 *
 * Time Consumption: \log{N} (every operation)
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/28
 * --------------------
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define BMXN 50007
#define lowbit(x) ((x) & (-(x)))
typedef long long TP;

TP _SEQUENCE[BMXN];

void BIT_ADD(int pos, TP adata) {
    for (; pos < BMXN; pos += lowbit(pos))
        _SEQUENCE[pos] += adata;
}

TP BIT_QUERY(int pos) {
    TP rtn = 0;
    for (; pos; pos -= lowbit(pos))
        rtn += _SEQUENCE[pos];
    return rtn;
}

inline void BIT_INIT() {
    memset(_SEQUENCE, 0, sizeof(_SEQUENCE));
}

