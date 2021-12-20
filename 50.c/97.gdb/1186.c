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

const int MAXN=1020, MAXM=MAXN*MAXN*2;
const int INF=0x3f3f3f3f;
int n,m;

struct Edge{
  int v,w; Edge *next;
}edge[MAXM],*head[MAXN];
int tail=0;
void addEdge(int u, int v, int d){
  edge[tail]=Edge{v,d,head[u]}; head[u] = edge + tail++;
  edge[tail]=Edge{u,d,head[v]}; head[v] = edge + tail++;
}

struct Node{
  int d; int u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

int d[MAXN];
Edge *pre[MAXN]; int preu[MAXN];
void Dij(int s, Edge *exclude=NULL){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u = t.u;
    if(t.d > d[u]) continue;
    for(Edge *e=head[u];e;e=e->next)
      if(e!=exclude) if(d[e->v] > t.d + e->w){
        d[e->v] = t.d + e->w;
        if(!exclude){
          pre[e->v] = e; preu[e->v]=u;
        }
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

  Dij(1);
  int ansMax=0;

  Edge *p = pre[n]; u = n;
  while(p){
    Dij(1,p);
    ansMax=max(ansMax,d[n]);
    u = preu[u]; p = pre[u];
  }
  printf("%d\n",ansMax);

  return 0;
}

