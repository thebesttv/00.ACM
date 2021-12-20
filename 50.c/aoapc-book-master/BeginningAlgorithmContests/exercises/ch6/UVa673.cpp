// UVa673 Parentheses Balance
// Rujia Liu
// ���⣺����һ������()��[]���������У��ж��Ƿ�Ϸ���
// ����ݹ鶨�����£�1.�մ��Ϸ���2.���A��B���Ϸ�����AB�Ϸ���3.���A�Ϸ���(A)��[A]���Ϸ���
// �㷨����һ��ջ��ע����������пմ�
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool judge(const string& input) {
  int n = input.length();
  stack<char> s;
  for(int i = 0; i < n; i++) {
    char c = input[i];
    if(c == '(' || c == '[') s.push(c);
    else {
      if(s.empty()) return false;
      if(c == ')' && s.top() != '(') return false;
      if(c == ']' && s.top() != '[') return false;
      s.pop();
    }
  }
  return s.empty();
}

int main() {
  int T;
  string s;
  cin >> T;
  getline(cin, s); // �Ե�T����Ļس�
  while(T--) {
    getline(cin, s);
    if(judge(s)) cout << "Yes\n"; else cout << "No\n";
  }
  return 0;
}
