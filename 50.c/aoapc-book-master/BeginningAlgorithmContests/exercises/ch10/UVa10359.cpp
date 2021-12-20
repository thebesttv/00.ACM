// UVa10359 Tiling
// Rujia Liu
// ���⣺2*n��2*1��2*2�����ж������̷���
// �㷨��f(1)=1, f(2)=3�����ѷ���f(n)=f(n-2)*2+f(n-1)
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

struct BigInteger {
  static const int MOD = 1000000000;
  vector<int> s;

  BigInteger(int num=0) { *this = num; }
  BigInteger operator = (int num) { s.clear(); s.push_back(num); return *this; }

  BigInteger operator + (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for(int i = 0, g = 0; ; i++) {
      if(g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if(i < s.size()) x += s[i];
      if(i < b.s.size()) x += b.s[i];
      c.s.push_back(x % MOD);
      g = x / MOD;
    }
    return c;
  }

  BigInteger operator += (const BigInteger& b) { *this = *this + b; return *this; }
};

ostream& operator << (ostream &out, const BigInteger& x) {
  cout << x.s.back();
  for(int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "%09d", x.s[i]);
    for(int j = 0; j < strlen(buf); j++) cout << buf[j];
  }
  return out;
}

const int maxn = 10000 + 5;

BigInteger f[maxn+1];

int main() {
  f[0] = 1;
  f[1] = 1;
  for(int i = 2; i <= maxn; i++)
    f[i] = f[i-2] + f[i-2] + f[i-1];
  int n;
  while(cin >> n) cout << f[n] << "\n";
  return 0;
}
