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

const int MAXN=5020, MAXM=100000*2+20;
int n,m,d[MAXN],d2[MAXN];

struct Edge{
  int v,w; Edge *next;
}edge[MAXM], *head[MAXN];
int tail=0;

void addEdge(int u, int v, int w){
  edge[tail] = Edge{v,w,head[u]}; head[u] = edge + tail++;
  edge[tail] = Edge{u,w,head[v]}; head[v] = edge + tail++;
}

struct Node{
  int d,u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  MST(d2,0x3f);
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u = t.u;
    if(t.d > d2[u]) continue;
    for(Edge *e=head[u];e;e=e->next){
      int td = t.d + e->w;
      if(td < d[e->v]){
        swap(td, d[e->v]);
        q.push(Node{d[e->v],e->v});
      }
      if(td < d2[e->v] && td > d[e->v]){
        d2[e->v] = td;
        q.push(Node{d2[e->v],e->v});
      }
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

  Dij(1);

  printf("%d\n",d2[n]);

  return 0;
}
