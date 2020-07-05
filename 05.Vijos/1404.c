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

const int MAXN=90020, MAXM = 10020 + MAXN;
const int INF=0x3f3f3f3f;
int n,s,t,d[MAXN];

struct Edge{
  int v,w; Edge *next;
}edge[MAXM], *head[MAXN];
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
  scanf("%d%d%d",&n,&s,&t);
  FOR(i,s+1,t) addEdge(i,i-1,0);
  int timeMax=t;
  int l,r,w;
  while(n--){
    scanf("%d%d%d",&l,&r,&w);
    addEdge(l,r+1,w);
    timeMax=max(timeMax,r);
  }

  Dij(s);
  int ansMin=INF;
  FORR(i,t+1,timeMax+1)
    ansMin=min(ansMin,d[i]);

  printf("%d\n", ansMin<INF ? ansMin : -1);

  return 0;
}
