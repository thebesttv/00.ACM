// UVa10721 Bar Codes
// Rujia Liu
// ���⣺����n, k, m������ж��ٸ����������㣺����k���������֮��Ϊn��ÿ������Ⱦ�Ϊ1~m����������
// �㷨�����Ϊd[k][n]����d[i][j]=sum{d[i-1][j-c] | 1<=c<=min{j,k}}
#include<iostream>
#include<cstring>
using namespace std;

const int maxk = 50 + 5;
const int maxn = 50 + 5;
long long d[maxk][maxn];

int main() {
  int n, k, m;
  while(cin >> n >> k >> m) {
    memset(d, 0, sizeof(d));
    d[0][0] = 1;
    for(int i = 1; i <= k; i++)
      for(int j = 1; j <= n; j++) {
        d[i][j] = 0;
        for(int c = 1; c <= m && c <= j; c++)
          d[i][j] += d[i-1][j-c];
      }
    cout << d[k][n] << "\n";
  }
  return 0;
}
