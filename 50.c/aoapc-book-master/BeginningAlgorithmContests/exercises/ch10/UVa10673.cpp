// UVa10673 Play with Floor and Ceil
// Rujia Liu
// ���⣺��������������x, k������������p, qʹ��x = p*floor(x/k) + q*ceil(x/k)��
// �㷨�����x��k�ı�������ֻҪp+q=k���ɣ�����floor(x/k)+1=ceil(x/k)����˶��߻��أ�����չŷ������㷨����
#include<iostream>
using namespace std;

typedef long long LL;

// ��ʹa, b��int��Χ�ڣ�x��y�п��ܳ���int��Χ
void gcd(LL a, LL b, LL& d, LL& x, LL& y) {
  if(!b){ d = a; x = 1; y = 0; }
  else{ gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int main() {
  int T, x, k;
  cin >> T;
  while(cin >> x >> k) {
    if(x % k == 0) cout << 0 << " " << k << "\n";
    else {
      int a = x/k, b = a+1;
      LL d, p, q;
      gcd(a, b, d, p, q);
      cout << p * x << " " << q * x << "\n";
    }
  }
  return 0;
}
