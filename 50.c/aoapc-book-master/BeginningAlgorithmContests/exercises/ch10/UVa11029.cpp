// UVa11029 Leading and Trailing
// Rujia Liu
// ���⣺����������n, k, ���n^k��ǰ��λ�ͺ���λ��n��32λ��������k<=10^7
// �㷨�������λ�ÿ�����ȡģ���ɣ�ǰ��λ���Խ��Ƽ��㡣��n^k=a*10^b��1<=a<10������klog10(n) = b+log10(a)
// ȡlog10(a)Ϊklog10(n)��С�����ּ��ɡ����ǰ��λ����a*100���������֡�
#include<cstdio>
#include<cmath>
int pow_mod(int a, long long p, int mod) {
  if(p == 0) return 1;
  int ans = pow_mod(a, p/2, mod);
  ans = (long long)ans * ans % mod;
  if(p%2) ans = (long long)ans * a % mod;
  return ans;
}

int main() {
  int T, n, k;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &k);
    int last = pow_mod(n, k, 1000);
    int first = (int)pow(10, fmod(k * log10(n), 1) + 2); // ֱ��ȡ����������������
    printf("%d...%03d\n", first, last);
  }
  return 0;
}
