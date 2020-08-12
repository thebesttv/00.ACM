// Tag: 树形DP TODO
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

const int MAX = 120;
const int INF = 0x3f3f3f3f;
int n,m,dp[MAX][MAX];
struct Edge { int v,w; };
VR<Edge> G[MAX];

int f(int u, int m, int fa){
  int &a = dp[u][m];
  if(a!=-1) return a;
  if(!m) return a=0;

  if(G[u].size()==1)  // leaf && m!=0
    return a = -INF;

  a = 0; Edge e1,e2;
  if(G[u].size() == 2) e1 = G[u][0], e2 = G[u][1];
  else FOR(i,0,G[u].size()) if(G[u][i].v==fa)
    e1 = G[u][(i+1)%3], e2 = G[u][(i+2)%3];

  a = max( f(e1.v,m-1,u) + e1.w, f(e2.v,m-1,u) + e2.w);
  FORR(i,0,m-2) a = max(a, f(e1.v,i,u) + f(e2.v,m-2-i,u) + e1.w + e2.w);
#ifdef DEBUG
  printf("f(%d, %d, %d): %d\n",u,m,fa,a);
#endif
  return a;
}

int main(void){
  MST(dp,-1);
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,1,n){
    scanf("%d%d%d",&u,&v,&w);
    G[u].pb({v,w}); G[v].pb({u,w});
  }
  printf("%d\n",f(1,m,-1));

  return 0;
}
