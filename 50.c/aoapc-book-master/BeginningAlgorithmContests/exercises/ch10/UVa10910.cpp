// UVa10910 Marks Distribution
// Rujia Liu
// ���⣺ĳ�˲μ���N�ſ��ԣ��ܷ�ΪT����ͷ�ΪP�����ж����ֿ��ܵķ�����N,T,P<=70�������32λ������������Χ��
// �㷨���𰸾���x1+x2+...+xN=T-(P-1)N���������⡣�ø��巨��һ����T-(P-1)N-1λ�ã���N-1������
// ע����Ȼ���������������Ǽ���������Ĺ����п��ܻ����
#include<iostream>
using namespace std;

long long C(int n, int m) {
  double ans = 1;
  if(n-m > m) m = n-m;
  for(int i = m+1; i <= n; i++) ans *= i;
  for(int i = 1; i <= n-m; i++) ans /= i;
  return ans + 0.5;
}

long long F(int N, int T, int P) {
  return C(T-(P-1)*N-1, N-1);
}

int main() {
  int N, T, P, kases;
  cin >> kases;
  while(kases--) {
    cin >> N >> T >> P;
    cout << F(N, T, P) << "\n";
  }
  return 0;
}
