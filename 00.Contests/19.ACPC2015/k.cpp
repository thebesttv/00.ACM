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

const int MAX = 10020;
int n;
int dMax, r;
VR<int> G[MAX];
bool vis[MAX];

void dfs(int u, int dep){
  vis[u] = 1;
  if(dep>dMax){
    dMax = dep, r = u;
  }
  for(int v : G[u]) if(!vis[v]){
    dfs(v, dep+1);
  }
}

int main(void){
  int T,u,v; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) G[i].clear();
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);
    }

    if(n<=3){
      printf("0\n"); continue;
    }

    MST(vis,0); dMax=0, r=-1;
    dfs(1,0);
#ifdef DEBUG
    printf("  from root: %d, dep: %d\n",r,dMax);
#endif

    MST(vis,0); dMax=0;
    dfs(r,0);
#ifdef DEBUG
    printf("    then: %d, dep: %d\n",r,dMax);
#endif

    printf("%d\n",n-1-dMax);
  }

  return 0;
}
