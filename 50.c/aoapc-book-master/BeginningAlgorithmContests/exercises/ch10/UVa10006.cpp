// UVa10006 Carmichael Numbers
// Rujia Liu
// ���⣺����n���ж��Ƿ�ΪCarmichael number����n����������������������1<=a<n, a^n mod n = a
// �㷨��ö��a�����������ȡģ
#include<cstdio>
#include<cmath>

bool is_prime(int n) {
  int m = floor(sqrt(n) + 0.5);
  for(int a = 2; a <= m; a++)
    if(n % a == 0) return false;
  return true;
}

int pow_mod(int a, long long p, int mod) {
  if(p == 0) return 1;
  int ans = pow_mod(a, p/2, mod);
  ans = (long long)ans * ans % mod;
  if(p%2) ans = (long long)ans * a % mod;
  return ans;
}

bool is_carmichael(int n) {
  if(is_prime(n)) return false;
  for(int a = 2; a < n; a++)
    if(pow_mod(a, n, n) != a) return false;
  return true;
}

int main() {
  int n;
  while(scanf("%d", &n) == 1 && n) {
    if(is_carmichael(n)) printf("The number %d is a Carmichael number.\n", n);
    else printf("%d is normal.\n", n);
  }
  return 0;
}
