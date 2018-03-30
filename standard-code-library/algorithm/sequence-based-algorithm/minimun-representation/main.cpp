/**--------------------
 * Minimum Sequence Representation Algorithm
 *
 * Time Consumption: linear
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/29
 * --------------------
 */

#include <cstring>
#include <iostream>

#define MREPMXN 1007
typedef char MREPTP;

MREPTP _SEQ[MREPMXN << 1 | 1];

int minrep(MREPTP a[], int n) {
    memset(_SEQ, 0, sizeof(_SEQ));
    memcpy(_SEQ, a, sizeof(MREPTP) * n);
    memcpy(_SEQ + n, _SEQ, sizeof(MREPTP) * n);
    int i = 0, j = 1, k;
    while (j < n) {
        k = 0;
        while (j + k < (n << 1) && _SEQ[i + k] == _SEQ[j + k]) ++k;
        if (j + k == (n << 1)) break;
        else if (_SEQ[i + k] > _SEQ[j + k]) {
            i = std::max(i + k + 1, j);
            j = i + 1;
        } else j += k + 1;
    }
    return i;
}
