// UVa10069 Distinct Subsequences
// Rujia Liu
// ���⣺���������ַ���X��Z����X�ж��ٸ������е���Z
// �㷨����d[i][j]ΪX[1..i]�ж��ٸ������е���Z[1..j]��
// ��X[i]==Z[j]ʱ��d[i][j]=d[i-1][j]+d[i-1][j-1]������d[i][j]=d[i-1][j]���߽�Ϊd[*][0]=1����Ҫ�и߾���
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 5;
const int maxm = 100 + 5;

const int maxd = 20;
const int MOD = 1000000000;

struct bign{
  int len, s[maxd];

  bign() { memset(s, 0, sizeof(s)); len = 1; }
  bign(int num) { *this = num; }

  bign operator = (int num) {
    s[0] = num;
    len = 1;
  }

  bign operator + (const bign& b) const{
    bign c;
    c.len = 0;
    for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
      int x = g;
      if(i < len) x += s[i];
      if(i < b.len) x += b.s[i];
      c.s[c.len++] = x % MOD;
      g = x / MOD;
    }
    return c;
  }

  bign operator += (const bign& b) {
    *this = *this + b;
    return *this;
  }
};

ostream& operator << (ostream &out, const bign& x) {
  for(int i = x.len-1; i > 0; i--) {
    cout << x.s[i];
  }
  if(x.len != 1) {
    char buf[20];
    sprintf(buf, "%09d", x.s[0]);
    for(int i = 0; i < strlen(buf); i++) cout << buf[i];
  } else
    cout << x.s[0];
  return out;
}

char A[maxn], B[maxm];
bign d[maxn][maxm];

void solve(const char* A, int n, const char* B, int m) {
  memset(d, 0, sizeof(d));
  d[0][0] = 1;
  for(int i = 1; i <= n; i++) {
    d[i][0] = 1;
    for(int j = 1; j <= m; j++) {
      d[i][j] = d[i-1][j];
      if(A[i-1] == B[j-1]) d[i][j] += d[i-1][j-1];
    }
  }
  cout << d[n][m] << "\n";
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%s%s", A, B);
    solve(A, strlen(A), B, strlen(B));
  }
  return 0;
}
