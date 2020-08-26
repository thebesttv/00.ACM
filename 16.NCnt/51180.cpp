// Tag: 树型DP 换根
/*
   换根时注意特判根节点变成叶子的情况

   1
   5
   2 1 10
   2 3 10
   2 4 10
   2 5 10
*/

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

const int MAX = 200020;
const int INF = 0x3f3f3f3f;
int n; LL f[MAX],g[MAX];
struct Edge { int v,w; };
VR<Edge> G[MAX];

LL dfs1(int u, int fa){
  LL &a = f[u];
  if(G[u].size()==1 && G[u][0].v == fa){  // leaf
    return a = INF;
  }
  for(Edge &e : G[u]) if(e.v!=fa){
    a += min((LL)e.w, dfs1(e.v,u));
  }
  return a;
}

void dfs2(int u, int fa){
  if(u == 1 && G[1].size()==1){  // 换根后，1变为叶子
    for(Edge &e : G[u]) if(e.v!=fa){
      g[e.v] = e.w; dfs2(e.v, u);
    }
    return;
  }
  for(Edge &e : G[u]) if(e.v!=fa){
    g[e.v] = min((LL)e.w, f[u] - min((LL)e.w, f[e.v]) + g[u]);
    dfs2(e.v, u);
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) G[i].clear(), f[i]=g[i]=0;
    int u,v,w;
    FOR(i,1,n){
      scanf("%d%d%d",&u,&v,&w);
      G[u].pb({v,w}), G[v].pb({u,w});
    }
    dfs1(1,-1), dfs2(1,-1);
    LL ansMax = 0;
    FORR(i,1,n){
#ifdef DEBUG
      printf("%d: f: %lld, g: %lld\n",i,f[i],g[i]);
#endif
      ansMax = max(ansMax, (f[i]==INF ? 0 : f[i]) + g[i]);
    }
    printf("%lld\n",ansMax);
  }

  return 0;
}
