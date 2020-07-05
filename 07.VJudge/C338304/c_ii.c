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

const int MAXN=120, MAXM=10020;
int n,m,k;

struct Edge{
  int v,w,c; Edge *next;
}edge[MAXM];
Edge *head[MAXM];
int tail=0;
void addEdge(int u, int v, int w, int c){
  edge[tail] = Edge{v,w,c,head[u]};
  head[u] = edge + (tail++);
}

struct Node{
  int d,c,u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

int Dij(int s){
  PQ<Node> q;
  q.push(Node{0,0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u = t.u;
    if(u==n) return t.d;
    for(Edge *e=head[u];e;e=e->next){
      if(e->c + t.c > k) continue;
      q.push(Node{t.d+e->w, e->c+t.c, e->v});
    }
  }
  return -1;
}

int main(void){
  scanf("%d%d%d",&k,&n,&m);
  int u,v,w,c;
  FOR(i,0,m){
    scanf("%d%d%d%d",&u,&v,&w,&c);
    addEdge(u,v,w,c);
  }

  int ans = Dij(1);

  printf("%d\n",ans);
  return 0;
}

/*
const int MAXN=120, MAXM=10020;
const int INF=0x3f3f3f3f;
int n,m,k,d[MAXN],c[MAXN];

struct Edge{
  int v,c,d; Edge *next;
}edge[MAXM], *head[MAXN];
int tail=0;
void addEdge(int u, int v, int c, int d){
  edge[tail] = Edge{v,c,d,head[u]};
  head[u] = edge + (tail++);
}

struct Node{
  int d,c,u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  MST(c,0x3f); c[s]=0;
  PQ<Node> q; q.push(Node{0,0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u =t.u;
    //if(d[u]!=t.d && c[u]!=t.c) continue;
    for(Edge *e=head[u];e;e=e->next){
      if(t.c + e->c > k) continue;
      int td = t.d + e->d;
      int tc = t.c + e->c;
      if(d[e->v]>td || c[e->v]>tc){
        d[e->v] = min(d[e->v], td);
        c[e->v] = min(c[e->v], tc);
        q.push(Node{td, tc, e->v});
      }
    }
  }
}


int main(void){
  scanf("%d%d%d",&k,&n,&m);
  for(int i=0,u,v,c,d;i<m;++i){
    scanf("%d%d%d%d",&u,&v,&d,&c);
    addEdge(u,v,c,d);
  }

  Dij(1);

  if(d[n]==INF) d[n]=-1;
  printf("%d\n",d[n]);
  return 0;
}
*/
