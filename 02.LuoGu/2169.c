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

const int MAXN=200020, MAXM=1000020;
int n,m;

struct Edge{
  int v,w; Edge *next;
};
struct Base{
  Edge edge[MAXM], *head[MAXN];
  int tail=0;
  void addEdge(int u, int v, int w){
    edge[tail]=Edge{v,w,head[u]}; head[u] = edge + tail++;
  }
};

struct Tarjan: public Base{
  int n;
  int dfn[MAXN], dfscnt=0, low[MAXN];
  stack<int> st; bool inst[MAXN];
  int belong[MAXN], sccnt=0;

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
        if(low[u] > low[v])
          low[u] = low[v];
      }else if(inst[v] && low[u] > dfn[v]){
        low[u] = dfn[v];
      }
    }

    if(dfn[u]!=low[u]) return;
    ++sccnt;
    do{
      v = st.top(); st.pop();
      inst[v]=0; belong[v]=sccnt;
    }while(v!=u);
  }
}tar;

struct Graph: public Base{
  int n,d[MAXN];
  struct Node{
    int d, u;
    bool operator < (const Node &b) const {
      return d > b.d;
    }
  };
  void Dij(int s){
    MST(d,0x3f); d[s]=0;
    PQ<Node> q; q.push(Node{0,s});
    while(!q.empty()){
      Node t=q.top(); q.pop();
      if(t.d!=d[t.u]) continue;
      int u=t.u;
      for(Edge *e=head[u];e;e=e->next){
        if(d[e->v] > d[u] + e->w){
          d[e->v] = d[u] + e->w;
          q.push(Node{d[e->v], e->v});
        }
      }
    }
  }
}G;

int main(void){
  int u,v,w;
  scanf("%d%d",&n,&m);
  tar.n = n;
  while(m--){
    scanf("%d%d%d",&u,&v,&w);
    tar.addEdge(u,v,w);
  }
  tar.tarjan();

  G.n = tar.sccnt;
  FORR(i,1,n){
    u = tar.belong[i];
    for(Edge *e=tar.head[i];e;e=e->next){
      v = tar.belong[e->v];
      if(u!=v){
        G.addEdge(u,v,e->w);
      }
    }
  }
  int s = tar.belong[1], t = tar.belong[n];
  G.Dij(s);
  printf("%d\n",G.d[t]);

  return 0;
}
