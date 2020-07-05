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
#include<cassert>
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

//const int MAXN = 80000*2 + 20;
const int MAXN = 80000*2 + 21;
const int MAXM = 200000*2 + 20;
int n,m,s;

struct Edge{
  int v,w; Edge *next;
};
struct Base{
  Edge edge[MAXM], *head[MAXN];
  int tail=0;
};
struct Tarjan: public Base{
  int dfn[MAXN],dfscnt,low[MAXN];
  bool inst[MAXN]; stack<int> st;
  int belong[MAXN],sccnt;

  double rate[MAXM];
  void addEdge(int u, int v, int w, double r){
    edge[tail] = Edge{v,w,head[u]}; head[u] = edge + tail;
    rate[tail] = r; tail++;
  }

  void tarjan(){
    FORR(i,1,n) if(!dfn[i])
      tarjan(i);
  }
  void tarjan(int u){
    int v;
    dfn[u] = low[u] = ++dfscnt;
    st.push(u); inst[u]=1;
    for(Edge *e=head[u];e;e=e->next){
      v = e->v;
      if(!dfn[v]){
        tarjan(v);
        if(low[v] < low[u]){
          low[u] = low[v];
        }
      }else if(inst[v] && dfn[v] < low[u]){
        low[u] = dfn[v];
      }
    }
    if(dfn[u] != low[u]) return;
    ++sccnt;
    do{
      v = st.top(); st.pop();
      inst[v]=0; belong[v]=sccnt;
    }while(v!=u);
  }
}tar;

int sum[MAXN];  // 每个强连通分量内部权值之和

struct Graph: public Base{
  struct Node{
    int d,u;
    bool operator < (const Node &b) const {
      return d < b.d;
    }
  };
  int n,d[MAXN];
  void addEdge(int u, int v, int w){
    edge[tail] = Edge{v,w,head[u]}; head[u] = edge + (tail++);
  }
  void Dij(int s){
    MST(d,0);
    PQ<Node> q; q.push(Node{0,s});
    while(!q.empty()){
      Node t = q.top(); q.pop();
      int u = t.u;
      if(d[u] != t.d) continue;
      for(Edge *e=head[u];e;e=e->next){
        if(d[e->v] <= d[u] + e->w){
          d[e->v] = d[u] + e->w;
          q.push(Node{d[e->v], e->v});
        }
      }
    }
  }
}G;

int main(void){
  int u,v,w; double rate;
  scanf("%d%d",&n,&m);
  while(m--){
    scanf("%d%d%d%lf",&u,&v,&w,&rate);
    tar.addEdge(u,v,w,rate);
  }
  scanf("%d",&s);

  tar.tarjan();
  int n = tar.sccnt; G.n = n*2;

  FORR(i,1,::n){
    u = tar.belong[i];
    for(Edge *e=tar.head[i];e;e=e->next){
      v = tar.belong[e->v];
      if(u==v){
        int &s = sum[u], w = e->w;
        rate = tar.rate[ e - tar.edge ];
        while(w){
          s += w; w *= rate;
        }
      }else{
        G.addEdge(u+n,v,e->w);
      }
    }
  }
  FORR(i,1,n) G.addEdge(i,i+n,sum[i]);
#ifdef DEBUG
  FORR(i,1,n) printf("sum[%d]: %d\n",i,sum[i]);
#endif

  s = tar.belong[s]; G.Dij(s);
#ifdef DEBUG
  printf("  Dij(%d)\n",s);
  FORR(i,1,G.n) printf("    d[%d]: %d\n",i,G.d[i]);
#endif
  int ansMax=0;
  FORR(i,n+1,G.n) ansMax=max(ansMax,G.d[i]);
  printf("%d\n",ansMax);

  return 0;
}
