// UVa10791 Minimum Sum LCM
// Rujia Liu
// ���⣺��������n��1<=n<2^31����������������������ʹ�����ǵ���С������Ϊn������Щ�����ĺ���С�������С�ĺ͡�
// �㷨����Ψһ�ֽ�ʽn=a1^p1 * a2^p2...�����ѷ���ÿ��a[i]^p[i]��Ϊһ������������ʱ���š�
// ������n=1ʱ��Ϊ1+1=2��nֻ��һ������ʱ��Ҫ�Ӹ�1������ע��n=2^31-1ʱ��Ҫ���
#include<cmath>
#include<iostream>
using namespace std;

int divide_all(int& n, int d) {
  int x = 1;
  while(n % d == 0) { n /= d; x *= d; }
  return x;
}

long long solve(int n) {
  if(n == 1) return 2;
  int m = floor(sqrt(n) + 0.5);
  long long ans = 0;
  int pf = 0; // ������(prime_factor)����
  for(int i = 2; i < m; i++) {
    if(n % i == 0) { // �µ�������
      pf++;
      ans += divide_all(n, i);
    }
  }
  if(n > 1) { pf++; ans += n; }
  if(pf <= 1) ans++;
  return ans;
}

int main() {
  int n, kase = 0;
  while(cin >> n && n)
    cout << "Case " << ++kase << ": " << solve(n) << "\n";
  return 0;
}

