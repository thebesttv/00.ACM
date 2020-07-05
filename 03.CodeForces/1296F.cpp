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

const int MAX = 5020;
const int INF = 0x3f3f3f3f;
int n,m,f[MAX],p[MAX][MAX],pe[MAX][MAX];
struct Edge { int v,no; };
VR<Edge> G[MAX];
struct Q{
  int u,v,g;
  bool operator < (const Q &b) const {
    return g < b.g;
  }
}q[MAX];

int col[MAX];
void bfs(int r, int *p, int *pe){
  queue<int> q;
  q.push(r); col[r]=r;
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(Edge e : G[u]) if(col[e.v]!=r){
      q.push(e.v); col[e.v]=r;
      p[e.v] = u; pe[e.v] = e.no;
    }
  }
}

int main(void){
  scanf("%d",&n);
  int u,g,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back({v,i});
    G[v].push_back({u,i});
    f[i]=INF;
  }
  FORR(i,1,n) bfs(i,p[i],pe[i]);

  scanf("%d",&m);
  FOR(i,0,m) scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].g);
  sort(q,q+m);
  FOR(i,0,m){
    u=q[i].u,v=q[i].v,g=q[i].g;
    while(v!=u){
      f[pe[u][v]]=g;
      v=p[u][v];
    }
  }

  bool ok=1;
  FOR(i,0,m){
    u=q[i].u,v=q[i].v,g=q[i].g;
    int tMin=INF;
    while(v!=u){
      tMin = min(tMin,f[pe[u][v]]);
      v=p[u][v];
    }
    if(tMin != g){
      ok = 0;
      break;
    }
  }
  if(!ok) printf("-1");
  else FOR(i,1,n) printf("%d ",min(f[i],int(1e6)));
  putchar('\n');

  return 0;
}
