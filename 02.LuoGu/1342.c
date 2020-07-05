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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1000020;
int n,m; LL d[MAX];

struct Edge{
  int v; LL w; bool rev; Edge *next;
}edge[MAX*2],*head[MAX];
int tail=0;
void addEdge(int u, int v, int w){
  edge[tail] = Edge{v,w,0,head[u]}; head[u] = edge + tail++;
  edge[tail] = Edge{u,w,1,head[v]}; head[v] = edge + tail++;
}

struct Node{
  LL d; int u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

void Dij(int s, bool rev){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u=t.u;
    if(d[u]<t.d) continue;
    for(Edge *e=head[u];e;e=e->next)
      if(e->rev == rev && d[e->v] > d[u]+e->w){
        d[e->v] = d[u] + e->w;
        q.push(Node{d[e->v],e->v});
      }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  while(m--){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
  }

  LL ans=0;
  Dij(1,0); FORR(i,1,n) ans += d[i];
  Dij(1,1); FORR(i,1,n) ans += d[i];

  printf("%lld\n",ans);

  return 0;
}
