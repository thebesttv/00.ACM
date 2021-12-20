// UVa10304 Optimal Binary Search Tree
// Rujia Liu
// ���⣺�����OBST����
// �㷨����d[i][j]Ϊ�ؼ���i~j�������OBST����С���ã�sum(i,j)Ϊi~j��Ȩֵ֮��
// d[i][j] = min{d[i][k-1] + d[k+1][j]} + sum(i,j) - f[k]����ʾ�����Ϊk�����˸�֮���������ĸ߶ȼ�1����˷���Ҫ����Ȩֵ��
#include<cstdio>
#include<cstring>
const int maxn = 250 + 5;
int n, f[maxn], psum[maxn], d[maxn][maxn];

int dp(int i, int j) {
  if(i > j) return 0;
  int& ans = d[i][j];
  if(ans > 0) return ans;
  ans = -1;
  for(int k = i; k <= j; k++) {
    int v = dp(i,k-1) + dp(k+1,j) + psum[j] - psum[i-1] - f[k];
    if(ans < 0 || v < ans) ans = v;
  }
  return ans;
}

int main() {
  while(scanf("%d", &n) == 1 && n) {
    memset(psum, 0, sizeof(psum));
    for(int i = 1; i <= n; i++) { scanf("%d", &f[i]); psum[i] = psum[i-1] + f[i]; }
    memset(d, 0, sizeof(d));
    printf("%d\n", dp(1, n));
  }
  return 0;
}
