// UVa10905 Children's Game
// Rujia Liu
// ���⣺��һ����Ϸ������N����������Ҫ������һ�ְ���Щ�����������ķ���ʹ�����󡣱�����4����123,124,56,90,��ô�����������µĽ����1231245690, 1241235690, 5612312490, 9012312456, 9056124123 �ȡ�ʵ������24�ֽ�������ǿ��Կ϶���9056124123���������ġ� 
// �㷨������a+b>b+a�Ĺ�������
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const string& a, const string& b) {
  return a+b > b+a;
}

const int maxn = 50 + 5;
string s[maxn];

int main() {
  int n;
  while(cin >> n && n) {
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s, s+n, cmp);
    for(int i = 0; i < n; i++) cout << s[i];
    cout << "\n";
  }
  return 0;
}
