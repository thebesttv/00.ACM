// UVa10391 Compound Words
// Rujia Liu
// ���⣺��һ�����ʼ���S�������ж��ٸ�����w����д��a+b������a, b����S��ĵ��ʣ����밴�ֵ������У����ҲӦ���ֵ�������
// �㷨������ж�ÿ�������Ƿ������������жϷ�����ö��a�ĳ���
#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<string> dict;

int main() {
  string s;
  while(cin >> s) dict.insert(s);
  for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
    const string& w = *it;
    for(int p = 1; p < w.size(); p++)
      if(dict.count(w.substr(0, p)) && dict.count(w.substr(p, w.length()-p))) { cout << w << "\n"; break; }
  }    
  return 0;
}
