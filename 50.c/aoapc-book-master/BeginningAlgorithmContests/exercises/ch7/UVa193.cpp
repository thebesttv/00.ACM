// UVa193 Graph Coloring
// Rujia Liu
// ���⣺��ͼ���������������Ѿ�����Ľ��ͼ��ʹ�����������ڵ㲻����
// �㷨�����ݡ�������ͨ��ά��ÿ���㡰���ںڵ�ĸ�������Ϣ�������ж�

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 100 + 5;

vector<int> G[maxn];
int n, ans, black[maxn], black_adjcnt[maxn], node[maxn];

void dfs(int u, int cnt) {
  if(u == n+1) {
    if(cnt > ans) {
      int c = 0;
      for(int i = 1; i <= n; i++) if(black[i]) node[c++] = i;
      ans = cnt;
    }
    return;
  }
  if(cnt + n - u + 1 <= ans) return; // ��֦

  // �ȳ���Ϳ��
  if(black_adjcnt[u] == 0) {
    for(int i = 0; i < G[u].size(); i++) black_adjcnt[G[u][i]]++;
    black[u] = 1;
    dfs(u+1, cnt+1);
    for(int i = 0; i < G[u].size(); i++) black_adjcnt[G[u][i]]--;
  }
  // ���ǿ���Ϳ��
  black[u] = 0;
  dfs(u+1, cnt);
}

int main() {
  int T, m;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 0; i < m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      G[x].push_back(y);
      G[y].push_back(x);
    }
    memset(black_adjcnt, 0, sizeof(black_adjcnt));
    ans = 0;
    dfs(1, 0);
    printf("%d\n", ans);
    for(int i = 0; i < ans-1; i++) printf("%d ", node[i]);
    printf("%d\n", node[ans-1]);
  }
  return 0;
}
