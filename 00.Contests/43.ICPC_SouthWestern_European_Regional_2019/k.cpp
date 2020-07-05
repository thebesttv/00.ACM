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

const int MAX = 1e5 + 20;
int n,m,t;
VR<int> G[MAX];
int vis[MAX];
queue<pii> q;

int main(void){
  scanf("%d%d%d",&n,&m,&t);
  int u,v;
  while(m--){
    scanf("%d%d",&v,&u);
    G[u].push_back(v);
  }
  vis[t] = 1; q.push({t,t});
  while(!q.empty()){
    u = q.front().FI;
    int fa = q.front().SE;
    q.pop();

    int d = vis[u] + 1;
    for(int v : G[u]) if(v!=fa){
      if(!vis[v]) q.push({v, fa == t ? u : fa});
      vis[v] = max(vis[v], d);
    }
  }
#ifdef DEBUG
  FOR(i,0,n) printf("  d[%d]: %d\n",i,vis[i]-1);
#endif
  VR<int> ans;
  for(int v : G[t]) if(vis[v]==2)
    ans.push_back(v);
  printf("%d\n",ans.size());
  for(int x : ans) printf("%d\n",x);

  return 0;
}
