// Tag: DFS 剪枝 状压DP iii
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
#define FGR(i,a,b) for(i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define FGRR(i,a,b) for(i=(a);i<=(b);++i)
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

const int INF = 0x3f3f3f3f;
const int MAX = 20;
int n,m,G[MAX][MAX],g[1<<12][1<<12],dp[1<<12][MAX];
// f[st][dep]: 目前已有 st 个点在树上，当前层数为 dep
// g[st1][st2] 从 st1 到 st2 所需的最小代价，即 st2 - st1 中每个点向 st1 连一条最小边

int f(int st, int dep){
  int &a = dp[st][dep];
  if(a!=-1) return a;
  if(!dep) return a=INF;
  a = INF;
  for(int st2=(st-1)&st; st2; st2=(st2-1)&st){
    if(f(st2, dep-1) == INF || g[st2][st] == INF) continue;
    a = min(a, f(st2, dep-1) + g[st2][st] * dep);
  }
  return a;
}

int main(void){
  MST(G,0x3f); scanf("%d%d",&n,&m);
  int u,v,w;
  while(m--){
    scanf("%d%d%d",&u,&v,&w); --u, --v;
    G[u][v] = G[v][u] = min(G[u][v], w);
  }

  // 预处理g
  MST(g,0x3f); int full = (1<<n)-1;
  FOR(st,1,1<<n){
    int comp = full ^ st, a[MAX];
    VR<int> vec; FOR(i,0,n) if(st&(1<<i)) vec.pb(i);
    FOR(u,0,n) if(comp&(1<<u)){
      int tMin = INF;
      for(int v : vec) tMin = min(tMin, G[u][v]);
      a[u] = tMin;
    }
    for(int st2=comp;st2;st2=(st2-1)&comp){
      LL sum = 0; FOR(i,0,n) if(st2&(1<<i)) sum += a[i];
      g[st][st|st2] = min((LL)INF, sum);
    }
  }

  /*
  FOR(st2,1,1<<n) for(int st1=(st2-1)&st2; st1; st1=(st1-1)&st2){
    int dif = st1 ^ st2, sum = 0;
    VR<int> vec; FOR(i,0,n) if(st1&(1<<i)) vec.pb(i);
    FOR(u,0,n) if(dif&(1<<u)){
      int tMin = INF;
      for(int v : vec) tMin = min(tMin, G[u][v]);
      if(tMin == INF) { sum = INF; break; }
      sum += tMin;
    }
    g[st1][st2] = sum;
  }
  */
#ifdef DEBUG
  printf("preprocess done\n");
#endif

  MST(dp,-1);
  FOR(i,0,n) dp[1<<i][0] = 0;
  int ansMin = INF;
  FORR(i,0,n) ansMin = min(ansMin, f((1<<n)-1, i));
  printf("%d\n",ansMin);

  return 0;
}

/*
// DFS 剪枝
// 考虑每个 v 从哪个 u 扩展过来，即枚举 v 的父节点
// 按照深度递增的顺序枚举，这样可以加上剪枝
const int INF = 0x3f3f3f3f;
const int MAX = 20;
int n,m,g[MAX][MAX];
int dep[MAX],r[MAX],ansMin=INF,lft; // lft: 剩下节点可选的最优边权和
struct Edge{
  int v,w;
  bool operator < (const Edge &b) const {
    return w < b.w;
  }
};
VR<Edge> G[MAX];

void dfs(int cur, int start, int sum){  // 从 r[start : cur] 扩展，层数递增
  if(sum >= ansMin) return;
  if(cur == n) { ansMin = sum; return; }
  for(int i=start, u=r[i]; i<=cur; u=r[++i]){
    if(sum + lft * dep[u] >= ansMin) return;  // 剪枝
    for(Edge &e : G[u]) if(!dep[e.v]){
      lft -= G[e.v][0].w;
      dep[e.v] = dep[u] + 1; r[cur+1] = e.v;
      dfs(cur+1, i, sum + dep[u] * e.w);
      dep[e.v] = 0;
      lft += G[e.v][0].w;
    }
  }
}

int main(void){
  MST(g,0x3f); scanf("%d%d",&n,&m);
  if(n == 1) { printf("0\n"); return 0; }
  while(m--){
    int u,v,w; scanf("%d%d%d",&u,&v,&w);
    g[u][v] = g[v][u] = min(g[u][v], w);
  }
  FORR(i,1,n) FORR(j,1,n) if(g[i][j]!=INF)
    G[i].pb({j, g[i][j]});
  FORR(u,1,n) sort(ALL(G[u])), lft += G[u][0].w;

  FORR(i,1,n){
    lft -= G[i][0].w;
    dep[i]=1, r[1]=i;
    dfs(1,1,0);
    dep[i]=0;
    lft += G[i][0].w;
  }
  printf("%d\n",ansMin);

  return 0;
}
*/

/*
// XXX TODO
   const LL INF = 0x3f3f3f3f3f3f3f3f;
   int n,m,G[20][20],root;
   LL dp[1<<12][14][14];
// f[st][u][d]: 起点为root，当前访问过的为st，上一个访问的为u，u的深度为d
// 若d为0则表示根

LL f(int st, int u, int d){
LL &a = dp[st][u][d];
if(a!=-1) return a;

a = INF;

if(!d){
if(u!=root) return a = INF;

FORR(v,1,n) if(u!=v && (st&(1<<(v-1)))) FORR(dd,1,n){
#ifdef DEBUG
if(f(st,v,dd)!=INF){
printf("f(");
FOR(i,0,n) putchar('0' + ((st>>i)&1));
printf(", %d, %d) <- f(..., %d, %d): %lld\n",u,d,v,dd,f(st,v,dd));
}
#endif
a = min(a, f(st, v, dd));
}
}else{
FORR(v,1,n) if(u!=v && (st&(1<<(v-1))) && G[u][v]!=INF){
#ifdef DEBUG
if(f(st & (~(1<<(u-1))), v, d-1)!=INF){
printf("f(");
FOR(i,0,n) putchar('0' + ((st>>i)&1));
printf(", %d, %d) <- f(",u,d);
FOR(i,0,n) putchar('0' + (((st & (~(1<<(u-1))))>>i)&1));
printf(", %d, %d)(%lld) + %d\n",v,d-1,f(st & (~(1<<(u-1))), v, d-1), G[u][v]*d);
}
#endif
a = min(a, f(st & (~(1<<(u-1))), v, d-1) + 1ll*G[u][v] * d);
}
}
#ifdef DEBUG
if(a!=INF){
printf("f(");
FOR(i,0,n) putchar('0' + ((st>>i)&1));
printf(", %d, %d): %lld\n",u,d,a);
}
#endif
return a;
}

int main(void){
MST(G,0x3f);
scanf("%d%d",&n,&m);
while(m--){
int u,v,w; scanf("%d%d%d",&u,&v,&w);
G[u][v] = G[v][u] = min(G[u][v], w);
}
#ifdef DEBUG
FORR(u,1,n) FORR(v,u+1,n) if(G[u][v] != 0x3f3f3f3f)
printf("G[%d][%d]: %d\n",u,v,G[u][v]);
#endif

LL ansMin = INF; int st = (1<<n)-1;
FGRR(root,1,n){ // 枚举起点
#ifdef DEBUG
printf("root: %d\n",root);
#endif
MST(dp,-1); dp[1<<(root-1)][root][0] = 0;
ansMin = min(ansMin, f(st, root, 0));
}

printf("%lld\n",ansMin);

return 0;
}
*/
