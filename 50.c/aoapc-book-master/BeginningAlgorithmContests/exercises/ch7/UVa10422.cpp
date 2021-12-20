// UVa10422 Knights in FEN
// Rujia Liu
// ���⣺ 5x5������12������12�������1���ո�ÿ�ο��԰�һ�����ƶ����ո��У����ع�������������ƶ����򣩡�
// �����ٲ��������̱��һ���ض����ӣ�����ͼ�������10�����޽�������޽�
// �㷨��IDA*����������Ϊ���������d����û�ߵ�Ŀ��λ�ã����ٻ�Ҫd��

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dmax;
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
const char* goal[] = {"11111", "01111", "00 11", "00001", "00000"};
char board[6][6];
int sx, sy;

int solution_diff() {
  int d = 0;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      if(goal[i][j] != board[i][j] && board[i][j] != ' ') d++;
  return d;
}

// dfs�������غ�(board, sx, sy)���ֲ���
bool dfs(int d) {
  int diff = solution_diff();
  if(diff == 0) return true;
  if(d + diff > dmax) return false; // IDA*��֦
  for(int i = 0; i < 8; i++) {
    int nx = sx + dx[i];
    int ny = sy + dy[i];
    if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
      swap(board[sx][sy], board[nx][ny]);
      swap(sx, nx); swap(sy, ny);
      bool ans = dfs(d+1);
      swap(sx, nx); swap(sy, ny);
      swap(board[sx][sy], board[nx][ny]);
      if(ans) return true;
    }
  }
  return false;
}

void solve() {
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      if(board[i][j] == ' ') { sx = i; sy = j; }
  for(dmax = 0; dmax <= 10; dmax++)
    if(dfs(0)) { printf("Solvable in %d move(s).\n", dmax); return; }
  printf("Unsolvable in less than 11 move(s).\n");  
}

int main() {
  int T;
  scanf("%d\n", &T);
  while(T--) {
    for(int i = 0; i < 5; i++) fgets(board[i], 10, stdin);
    solve();
  }
  return 0;
}

