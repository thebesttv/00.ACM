// UVa10340 All in All
// Rujia Liu
// ���⣺���������ַ���S��T���ж�S�Ƿ�ΪT�ģ���һ�������ģ��Ӵ�
#include<iostream>
#include<string>
using namespace std;

int main() {
  string s, t;
  while(cin >> s >> t) {
    int n = s.length(), m = t.length();
    bool ok = true;
    int i, j;
    for(i = j = 0; i < n; i++, j++) {
      while(j < m && t[j] != s[i]) j++;
      if(j == m) { ok = false; break; }
    }
    if(ok) cout << "Yes\n"; else cout << "No\n";
  }
  return 0;
}

