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

const int MAX=106;
const int INF=0x3f3f3f3f;
int n,m,l,r;
int lev[MAX];

struct Edge{
  int v,w; Edge *next;
}edge[MAX*MAX*4];
Edge *head[MAX*2];
int tail=0;

void addEdge(int u, int v, int w){
  edge[tail] = Edge{v,w,head[u]};
  head[u] = edge + (tail++);
}

struct Node{
  int d,u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

int d[MAX*2];
void Dij(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    if(t.d != d[t.u]) continue;
    int u = t.u;
    for(Edge *e = head[u]; e; e = e->next){
      if(e->v <= n && ( lev[e->v]<l || lev[e->v]>r ))
        continue;
      if(d[e->v] > d[u] + e->w){
        d[e->v] = d[u] + e->w;
        q.push(Node{d[e->v], e->v});
      }
    }
  }
}

int main(void){
  scanf("%d%d",&m,&n);
  FORR(i,1,n){
    int p,x,t,v;
    scanf("%d%d%d",&p,&lev[i],&x);
    addEdge(i,n+i,p);
    while(x--){
      scanf("%d%d",&t,&v);
      addEdge(i,t,v);
    }
  }

  int ansMin = INF;
  FORR(i,max(lev[1]-m,0),lev[1]){
    l = i, r = i+m;
#ifdef DEBUG
    printf(" %d, %d\n",l,r);
#endif
    Dij(1);
    FORR(i,n+1,2*n)
      ansMin=min(ansMin,d[i]);
  }
  printf("%d\n",ansMin);

  return 0;
}
