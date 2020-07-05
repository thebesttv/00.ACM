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

const int MAX=1e4+20;
int n,m;

struct Tarjan{
  VR<int> G[MAX];
  int w[MAX];
  int dfn[MAX],dfscnt=0,low[MAX];
  int belong[MAX],sccnt=0;
  stack<int> st; bool ins[MAX];

  void addEdge(int u, int v){
    G[u].push_back(v);
  }
  void tarjan(){
    FORR(i,1,n) if(!dfn[i]){
      tarjan(i);
    }
  }
  void tarjan(int u){
    dfn[u]=low[u]=++dfscnt;
    st.push(u); ins[u]=1;
    for(int v : G[u]){
      if(!dfn[v]){
        tarjan(v);
        if(low[u]>low[v])
          low[u]=low[v];
      }else if(ins[v] && low[u]>dfn[v]){
        low[u]=dfn[v];
      }
    }
    if(dfn[u]!=low[u]) return;
    int v; sccnt++;
    do{
      v=st.top(); st.pop();
      ins[v]=0; belong[v]=sccnt;
    }while(v!=u);
  }
}tar;

struct Graph{
  int n,w[MAX]; VR<int> G[MAX];
  int f[MAX];

  void addEdge(int u, int v){
    G[u].push_back(v);
  }
  int dp(int u){
    int &a=f[u];
    if(a>-1) return a;
    a = w[u];
    for(int v : G[u]){
      a = max(a, w[u]+dp(v));
    }
    return a;
  }
  int cal(){
    MST(f,-1); int ansMax=0;
    FORR(i,1,n) ansMax=max(ansMax,dp(i));
    return ansMax;
  }
}G;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&tar.w[i]);
  int u,v;
  while(m--){
    scanf("%d%d",&u,&v);
    tar.addEdge(u,v);
  }
  tar.tarjan();

  G.n = tar.sccnt;
  FORR(i,1,n){
    u = tar.belong[i];
    G.w[u] += tar.w[i];
    for(int j : tar.G[i]){
      v = tar.belong[j];
      if(u!=v){
        G.addEdge(u,v);
      }
    }
  }

  printf("%d\n",G.cal());

  return 0;
}
