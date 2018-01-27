#include <stdio.h>
#include <string.h>
char isprime[10007];
int prime[10007], tot = 0;
int s[10007];
void genprime() {
  memset(isprime, 0xff, sizeof(isprime));
  memset(prime, 0, sizeof(prime));
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i < 10007; ++i) {
    if (isprime[i]) prime[tot++] = i;
    for (int j = 0; j < tot; ++j) {
      if (i * prime[j] > 10007) break;
      isprime[i * prime[j]] = 0;
      if (i % prime[j] == 0) break;
    }
  }
}


int main() {
  //freopen("a.txt", "r", stdin);
  genprime();
  for (int i = 0; i < tot; ++i)
    s[i + 1] = s[i] + prime[i];
  int t;
  while (scanf("%d", &t), t) {
    int cnt = 0;
    for (int i = 0; i < tot + 1; ++i) {
      for (int j = i + 1; j < tot + 1; ++j) {
        if (s[j] - s[i] == t) ++cnt;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
