// UVa674 Coin Change
// Rujia Liu
// ���⣺��50, 25, 10, 5, 1��Ӳ�ҡ�����n����n��Ǯ�ж�������ɷ�����n<=7489
// �㷨��DP��d[i][j]��ʾǰi��0<=i<5����Ӳ�����j��Ǯ�ж����ַ������߽�Ϊd[0][*]=1��
// ע������ֻ��һ�����������Դ��
#include<cstdio>
const int maxn = 7500;
const int n_coins = 5;
const int coins[] = {1, 5, 10, 25, 50};
int d[n_coins][maxn + 1];

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
  while(scanf("%d", &n) == 1) printf("%d\n", d[n_coins-1][n]);
  return 0;
}
