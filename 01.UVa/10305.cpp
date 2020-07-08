// Tag: 拓扑
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

const int MAX = 120;
int n,m,c[MAX],ans[MAX],tail;
VR<int> G[MAX];

bool dfs(int u){
  c[u] = -1;
  for(int v : G[u])
    if(c[v] == -1) return false;
    else if(!c[v] && !dfs(v)) return false;
  c[u] = 1; ans[tail--] = u;
  return true;
}

bool topo(){
  tail = n;
  FORR(i,1,n) if(!c[i])
    if(!dfs(i)) return false;
  return true;
}

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    FORR(i,1,n) G[i].clear(); MST(c,0);
    int u,v;
    while(m--){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
    }

    if(topo()){
      FORR(i,1,n) printf("%d ",ans[i]);
      putchar('\n');
    }
  }

  return 0;
}

/*
const int MAX = 120;
int n,m,to[MAX];
VR<int> G[MAX];

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    FORR(i,1,n) G[i].clear(); MST(to,0);
    int u,v;
    while(m--){
      scanf("%d%d",&u,&v);
      G[u].push_back(v); ++to[v];
    }
    queue<int> q;
    FORR(i,1,n) if(!to[i]) q.push(i);

    while(!q.empty()){
      u = q.front(); q.pop();
      printf("%d ",u);
      for(int v : G[u]) if(--to[v] == 0){
        q.push(v);
      }
    }
    putchar('\n');
  }

  return 0;
}
*/
