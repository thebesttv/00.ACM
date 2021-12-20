// UVa10105 Polynomial coefficients
// Rujia Liu
// ���⣺����������n, k���Լ�k���Ǹ�����n1, n2, ..., nk, ���(x1+x2+...+xk)^n��x1^n1*x2^n2*...*xk^nk��ϵ��
// �㷨����n��������ѡn1��x1����ѡn2��x2����ѡn3��x3...���������ΪC(n,n1)*C(n-n1,n2)*...
#include<iostream>
using namespace std;

const int maxn = 12;
long long C[maxn+1][maxn+1];

// ���Ƴ����������
void init() {
  for(int i = 0; i <= maxn; i++) {
    C[i][0] = 1;
    for(int j = 1; j <= i; j++)
      C[i][j] = C[i-1][j] + C[i-1][j-1]; // ע��i=0ʱ����ִ���������
  }
}

int main() {
  init();
  int n, k, ni;
  while(cin >> n >> k && n) {
    long long ans = 1;
    for(int i = 0; i < k; i++) {
      cin >> ni;
      ans *= C[n][ni];
      n -= ni;
    }
    cout << ans << "\n";
  }
  return 0;
}
