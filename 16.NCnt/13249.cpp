// Tag: TODO 贪心 树型DP ii
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
#include<map>
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

const int MAX = 1e5 + 20;
int n,f[MAX],g[MAX],h[MAX],ans;
// f[u]: 覆盖子树u的同时，能向上覆盖的最大长度
// g[u]: 子树u中节点能向上覆盖的最大长度，不一定覆盖子树u
VR<int> G[MAX];

void dfs(int u){
  g[u] = h[u];
  for(int v : G[u]){
    dfs(v);
    f[u] = max(f[u], f[v]-1);
    g[u] = max(g[u], g[v]-1);
  }
  if(!f[u]){
    f[u] = g[u]; ++ans;
  }
}

int main(void){
  scanf("%d",&n); int u;
  FORR(v,2,n) scanf("%d",&u), G[u].pb(v);
  FORR(i,1,n) scanf("%d",&h[i]);
  dfs(1);
  printf("%d\n",ans);

  return 0;
}
