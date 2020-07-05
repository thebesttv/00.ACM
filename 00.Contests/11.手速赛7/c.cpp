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
typedef pair<LL,LL> pii;

const int MAX = 5e5 + 20;
int n,k; LL dp[MAX][2];

struct Edge{
  int v, w;
};
VR<Edge> G[MAX];

LL getBest(VR<pii> &v, int k){
  LL ans = 0;
  for(auto & p : v){
    ans += p.FI;  // not choose
    p.FI = p.SE - p.FI; // delta
    p.SE = 0;
  }

  sort(ALL(v), [](pii &a, pii &b){
      return a.FI > b.FI;
      });
  for(auto p : v){
    if(p.FI<0) break;
    if(!k) break;
    ans += p.FI; --k;
  }
  return ans;
}

LL f(int u, int st, int fa){
  LL &a = dp[u][st];
  if(a!=-1) return a;
  a = 0;
  int k = ::k - st;
  VR<pii> v;
  for(Edge e : G[u]) if(e.v != fa){
    //v.push_back({e.v, 0, f(e.v,0, u)});
    //v.push_back({e.v, 1, f(e.v,1, u) + e.w});
    v.push_back({f(e.v,0, u), f(e.v,1, u) + e.w});
  }
  a = getBest(v, k);
#ifdef DEBUG
  printf(" f(%d, %d): %lld\n",u,st,a);
#endif
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    FORR(i,1,n){
      dp[i][0] = dp[i][1] = -1;
      // vis[i] = 0;
      G[i].clear();
    }

    int u, v, w;
    FOR(i,1,n){
      scanf("%d%d%d",&u,&v,&w);
      G[u].push_back({v,w});
      G[v].push_back({u,w});
    }

    printf("%lld\n", f(1,0,-1));
  }

  return 0;
}
