// UVa10300 Ecological Premium
// Rujia Liu
// ���⣺����n����Ԫ��(a,b,c)������a*c֮��
// ע������۲���Ŀ�е���ֵ��Χ���Է��ֽ����Ҫ��long long����
#include<iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    long long n, a, b, c, sum = 0;
    cin >> n;
    while(n--) { cin >> a >> b >> c; sum += a * c; }
    cout << sum << "\n";
  }
  return 0;
}
