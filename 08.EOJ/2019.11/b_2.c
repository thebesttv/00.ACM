#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int n, m, k;
int ans;
int d[10], b[8];
char s[2001];
long long g[2001][8];
map<long long, int> f;

void dfs(int x, int cnt, int k) {
  if (x > 7) {
    f.clear();
    for (int i = 1; i <= n; i ++) {
      long long v = 0;
      for (int j = 0; j < 8; j ++)
        v = v + d[j] * g[i][j];
      f[v] ++;
    }
    int sum = 0;
    for (auto u : f)
      sum += u.second * (u.second - 1) / 2;
    ans = max(ans, sum);
    return;
  }
  if (k)
    for (int i =1; i <= cnt; i ++) {
      d[x] = i;
      dfs(x + 1, cnt, k - 1);
    }

  d[x] = cnt + 1;
  dfs(x + 1, cnt + 1, k);
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i ++) {
    scanf("%s", s);
    for (int j = 0; j < m ; j ++)
    {
      for (int k = 0; k < 8; k ++)
        g[i][k] = g[i][k] * 11;
      g[i][s[j] - 'a'] += 23;
    }
  }
  d[0] = 1;
  dfs(1, 1, k);
  printf("%d\n", ans);
  return 0;
}
