// Tag: 二分图最大独立集 i
// 一个字符串必须经过偶数次swap才可变回自己，因此仅存在 swap-free 图的反图仅存在偶环，即可黑白染色后求二分图最大独立集，答案即为 n - 独立集大小
#include<cassert>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 520;
int n,m,c[MAX],no[MAX]; char s[MAX][30];
bool G[MAX][MAX];

struct augment_path{
  vector<vector<int>> g;
  vector<int> pa;  // 匹配
  vector<int> pb;
  vector<int> vis;  // 访问
  int n, m;         // 顶点和边的数量
  int dfn;          // 时间戳记
  int res;          // 匹配数

  augment_path(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    vis = vector<int>(n);
    g.resize(n);
    res = 0; dfn = 0;
  }

  void add(int from, int to) {
#ifdef DEBUG
    printf("(%d) add %d %d\n",n,from,to);
#endif
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }

  bool dfs(int v) {
    vis[v] = dfn;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pb[u] = v;
        pa[v] = u;
        return true;
      }
    }
    for (int u : g[v]) {
      if (vis[pb[u]] != dfn && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }

  int solve() {
    while (true) {
      dfn++;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          cnt++;
        }
      }
      if (cnt == 0) {
        break;
      }
      res += cnt;
    }
    return res;
  }
};

bool ok(char *s1, char *s2){
  int c = 0;
  FOR(i,0,m) c += s1[i] != s2[i];
  return c >= 3;
}

void dfs(int u, int color){
  c[u] = color;
  FORR(v,1,n) if(G[u][v] && !c[v]){
    dfs(v, -color);
  }
}

int main(void){
  scanf("%d",&n); FORR(i,1,n) scanf("%s",s[i]);
  m = strlen(s[1]);

  FORR(i,1,n) FORR(j,i+1,n)
    if(!ok(s[i],s[j])) G[i][j] = G[j][i] = 1;

  FORR(i,1,n) if(!c[i]) dfs(i, 1);
#ifdef DEBUG
  FORR(i,1,n){
    printf("c[%d]: %d,",i,c[i]);
    FORR(j,1,n) if(G[i][j]) printf(" %d",j); putchar('\n');
  }
#endif
  int c0 = 0, c1 = 0;
  FORR(i,1,n)
    if(c[i] == 1) no[i] = c0++;
    else no[i] = c1++;

  augment_path sg(c0, c1);
  FORR(i,1,n) if(c[i] == 1) FORR(j,1,n)
    if(c[j] == -1 && G[i][j]) sg.add(no[i],no[j]);

  printf("%d\n",n - sg.solve());

  return 0;
}
