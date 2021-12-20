// UVa10617 Again Palindromes
// Rujia Liu
// ���⣺����һ������ΪN���ַ�����ɾ��0�������ַ���ʣ��һ�����Ĵ����ж����ַ��������ٵ���һ���ַ���
// �㷨���������˵��ַ�Ҫ��Ҫɾ���������ݳ�ԭ�����ڲ�ɾ�ķ�����+ɾ��ߵķ�����+ɾ�ұߵķ�����-ɾ���ߵķ�����
// d[i][j]ΪS[i..j]�ķ�������ֻ��S[i]==S[j]��ʱ����Բ�ɾ������������d[i+1][j-1]+1�����1��ֻ�����ˣ�
// ɾ��ߡ��ұߺ����ߵķ������ֱ�Ϊd[i+1][j], d[i][j-1], d[i+1][j-1]
// ����S[i]==S[j]ʱd[i][j]=d[i+1][j]+d[i][j-1]+1, ����d[i][j]=d[i+1][j]+d[i][j-1]-d[i+1][j-1]��ע��߽�
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

const int maxn = 100 + 5;
int n, vis[maxn][maxn];
long long d[maxn][maxn];
string S;

long long dp(int i, int j) {
  if(i > j) return 0;
  if(i == j) return 1;
  if(vis[i][j]) return d[i][j];
  vis[i][j] = 1;
  long long& ans = d[i][j];
  ans = dp(i+1,j) + dp(i,j-1);
  if(S[i] == S[j]) ans++; else ans -= dp(i+1,j-1);
  return ans;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> S;
    n = S.length();
    memset(vis, 0, sizeof(vis));
    cout << dp(0, n-1) << "\n";
  }
  return 0;
}
