#include <cstring>
#include <iostream>
#include <cstdio>
#define N 57
using namespace std;

int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
char mp[N][N], vis[N][N];
int s = 0, n, m, b = 0, sss;
char tag = 0;

void dfs(int y, int x) {
    if (vis[y][x] || ( mp[y][x] != '.' && mp[y][x] != '?' && mp[y][x] != '*' )) return;
    vis[y][x] = 1;
    if (mp[y][x] == '?') mp[y][x] = '*';
    s++;
    for (int i = 0; i < 4; ++i) dfs(y + dy[i], x + dx[i]);
}

int main() {
    int x, y;
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == '.' && !vis[i][j]) {
                ++b;
                dfs(i, j);
                y = i, x = j;
            }
        }
    sss = s;
    if (b == 1) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m ; j++) {
                if (mp[i][j] == '*') {
                    memset(vis, 0, sizeof(vis));
                    mp[i][j] = '#';
                    s = 0;
                    dfs(y, x);
                    if (s == sss - 1) tag = 1;
                    mp[i][j] = '.';
                }
            }
        if (tag) {
            puts("Ambiguous");
        } else {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (mp[i][j] == '.') putchar('.');
                    else putchar('#');
                }
                putchar('\n');
            }
        }

    } else puts("Impossible");
    return 0;
}
/* #include <cstring> */
/* #include <iostream> */
/* #include <cstdio> */
/* #define N 57 */
/* using namespace std; */
/* char vis[N][N]; */
/* char mp[N][N]; */
/* int arbicnt, vcnt, tarbicnt, tvcnt; */
/* char donetag, suctag, ftag; */
/* void dfs(int y, int x) { */
    /* if (donetag) return; */
    /* char innertag = 0; */
    /* if (mp[y][x] != '.' && mp[y][x] != '#' && mp[y][x] != '?') return; */
    /* if (vis[y][x]) return; */
    /* vis[y][x] = 1; */
    /* if (mp[y][x] == '.') { */
        /* if (++vcnt == tvcnt) { */
            /* donetag = 1; */
            /* if (arbicnt == tarbicnt) { */
                /* suctag = 1; */
            /* } */
            /* return; */
        /* } */
    /* } */
    /* if (mp[y][x] == '?') ++arbicnt; */
    /* if (mp[y][x] == '#') return; */
    /* if (mp[y - 1][x] != '?') dfs(y - 1, x); */
    /* if (mp[y + 1][x] != '?') dfs(y + 1, x); */
    /* if (mp[y][x + 1] != '?') dfs(y, x + 1); */
    /* if (mp[y][x - 1] != '?') dfs(y, x - 1); */
    /* dfs(y - 1, x); */
    /* dfs(y + 1, x); */
    /* dfs(y, x + 1); */
    /* dfs(y, x - 1); */
/* } */
/* void secdfs(int y, int x) { */
    /* if (vis[y][x] || mp[y][x] != '?') return; */
    /* ++arbicnt; */
    /* vis[y][x] = 1; */
    /* dfs(y - 1, x); */
    /* dfs(y + 1, x); */
    /* dfs(y, x + 1); */
    /* dfs(y, x - 1); */

/* } */
/* char ffs(int y, int x) { */
    /* if (mp[y - 1][x] == '.' || mp[y - 1][x] == '?' && vis[y - 1][x]) return 0; */
    /* if (mp[y + 1][x] == '.' || mp[y + 1][x] == '?' && vis[y + 1][x]) return 0; */
    /* if (mp[y][x + 1] == '.' || mp[y][x + 1] == '?' && vis[y][x + 1]) return 0; */
    /* if (mp[y][x - 1] == '.' || mp[y][x - 1] == '?' && vis[y][x - 1]) return 0; */
    /* return 1; */
/* } */

/* int main() { */
    /* memset(vis, 0, sizeof(vis)); */
    /* arbicnt = vcnt = tvcnt = tarbicnt = donetag = suctag = 0; */
    /* ftag = 1; */
    /* int n, m; */
    /* scanf ("%d %d\n", &n, &m); */
    /* for (int i = 1; i <= n; ++i) */
        /* scanf("%s", mp[i] + 1); */
    /* for (int i = 1; i <= n; ++i) { */
        /* for (int j = 1; j <= m; ++j) { */
            /* if (mp[i][j] == '.') ++tvcnt; */
            /* if (mp[i][j] == '?') ++tarbicnt; */
        /* } */
    /* } */
    /* for (int i = 1; i <= n; ++i) { */
        /* for (int j = 1; j <= m; ++j) { */
            /* if (mp[i][j] == '.') { */
                /* dfs(i, j); */
                /* if (suctag) { */
                    /* for (int k = 1; k <= n; ++k) { */
                        /* for (int l = 1; l <= m; ++l) { */
                            /* if (mp[k][l] == '?') putchar('.'); */
                            /* else putchar(mp[k][l]); */
                        /* } */
                        /* putchar('\n'); */
                    /* } */
                    /* return 0; */
                /* } */
                /* if (donetag) { */
                    /* for (int k = 1; k <= n; ++k) { */
                        /* for (int l = 1; l <= m; ++l) { */
                            /* if (mp[k][l] == '?' && !vis[k][l]) { */
                                /* if (!ffs(k, l)) ftag = 0; */
                            /* } */
                        /* } */
                    /* } */
                    /* if (!ftag) puts("Ambiguous"); */
                    /* else { */
                        /* for (int k = 1; k <= n; ++k) { */
                            /* for (int l = 1; l <= m; ++l) { */
                                /* if (mp[k][l] == '?') { */
                                    /* if (vis[k][l]) putchar('.'); */
                                    /* else putchar('#'); */
                                /* } */
								/* else putchar(mp[k][l]); */
							/* } */
                            /* putchar('\n'); */
						/* } */
                    /* } */
					/* return 0; */
                /* } */
                /* puts("Impossible"); */
                /* return 0; */
            /* } */
        /* } */
    /* } */
    /* if (tarbicnt > 1) puts("Ambiguous"); */
    /* else if (tarbicnt == 1) { */
        /* for (int i = 1; i <= n; ++i) { */
            /* for (int j = 1; j <= m; ++j) { */
                /* if (mp[i][j] == '?') { */
                    /* putchar('.'); */
                /* } else putchar('#'); */
            /* } */
            /* putchar('\n'); */
        /* } */

    /* } else puts("Impossible"); */
    /* return 0; */
 /* } */
