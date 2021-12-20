// UVa11121 Base -2
// Rujia Liu
// ���⣺��֪�������͸���������Ωһ��-2���Ʊ�ʾ�����Ҳ�������λ����������n���������-2���Ʊ�ʾ
// �㷨������b0, b1, ... ������˳����⣬ÿ�ζ�-2ȡ�࣬Ȼ�������������0��1��
#include<cstdio>

void div_negative(int n, int m, int& q, int& r) {
  q = n / m;
  r = n - q * m;
  while(r < 0) { r -= m; q++; }
}

int b[10];
void solve(int n) {
  int k = 0, q, r;
  do {
    div_negative(n, -2, q, r);
    b[k++] = r;
    n = q;
  } while(n);
  for(int i = k-1; i >= 0; i--) printf("%d", b[i]);
  printf("\n");
}

int main() {
  int T, n, kase = 0;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    printf("Case #%d: ", ++kase);
    solve(n);
  }
  return 0;
}
