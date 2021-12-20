// UVa10219 Find the ways !
// Rujia Liu
// ���⣺��C(n,k)��ʮ�������Ǽ�λ��
// �㷨����log(10, C(n,k))����
#include<cstdio>
#include<cmath>
double lgC(int n, int m) {
  double ans = 1;
  if(n-m > m) m = n-m;
  for(int i = m+1; i <= n; i++) ans += log10(i);
  for(int i = 1; i <= n-m; i++) ans -= log10(i);
  return ans;
}

int main() {
  int n, k;
  while(scanf("%d%d", &n, &k) == 2)
    printf("%.0lf\n", floor(lgC(n, k)));
  return 0;
}
