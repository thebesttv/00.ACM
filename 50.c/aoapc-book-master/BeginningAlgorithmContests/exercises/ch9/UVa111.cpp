// UVa111 History Grading
// Rujia Liu
// ���⣺��ʷ��������һ����������⣬�ٶ���ȷ���¼�˳��ΪA������д����B������ߵ�LCSΪ�÷֡�������ȷ�𰸺Ϳ�������ÿ���¼�����ţ������÷֡�
// �㷨��ע���������ÿ���¼�����ţ���LCS����Եİ�ʱ��˳����¼�����
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 20 + 5;
int n, A[maxn], B[maxn], d[maxn][maxn];

int LCS() {
  memset(d, 0, sizeof(d));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      if(A[i] == B[j]) d[i][j] = d[i-1][j-1] + 1;
      else d[i][j] = max(d[i][j-1], d[i-1][j]);
    }
  return d[n][n];
}

bool read() {
  int x;
  for(int i = 0; i < n; i++) {
    if(!(cin >> x)) return false;
    B[x] = i;
  }
  return true;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) { int x; cin >> x; A[x] = i; }
  while(read()) {
    cout << LCS() << "\n";
  }
  return 0;
}
