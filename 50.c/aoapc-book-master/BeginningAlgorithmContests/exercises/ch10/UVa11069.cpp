// UVa11069 A Graph Problem
// Rujia Liu
// ���⣺��һ������Ϊn�����������ж��ٸ����������
// �㷨������ѡ��ѡ��һ�������������Եõ�f(n)=f(n-2)+f(n-3)
#include<cstdio>
const int maxn = 76;
int f[maxn+1];

int main() {
  f[1] = 1, f[2] = 2, f[3] = 2;
  for(int i = 4; i <= maxn; i++) f[i] = f[i-2] + f[i-3];
  int n;
  while(scanf("%d", &n) == 1) printf("%d\n", f[n]);
  return 0;
}

