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
int n,m,cnt1=0;
struct Edge{
  int v, no, col;
};
VR<Edge> G[MAX];
bool vis[MAX];

void dfs(int u){
  vis[u] = 1;
  for(Edge &e : G[u])
    if(!vis[e.v]){
      e.col = 1; ++cnt1;
    }else{
      e.col = -1;
    }

  for(Edge e : G[u]) if(!vis[e.v])
    dfs(e.v);
}

int main(void){
  scanf("%d%d",&n,&m);
  int u, v;
  FORR(i,1,m){
    scanf("%d%d",&u,&v);
    G[u].push_back({v,i,0});
  }

  FORR(i,1,n) if(!vis[i])
    dfs(i);

  int col,ans;
  if(cnt1<=m/2) col = 1, ans = cnt1;
  else col = -1, ans = m - cnt1;

  printf("%d\n",ans);
  FORR(i,1,n) for(Edge e : G[i])
    if(e.col==col) printf("%d\n",e.no);

  return 0;
}
