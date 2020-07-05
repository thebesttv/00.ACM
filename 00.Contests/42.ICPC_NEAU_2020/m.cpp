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
int n,ans,s[MAX]; bool vis[MAX];
struct Edge { int v,w; };
VR<Edge> G[MAX];

int dfs(int u){
  vis[u] = 1; s[u] = 1;
  for(Edge e : G[u]) if(!vis[e.v]){
    s[u] += dfs(e.v);
    if((s[e.v] & 1) && ((n-s[e.v])&1)){
      ans ^= e.w;
    }
  }
  return s[u];
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    ans = 0;
    scanf("%d",&n);
    FORR(i,1,n) vis[i] = 0, G[i].clear();
    int u,v,w;
    FOR(i,1,n){
      scanf("%d%d%d",&u,&v,&w);
      G[u].push_back({v,w});
      G[v].push_back({u,w});
    }

    dfs(1);
    printf("%d\n",ans);
  }

  return 0;
}
