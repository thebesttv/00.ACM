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
int n,a[MAX],f[MAX],g[MAX];
VR<int> G[MAX];
bool vis[MAX];

void dfs1(int u){
  vis[u] = 1; int s = 0;
  for(int v : G[u]) if(!vis[v]){
    dfs1(v);
    if(f[v]>0) s += f[v];
  }
  f[u] = s + a[u];
}

void dfs2(int u, int p){
  vis[u] = 1;
  if(u!=1){
    /*
    if(f[u]>=0) g[u] = g[p];
    else g[u] = g[p]-1;
    */

    int up;
    if(f[u]>=0) up = g[p] - f[u];
    else up = g[p];
#ifdef DEBUG
    printf("  u: %d, up: %d\n",u,up);
#endif
    g[u] = f[u] + max(up,0);
  }else{
    g[u] = f[u];
  }

  for(int v : G[u]) if(!vis[v])
    dfs2(v,u);
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    if(!a[i]) a[i]=-1;
  }
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs1(1);
  MST(vis,0);
  dfs2(1,0);

#ifdef DEBUG
  FORR(u,1,n) printf("  f[%d]: %d\n",u,f[u]);
#endif
  FORR(u,1,n){
    printf("%d ",g[u]);
  }
  putchar('\n');

  return 0;
}
