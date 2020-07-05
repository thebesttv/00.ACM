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

const int MAXN=100020;
const int MAXM=200020;
const int INF=0x3f3f3f3f;
int n,m,s,d[MAXN];

struct Edge{
  int v,w; Edge *next;
}edge[MAXM];
Edge *head[MAXN];
int tail=0;

void addEdge(int u, int v, int w){
  edge[tail]=Edge{v,w,head[u]};
  head[u]=edge + (tail++);
}

struct Node{
  int d,u;
  Node(int d, int u): d(d), u(u) { }
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
PQ<Node> q;

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  q.push(Node(0,s));
  while(!q.empty()){
    Node t=q.top(); q.pop();
    if(t.d!=d[t.u]) continue;
    int u=t.u;
    for(Edge *e=head[u];e;e=e->next){
      if(d[e->v] > d[u] + e->w){
        d[e->v] = d[u] + e->w;
        q.push(Node(d[e->v], e->v));
      }
    }
  }
}

int main(void){
  scanf("%d%d%d",&n,&m,&s);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
  }

  Dij(s);

  printf("%d",d[1]);
  FORR(i,2,n) printf(" %d",d[i]);
  putchar('\n');
  return 0;
}
