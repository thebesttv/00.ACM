// UVa10375 Choose and divide
// Rujia Liu
// ���⣺����p, q, r, s������C(p,q)/C(r,s)����֪C(m,n) = m!/(n!(m-n)!)��p>=q, r>=s, p,q,r,s<=10000�������֤������10^8������5λС����
// �㷨���ֽ������������������ӵ������������һ���Լ��㡣
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

const int maxn = 10000;
vector<int> primes;
int e[maxn];

// ���Ի����n. d=0��ʾ�ˣ�d=-1��ʾ��
void add_integer(int n, int d) {
  for(int i = 0; i < primes.size(); i++) {
    while(n % primes[i] == 0) {
      n /= primes[i];
      e[i] += d;
    }
    if(n == 1) break; // ��ǰ��ֹѭ������Լʱ��
  }
}

void add_factorial(int n, int d) {
  for(int i = 1; i <= n; i++)
    add_integer(i, d);
}

bool is_prime(int n) {
  int m = floor(sqrt(n) + 0.5);
  for(int a = 2; a <= m; a++)
    if(n % a == 0) return false;
  return true;
}

int main() {
  for(int i = 2; i <= 10000; i++)
    if(is_prime(i)) primes.push_back(i);
  int p, q, r, s;
  while(cin >> p >> q >> r >> s) {
    memset(e, 0, sizeof(e));
    add_factorial(p, 1);
    add_factorial(q, -1);
    add_factorial(p-q, -1);
    add_factorial(r, -1);
    add_factorial(s, 1);
    add_factorial(r-s, 1);
    double ans = 1;
    for(int i = 0; i < primes.size(); i++)
      ans *= pow(primes[i], e[i]);
    printf("%.5lf\n", ans);
  }
  return 0;
}
