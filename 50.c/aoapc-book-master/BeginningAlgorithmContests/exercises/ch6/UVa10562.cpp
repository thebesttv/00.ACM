// UVa10562 Undraw the Trees
// Rujia Liu
// ���⣺�ѻ���ͦ�ÿ��Ķ����ת��Ϊ���ű�ʾ��
// �㷨��ֱ���ڶ�ά�ַ�������ݹ顣ע����������ҽ���ſ���������ɴ�ӡ�ַ�

#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

const int maxn = 200 + 10;
int n;
char buf[maxn][maxn];

// �ݹ��������������ַ�buf[r][c]Ϊ������
void dfs(int r, int c) {
  printf("%c(", buf[r][c]);
  if(r+1 < n && buf[r+1][c] == '|') { // ������
    int i = c;
    while(i-1 >= 0 && buf[r+2][i-1] == '-') i--; // ��"----"����߽�
    while(buf[r+2][i] == '-' && buf[r+3][i] != '\0') {
      if(!isspace(buf[r+3][i])) dfs(r+3, i); // fgets�����'\n'Ҳ����isspace()
      i++;
    }
  }
  printf(")");
}

void solve() {
  n = 0;
  for(;;) {
    fgets(buf[n], maxn, stdin);
    if(buf[n][0] == '#') break; else n++;
  }
  printf("(");
  if(n) {
    for(int i = 0; i < strlen(buf[0]); i++)
      if(buf[0][i] != ' ') { dfs(0, i); break; }
  }
  printf(")\n");
}

int main() {
  int T;
  fgets(buf[0], maxn, stdin);
  sscanf(buf[0], "%d", &T);
  while(T--) solve();
  return 0;
}
