// Tag: 拓扑 iiii
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
int n,m,c[MAX],pos[MAX],tail; VR<int> G[MAX];
struct Edge{
  int u,v,t;
}edge[MAX];

bool topo(int u){
  c[u] = -1;
  for(int v : G[u])
    if(c[v] == -1) return false;
    else if(!c[v] && !topo(v)) return false;
  pos[u] = tail--; c[u] = 1;
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    FORR(i,1,n) c[i]=0, G[i].clear();
    int t,u,v;
    FOR(i,0,m){
      scanf("%d%d%d",&t,&u,&v);
      edge[i] = {u,v,t};
      if(t) G[u].push_back(v);
    }

    bool bad = 0; tail = n;
    FORR(i,1,n) if(!c[i] && !topo(i)){
      bad = 1; break;
    }
    if(bad) { printf("NO\n"); continue; }

    printf("YES\n");
    FOR(i,0,m){
      Edge &e = edge[i];
      if(!e.t && pos[e.u] > pos[e.v])
        swap(e.u, e.v);
      printf("%d %d\n",e.u,e.v);
    }
  }

  return 0;
}
