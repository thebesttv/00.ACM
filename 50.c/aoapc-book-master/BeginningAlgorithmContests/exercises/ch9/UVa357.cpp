// UVa357 Let Me Count The Ways
// Rujia Liu
// ���⣺��50c, 25c, 10c, 5c, 1cӲ�ҡ�����n����n��Ǯ�ж�������ɷ�����n<=30000
// �㷨��ͬUVa674��
#include<cstdio>
const int maxn = 30000;
const int n_coins = 5;
const int coins[] = {1, 5, 10, 25, 50};
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
  int n;
  while(scanf("%d", &n) == 1) {
    if(d[n_coins-1][n] == 1) printf("There is only 1 way");
    else printf("There are %lld ways", d[n_coins-1][n]);
    printf(" to produce %d cents change.\n", n);
  }
  return 0;
}
