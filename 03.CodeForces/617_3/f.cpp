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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 5020, INF=1e6;
int n, m, f[MAX];

int E[MAX][MAX];  // index of edge (u,v)
VR<int> G[MAX];
int p[MAX][MAX];
void dfs(int u, int pv, int root){
  p[root][u]=pv;
  for(int v : G[u]) if(v!=pv){
    dfs(v,u,root);
  }
}

struct Query{
  int u,v,g;
  bool operator < (const Query &b) const {
    return g < b.g;
  }
}Q[MAX];

void mark(int root, int v, int g){
  int u;
  while(v!=root){
    u = p[root][v];
    f[E[u][v]] = max(f[E[u][v]], g);
    v = u;
  }
}

int qMin(int root, int v){
  int u,tMin = INF;
  while(v!=root){
    u = p[root][v];
    tMin = min(tMin, f[E[u][v]]);
    v = u;
  }
  return tMin;
}

int main(void){
  scanf("%d",&n);
  int u, v, g;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    E[u][v]=E[v][u]=i;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  FORR(i,1,n) dfs(i,0,i);

  scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d%d",&Q[i].u,&Q[i].v,&Q[i].g);
  }
  sort(Q,Q+m);
  FOR(i,0,m) mark(Q[i].u, Q[i].v, Q[i].g);

  bool ok = 1;
  FOR(i,0,m) if(qMin(Q[i].u,Q[i].v)!=Q[i].g){
    ok = 0; break;
  }

  if(ok) FOR(i,1,n) printf("%d ",f[i] ? f[i] : INF);
  else printf("-1");
  putchar('\n');

  return 0;
}

/*
const int MAX=5020, INF=1e6;
int n,m;

int f[MAX];
int G[MAX][MAX];
VR<int> to[MAX];

int p[MAX][MAX];
int vis[MAX], col;
void dfs(int u, int root){
  vis[u] = col;
  for(int v : to[u]) if(vis[v]!=col){
    p[root][v] = u;
    dfs(v, root);
  }
}

struct Q{
  int u,v,g;
  bool operator < (const Q &b) const {
    return g < b.g;
  }
}q[MAX];

void mark(int root, int v, int g){
  int u;
  while(v != root){
    u = p[root][v];
    f[G[u][v]] = max(f[G[u][v]], g);
    v = u;
  }
}

int qMin(int root, int v){
  int u, tMin = INF;
  while(v!=root){
    u = p[root][v];
    tMin = min(tMin, f[G[u][v]]);
    v = u;
  }
  return tMin;
}

int main(void){
  scanf("%d",&n);
  int u, v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u][v] = G[v][u] = i;
    to[u].push_back(v);
    to[v].push_back(u);
  }

  FORR(i,1,n){
    ++col; dfs(i,i);
  }

  int g; scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&g);
    q[i]={u,v,g};
  }
  sort(q,q+m);
  FOR(i,0,m) mark(q[i].u,q[i].v,q[i].g);

  bool ok = 1;
  FOR(i,0,m) if(qMin(q[i].u,q[i].v)!=q[i].g){
    ok = 0; break;
  }

  if(!ok){ printf("-1\n"); return 0; }
  FOR(i,1,n) printf("%d ",f[i]==0 ? INF : f[i]);

  return 0;
}
*/
