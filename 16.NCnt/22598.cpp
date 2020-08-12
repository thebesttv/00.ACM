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
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n,m,rt; LL dp[MAX];
struct Edge { int v; LL w; };
VR<Edge> G[MAX];

LL f(int u, int fa){
  LL &a = dp[u];
  if(a!=-1) return a;
  bool leaf = true; a = 0;
  for(Edge e : G[u]) if(e.v!=fa)
    a += min(e.w, f(e.v,u)), leaf = false;
  if(leaf) a = INF;
  return a;
}

int main(void){
  MST(dp,-1);
  scanf("%d%d%d",&n,&m,&rt);
  int u,v; LL w;
  FORR(i,1,m){
    scanf("%d%d%lld",&u,&v,&w);
    G[u].pb({v,w}), G[v].pb({u,w});
  }

  printf("%lld\n",f(rt,-1));

  return 0;
}
