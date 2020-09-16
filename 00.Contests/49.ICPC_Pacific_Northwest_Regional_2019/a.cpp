// Tag: 树形DP
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
struct Edge { int v,w; };
int n,t[MAX],f[MAX]; LL g[MAX]; VR<Edge> G[MAX];
LL ans[MAX], l, r;

int dfs1(int u, int d, int fa){
  l += d; r += 1ll * t[u] * d;

  int &a = f[u]; a = 1;
  LL &b = g[u]; b = t[u];
  for(Edge &e : G[u]) if(e.v!=fa){
    a += dfs1(e.v, d + e.w, u); b += g[e.v];
  }
  return a;
}

void dfs2(int u, LL l, LL r, int fa){
  ans[u] = t[u] * l + r;
  for(Edge &e : G[u]) if(e.v!=fa){
    dfs2(e.v, l - f[e.v] * e.w + (n - f[e.v]) * e.w,
            r - g[e.v] * e.w + (g[1] - g[e.v]) * e.w,
            u);
  }
}

int main(void){
  scanf("%d",&n); FORR(i,1,n) scanf("%d",&t[i]);
  FOR(i,1,n){
    int u,v,w; scanf("%d%d%d",&u,&v,&w);
    G[u].pb(Edge{v,w}); G[v].pb(Edge{u,w});
  }
  dfs1(1,0,-1);
  dfs2(1,l,r,-1);
  FORR(i,1,n) printf("%lld\n",ans[i]);

  return 0;
}
