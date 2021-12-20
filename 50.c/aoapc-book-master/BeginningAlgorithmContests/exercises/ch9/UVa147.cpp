// UVa147 Dollars
// Rujia Liu
// ���⣺��$100, $50, $20, $10, $5, $2, $1, 50c, 20c, 10c, 5cӲ�ҡ�����n����$n�ж�������ɷ�����n<=300.00
// �㷨��ͬUVa674��һ��ʼת�����������֣���Ȼ�����5
#include<cstdio>
#include<cmath>
const int maxn = 6000;
const int n_coins = 11;
const int coins[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long d[n_coins][maxn + 1];

void dp(int n) {
  for(int i = 0; i < n_coins; i++)
    for(int j = 0; j <= n; j++) {
      if(i == 0) d[i][j] = 1; // ��1��Ǯ��������j��ֻ��һ�ַ���
      else {
        d[i][j] = 0;
        for(int k = 0; k <= j; k += coins[i]) d[i][j] += d[i-1][j-k];
      }
    }
}

int main() {
  dp(maxn);
  double s;
  while(scanf("%lf", &s) == 1) {
    int n = floor(s*100+0.5);
    if(n == 0) break;
    printf("%3d.%02d%17lld\n", n/100, n%100, d[n_coins-1][n / 5]);
  }
  return 0;
}
