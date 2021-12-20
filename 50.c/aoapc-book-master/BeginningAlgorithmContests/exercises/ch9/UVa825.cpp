// UVa825 Walking on the Safe Side
// Rujia Liu
// ���⣺n*m��������һЩ�ϰ���������ϵ����µ�·��������ֻ�����Һ�������
// �㷨����̬�滮��d[i][j]Ϊ�����ϵ�(i,j)��·����������ˢ���ȽϺ�д����Ŀû˵��ģ��ʵ��m,n<=200
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

const int maxn = 200;
int a[maxn][maxn], d[maxn][maxn];

int main() {
  string line;
  int T, m, n;
  cin >> T;
  while(T--) {
    cin >> m >> n;
    getline(cin, line);
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    for(int i = 0; i < m; i++) {
      getline(cin, line);
      stringstream ss(line);
      int j;
      ss >> j;
      while(ss >> j) a[i][j-1] = 1;
    }
    if(a[0][0] == 0) d[0][0] = 1;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++) {
        if(i + 1 < m && a[i+1][j] == 0) d[i+1][j] += d[i][j];        
        if(j + 1 < n && a[i][j+1] == 0) d[i][j+1] += d[i][j];        
      }
    cout << d[m-1][n-1] << "\n";
    if(T) cout << "\n";
  }

  return 0;
}
