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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10020;
const int MOD=1000000007;
int n;
struct Edge{
  int v,d;
  Edge() { }
  Edge(int v, int d): v(v), d(d) { }
};
VR<Edge> to[MAX];
bool vis[MAX];
int ans[3];

void dfs(int u, int d){
  vis[u]=1;
  if(d) ans[d%3] = (ans[d%3]+d)%MOD;
  for(Edge e: to[u]) if(!vis[e.v]){
    dfs(e.v, d+e.d);
  }
}

int main(void){
  while(scanf("%d",&n)==1){
    FOR(i,0,n) to[i].clear();
    ans[0]=ans[1]=ans[2]=0;
    int u,v,d;
    FOR(i,1,n){
      scanf("%d%d%d",&u,&v,&d);
      to[u].push_back(Edge(v,d));
      to[v].push_back(Edge(u,d));
    }
    FOR(i,0,n){
      MST(vis,0); dfs(i,0);
    }
    printf("%d %d %d\n",ans[0],ans[1],ans[2]);
  }

  return 0;
}
