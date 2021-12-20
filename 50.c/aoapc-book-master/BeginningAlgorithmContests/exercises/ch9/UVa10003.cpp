// UVa10003 Cutting Sticks
// Rujia Liu
// ���⣺������ӳ���L�Լ�n���и���λ�ã����մ�С�������У��������С���и���á�ÿ���и�ķ��õ��ڱ��и��ľ�����ȡ�
// ���磺L=10���и��Ϊ2, 4, 7���������2, 4, 7��˳�򣬷���Ϊ10+8+6=24���������4, 2, 7��˳�򣬷���Ϊ10+4+6=20
// �㷨����̬�滮����d[i][j]Ϊ�и�Сľ��i~j�����ŷ��ã���d[i][j]=min{d[i][k]+d[k][j]}+a[j]-a[i]������a[j]-a[i]�ǵ�һ���ķ��á�Ȼ��ֳ�i~k��k~j�����֡�
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 50 + 5;
int n, L, a[maxn], vis[maxn][maxn], d[maxn][maxn];

int dp(int i, int j) {
  if(i >= j - 1) return 0;
  if(vis[i][j]) return d[i][j];
  vis[i][j] = 1;
  int& ans = d[i][j];
  ans = -1;
  for(int k = i+1; k <= j-1; k++) {
    int v = dp(i,k) + dp(k,j) + a[j] - a[i];
    if(ans < 0 || v < ans) ans = v;
  }
  return ans;
}

int main() {
  while(scanf("%d%d", &L, &n) == 2 && L) {
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = 0; a[n+1] = L;
    memset(vis, 0, sizeof(vis));
    printf("The minimum cutting is %d.\n", dp(0, n+1));
  }
  return 0;
}
