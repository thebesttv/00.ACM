// Tag: 树形DP
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e5 + 20;
const int INF = 0x3f3f3f3f;
int n,m,mid,dp[MAX];
struct Edge { int v,w; };
VR<Edge> G[MAX];

int f(int u, int fa){
  int &a = dp[u];
  if(a!=-1) return a;
  bool leaf = true; a = 0;
  for(Edge e : G[u]) if(e.v!=fa){
    leaf = false;
    int t = min(e.w > mid ? INF : e.w, f(e.v, u));
    if(t >= INF) { a = INF; break; }
    a += t;
  }
  if(leaf) a = INF;
#ifdef DEBUG
  printf("mid: %d, f(%d): %d\n",mid,u,a);
#endif
  return a;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,1,n){
    scanf("%d%d%d",&u,&v,&w);
    G[u].pb({v,w}), G[v].pb({u,w});
  }
  int l = 1, r =1e3+10;
  while(l < r){
    mid = (l+r)/2; MST(dp,-1);
    if(f(1,-1) <= m) r = mid;
    else l = mid+1;
  }
  printf("%d\n",l > 1000 ? -1 : l);

  return 0;
}
