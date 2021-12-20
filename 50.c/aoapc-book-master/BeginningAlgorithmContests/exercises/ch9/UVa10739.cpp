// UVa10739 String to Palindrome
// Rujia Liu
// ���⣺����һ��Сд��ĸ��ɵ��ַ��������Բ��롢ɾ�����޸��ַ��������ٵ��޸Ĵ�����ɻ��Ĵ�
// �㷨�������ǲ��صġ���d[i][j]Ϊ�Ӵ�S[i..j]��Ҫ�޸ĵ����ٴ���
// ���S[i]==S[j]��d[i][j]=d[i+1][j-1]����������滻(d[i+1][j-1]+1)����ɾ��ĳһ��(d[i+1][j]+1����d[i][j-1]+1)
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

const int maxn = 1000 + 5;
int n, vis[maxn][maxn], d[maxn][maxn];
string S;

int dp(int i, int j) {
  if(i >= j) return 0;
  if(vis[i][j]) return d[i][j];
  vis[i][j] = 1;
  int& ans = d[i][j];
  if(S[i] == S[j]) ans = dp(i+1,j-1);
  else { ans = min(dp(i+1,j), dp(i,j-1)); ans = min(ans, dp(i+1,j-1)) + 1; }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for(int kase = 1; kase <= T; kase++) {
    cin >> S;
    n = S.length();
    memset(vis, 0, sizeof(vis));
    printf("Case %d: %d\n", kase, dp(0, n-1));
  }
  return 0;
}
