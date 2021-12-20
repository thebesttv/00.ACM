// UVa10277 Boastin' Red Socks
// Rujia Liu
// ���⣺����aֻ�����Ӻ�b-aֻ�����ӣ���b���ӡ�2<=b<=50000���������ֻ�������Ǻ�ɫ�ĸ���Ϊp/q������p, q�����������������򱨸��޽�
// �㷨��p/q=a*(a-1)/b*(b-1)��ö��b����a*(a-1)=b*(b-1)*p/q��Ȼ����a���ɡ�ע��p=0�����
#include<iostream>
#include<cmath>
using namespace std;

void solve(long long p, long long q) {
  if(p == 0) { cout << "0 2\n"; return; }
  for(long long b = 2; b <= 50000; b++) {
    long long x = b * (b-1) * p;
    if(x % q != 0) continue;
    x /= q;
    long long a = (long long)sqrt(x)+1;
    if(a*(a-1) == x) {
      cout << a << " " << b-a << "\n";
      return;
    }
  }
  cout << "impossible\n";
}

int main() {
  long long p, q;
  while(cin >> p >> q && q) // ע��p����Ϊ0
    solve(p, q);
  return 0;
}

