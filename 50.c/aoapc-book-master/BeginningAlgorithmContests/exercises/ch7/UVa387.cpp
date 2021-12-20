// UVa387 A Puzzling Problem
// Rujia Liu
// ���⣺��n����ľ��ƴ��һ��4*4�������Σ�Ҫ��ÿ����ǡ����һ�Σ�������ת���߷�ת��������һ������
// �㷨������д���кܶ࣬���ڹ�ģ�ǳ�С���������һ��Ч�ʲ���ߵ��Ϻ�ʵ�ֵķ�����ÿ������ѡһ�����û�ľ����ö��һ��λ�÷���ȥ

#include<cstdio>
#include<cstring>
const int maxn = 5;
int n;
int board[5][5]; // Ҫƴ����������

struct Piece {
  int r, c, size;
  char data[maxn][maxn];
  void read() {
    size = 0;
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++) {
      scanf("%s", data[i]);
      for(int j = 0; j < c; j++) if(data[i][j] == '1') size++;
    }
  }
  bool can_place(int x, int y) {
    if(x+r > 4 || y+c > 4) return false;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        if(data[i][j] == '1' && board[x+i][y+j] != 0) return false;
    return true;
  }
  void fill(int x, int y, int v) {
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        if(data[i][j] == '1') board[x+i][y+j] = v;
  }
} pieces[5];

int vis[5];
bool dfs(int d) {
  if(d == n) return true;
  for(int i = 0; i < n; i++) if(!vis[i]) {
    vis[i] = 1;
    for(int x = 0; x < 4; x++)
      for(int y = 0; y < 4; y++)
        if(pieces[i].can_place(x, y)) {
          pieces[i].fill(x, y, i+1);
          if(dfs(d+1)) return true;
          pieces[i].fill(x, y, 0);
        }
    vis[i] = 0;
  }
  return false;
}

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1 && n) {
    if(kase++) printf("\n");
    memset(board, 0, sizeof(board));
    memset(vis, 0, sizeof(vis));
    int tot = 0;
    for(int i = 0; i < n; i++) {
      pieces[i].read();
      tot += pieces[i].size;
    }
    if(tot != 16 || !dfs(0)) printf("No solution possible\n");
    else {
      for(int i = 0; i < 4; i++)
        printf("%d%d%d%d\n", board[i][0], board[i][1], board[i][2], board[i][3]);
    }
  }
  return 0;
}
