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

const int MAX = 1e6 + 20;
int n;
VR<int> G[MAX];
VR<pii> ans;

int dfs(int u){
  if(!G[u].size())
    return u;
  if(G[u].size()==1)
    return dfs(G[u][0]);

  int last=0;
  for(int v : G[u]){
    if(last) ans.push_back({last,v});
    last = dfs(v);
  }
  return last;
}

int fa[MAX];
int p(int u){
  return fa[u]<0 ? u : fa[u] = p(fa[u]);
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FORR(i,1,n){
      G[i].clear();
      fa[i] = -1;
    }
    ans.clear();

    int u,v;
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
      fa[v] = u;
    }
    int r = p(1);

    dfs(r);
    printf("Case %d: %d\n",kase,(int)ans.size());
    for(auto p : ans){
      printf("%d %d\n",p.FI,p.SE);
    }
  }

  return 0;
}
