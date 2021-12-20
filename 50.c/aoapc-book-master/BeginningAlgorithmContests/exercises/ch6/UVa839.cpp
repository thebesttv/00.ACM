// UVa839 Not so Mobile
// Rujia Liu
// ���⣺����һ����״��ƽ�������������ԭ���ж��Ƿ�ƽ�⡣���õݹ鷽ʽ���룬0��ʾ�м���
// �㷨���ڡ�������ʱֱ�Ӷ��벢�жϣ��������������������
#include<iostream>
using namespace std;

// ����һ������ƽ����������ƽ�Ƿ�ƽ�⣬����W�޸�Ϊ����ƽ��������
bool solve(int& W) {
  int W1, D1, W2, D2;
  bool b1 = true, b2 = true;
  cin >> W1 >> D1 >> W2 >> D2;
  if(!W1) b1 = solve(W1);
  if(!W2) b2 = solve(W2);
  W = W1 + W2;
  return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main() {
  int T, W;
  cin >> T;
  while(T--) {
    if(solve(W)) cout << "YES\n"; else cout << "NO\n";
    if(T) cout << "\n";
  }
  return 0;
}
