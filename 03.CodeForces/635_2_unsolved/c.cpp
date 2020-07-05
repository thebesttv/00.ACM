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

const int MAX = 2e5 + 20;
int n, k, f[MAX], cnt[MAX], dep[MAX], fa[MAX];
VR<int> G[MAX], leaves;

struct Node{
  int u, cost, gain;
  bool operator < (const Node &b) const {
    return gain - cost < b.gain - b.cost;
  }
};
PQ<Node> q;

void dfs(int u, int d, int p){
  dep[u] = d, fa[u] = p;
  int &c = cnt[u];
  for(int v : G[u]) if(dep[v] == -1){
    dfs(v, d+1, u); ++c;
  }
  if(!c) leaves.push_back(u);
}

int main(void){
  scanf("%d%d",&n,&k); int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  MST(dep,-1);
  dfs(1, 0, -1);

  for(int u : leaves)
    q.push({u, 0, dep[u]});

  LL ans = 0;
  FORR(i,1,k){
    Node t = q.top(); q.pop();
#ifdef DEBUG
    printf("  %dth: u: %d, cost: %d, gain: %d\n",i,t.u,t.cost,t.gain);
#endif
    u = t.u, v = fa[t.u];
    ans += t.gain - t.cost;
    ++f[u]; --cnt[v];
    if(!cnt[v]){
      int sum = 0;
      for(int u : G[v]) if(dep[u] > dep[v]){
        sum += f[u];
      }
      f[v] = sum;
#ifdef DEBUG
      printf("  push node %d, cost: %d, gain: %d\n",v,sum,dep[v]);
#endif
      q.push({v, sum, dep[v]});
    }
  }
  printf("%lld\n",ans);

  return 0;
}
