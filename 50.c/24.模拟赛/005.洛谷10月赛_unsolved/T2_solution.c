#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 100010
#define maxm 1200010

using namespace std;

int a[maxn][3];
int f[maxn][4], ans, N, n;
int t[maxm];

struct BIT
{
  int a[maxm], N;

  int lowbit(int x)
  {
    return x & -x;
  }

  int query(int x)
  {
    int res = -1;
    for (; x; x -= lowbit(x))
      res = max(res, a[x]);
    return res;
  }

  void update(int x, int v)
  {
    for(; x <= N; x += lowbit(x))
      a[x] = max(a[x], v);
  }

  void init(int n)
  {
    for(N = 1; N < n; N <<= 1);
    memset(a, 0, sizeof(a));
  }

} b[4][2];

int res[4];

inline int id(int j)
{
  return j == 3 ? 2 : j;
}

int main()
{
  scanf("%d", &n);
  for (int j = 0; j < 3; j++)
    for (int i = 1; i <= n ; i++)
      scanf("%d", &a[i][j]), t[N++] = a[i][j];

  sort(t, t + N);
  N = unique(t, t + N) - t;
  for (int j = 0; j < 3; j++)
    for (int i = 1; i <= n ; i++)
      a[i][j] = (lower_bound(t, t + N, a[i][j]) - t) + 1;

  for (int j = 0; j < 4; j++)
    b[j][0].init(N), b[j][1].init(N);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      res[j] = 0;
      for (int k = 0; k < 4; k++)
        if(!(j == 2 && k == 3 || j == 3 && k == 2))
          res[j] = max(res[j], b[k][j & 1].query((j & 1) ? N - a[i][id(j)] + 1 : a[i][id(j)]));
      ans = max(ans, ++res[j]);
    }

    for (int j = 0; j < 4; j++)
      b[j][0].update(a[i][id(j)], res[j]),
        b[j][1].update(N - a[i][id(j)] + 1, res[j]);
  }

  printf("%d\n", ans);

  return 0;
}
