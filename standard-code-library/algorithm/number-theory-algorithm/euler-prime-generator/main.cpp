/**--------------------
 * Euler Prime Generator
 *
 * Time Consumption: linear
 * Mem Consumption: linear
 * Author: cjsoft
 * Date: 2018/01/27
 * --------------------
 */

#include <cstring>

#define PMXN 100007

int PRIME[PMXN];
char ISPRIME[PMXN];
int PTOT;

void genprime() {
    memset(PRIME, 0, sizeof(PRIME));
    memset(ISPRIME, 0xff, sizeof(ISPRIME));
    PTOT = 0;
    ISPRIME[0] = ISPRIME[1] = 0;
    for (int i = 2; i < PMXN; ++i) {
        if (ISPRIME[i])
            PRIME[PTOT++] = i;
        for (int j = 0; j < PTOT; ++j) {
            if (i * PRIME[j] >= PMXN) break;
            ISPRIME[i * PRIME[j]] = 0;
            if (i % PRIME[j] == 0) break;
        }
    }
}

