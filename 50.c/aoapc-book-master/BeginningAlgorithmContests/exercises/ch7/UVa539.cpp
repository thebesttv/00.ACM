// UVa539 The Settlers of Catan
// Rujia Liu
// ���⣺����n������m���ߵ�����ͼ����һ����ͨ�������·�ĳ��ȡ��߲��ܾ������Σ����Ƕ�������ظ�����
// ���ƣ�2<=n<=25, 1<=m<=25��û���Ի����ر�
// �㷨��DFS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 25 + 5;
int n, m, G[maxn][maxn];

// ���ش�u�������·����
int dfs(int u) {
  int ans = 0;
  for(int v = 0; v < n; v++) if(G[u][v]) {
    G[u][v] = G[v][u] = 0;
    ans = max(ans, dfs(v) + 1);
    G[u][v] = G[v][u] = 1;
  }
  return ans;
}

int main() {
  while(scanf("%d%d", &n, &m) == 2 && n) {
    memset(G, 0, sizeof(G));
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v); G[u][v] = G[v][u] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
      ans = max(ans, dfs(i));
    printf("%d\n", ans);
  }
  return 0;
}
