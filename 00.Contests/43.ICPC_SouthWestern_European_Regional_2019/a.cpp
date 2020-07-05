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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1020;
const int INF = 0x3f3f3f3f;
int n,sx,sy,ex,ey,b,c[MAX];
int dp[MAX][102], dis[MAX][MAX];
pii p[MAX];
struct Edge { int v, mod; };
VR<Edge> G[MAX];

int f(int u, int b){
  if(b > 100) return INF;
  int &a = dp[u][b];
  if(a!=-1) return a;
  a = INF;

  for(Edge &e : G[u]){
    int d = dis[u][e.v];
    if(d > b) continue;
    a = min(a, f(e.v, b-d) + d * c[e.mod]);
  }
#ifdef DEBUG
  if(a != INF) printf("  f[%d][%d]: %d\n",u,b,a);
#endif
  return a;
}

int getDis(int u, int v){
  int dx = p[u].FI - p[v].FI,
      dy = p[u].SE - p[v].SE;
  return ceil(sqrt(dx*dx + dy*dy));
}

int main(void){
  MST(dp,-1);
  scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
  scanf("%d%d",&b,&c[0]);
  int t; scanf("%d",&t);
  FORR(i,1,t) scanf("%d",&c[i]);

  scanf("%d",&n); n += 2;
  p[1] = {sx, sy}; p[n] = {ex, ey};
  // G[1].push_back({n,0});
  G[n].push_back({1,0});

  FOR(u,2,n){
    scanf("%d%d%d",&p[u].FI,&p[u].SE,&t);
    int v, mod;
    while(t--){
      scanf("%d%d",&v,&mod); v += 2;
      G[u].push_back({v,mod});
      G[v].push_back({u,mod});
    }
    // G[1].push_back({u,0});
    // G[u].push_back({n,0});
    G[u].push_back({1,0});
    G[n].push_back({u,0});
  }
  FORR(i,1,n) FORR(j,i+1,n)
    dis[i][j] = dis[j][i] = getDis(i,j);

  FORR(i,0,b) dp[1][i] = 0;
  int ansMin = INF;
  FORR(i,0,b) ansMin = min(ansMin, f(n,i));
  printf("%d\n",ansMin == INF ? -1 : ansMin);

  return 0;
}
