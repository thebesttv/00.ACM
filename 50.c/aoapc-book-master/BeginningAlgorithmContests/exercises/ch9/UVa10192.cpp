// UVa10192 Vacation
// Rujia Liu
// ���⣺���������ַ�����������������г���
// �㷨��LCS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;

char A[maxn], B[maxn];
int d[maxn][maxn];

int LCS(const char* A, int n, const char* B, int m) {
  memset(d, 0, sizeof(d));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
      if(A[i-1] == B[j-1]) d[i][j] = d[i-1][j-1] + 1;
      else d[i][j] = max(d[i][j-1], d[i-1][j]);
    }
  return d[n][m];
}

int main() {
  int kase = 0;
  while(fgets(A, maxn, stdin) != NULL) {
    if(A[0] == '#') break;
    fgets(B, maxn, stdin);
    printf("Case #%d: you can visit at most %d cities.\n", ++kase, LCS(A, strlen(A)-1, B, strlen(B)-1)); // ��1����Ϊfgets������س�
  }
  return 0;
}
