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

const int MAX=102;
int n;

struct Tarjan{
  int n;
  int dfn[MAX],dfscnt,low[MAX];
  bool inst[MAX]; stack<int> st;
  int belong[MAX],sccnt;
  VR<int> G[MAX];

  void init(int n_){
    n = n_;
    FORR(i,1,n) G[i].clear();
    MST(dfn,0); dfscnt=0; MST(low,0);
    MST(inst,0); MST(belong,0); sccnt=0;
  }

  void addEdge(int u, int v){
    G[u].push_back(v);
  }
  void tarjan(){
    FORR(i,1,n) if(!dfn[i])
      tarjan(i);
  }
  void tarjan(int u){
    dfn[u] = low[u] = ++dfscnt;
    st.push(u); inst[u]=1;
    for(int v : G[u]){
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
    int v; ++sccnt;
    do{
      v = st.top(); st.pop();
      inst[v]=0; belong[v] = sccnt;
    }while(v!=u);
  }
}tar;

struct Graph{
  int n; VR<int> G[MAX];
  int in[MAX], out[MAX];

  void init(int n_){
    n = n_;
    FORR(i,1,n) G[i].clear();
    MST(in,0); MST(out,0);
  }
  void addEdge(int u, int v){
    G[u].push_back(v);
    out[u]++, in[v]++;
  }
}G;

int main(void){
  int u,v;
  scanf("%d",&n);

  tar.init(n);
  FORR(u,1,n){
    while(scanf("%d",&v)==1 && v)
      tar.addEdge(u,v);
  }
  tar.tarjan();
  G.init(tar.sccnt);
  FORR(i,1,n){
    u = tar.belong[i];
    for(int j : tar.G[i]){
      v = tar.belong[j];
      if(u != v){
        G.addEdge(u,v);
      }
    }
  }
  int cntIn0 = 0;
  FORR(i,1,G.n) if(!G.in[i])
    cntIn0++;
  printf("%d\n%d\n",cntIn0,tar.sccnt);

  return 0;
}

/*
const int MAX=102;
int n;

struct Tarjan{
  int n;
  int dfn[MAX],dfscnt,low[MAX];
  bool inst[MAX]; stack<int> st;
  int belong[MAX],sccnt;
  VR<int> G[MAX];

  void init(int n_){
    n = n_;
    FORR(i,1,n) G[i].clear();
    MST(dfn,0); dfscnt=0; MST(low,0);
    MST(inst,0); MST(belong,0); sccnt=0;
  }

  void addEdge(int u, int v){
    G[u].push_back(v);
#ifdef DEBUG
    printf("  T: %d -> %d\n",u,v);
#endif
  }
  void tarjan(){
    FORR(i,1,n) if(!dfn[i])
      tarjan(i);
  }
  void tarjan(int u){
    dfn[u] = low[u] = ++dfscnt;
    st.push(u); inst[u]=1;
    for(int v : G[u]){
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
    int v; ++sccnt;
    do{
      v = st.top(); st.pop();
      inst[v]=0; belong[v] = sccnt;
    }while(v!=u);
  }
}tar;

struct Graph{
  int n; VR<int> G[MAX];
  int in[MAX], out[MAX];

  void init(int n_){
    n = n_;
    FORR(i,1,n) G[i].clear();
    MST(in,0); MST(out,0);
  }
  void addEdge(int u, int v){
#ifdef DEBUG
          printf("  G: %d -> %d\n",u,v);
#endif
    G[u].push_back(v);
    out[u]++, in[v]++;
  }
}G;

int main(void){
  int u,v;
  scanf("%d",&n);

  tar.init(n);
  FORR(u,1,n){
    while(scanf("%d",&v)==1 && v)
      tar.addEdge(u,v);
  }
  tar.tarjan();

  bool first=1;
  int cnt=0;

  do{
    G.init(tar.sccnt);
    FORR(i,1,n){
      u = tar.belong[i];
      for(int j : tar.G[i]){
        v = tar.belong[j];
        if(u!=v){
          G.addEdge(u,v);
        }
      }
    }
    if(first){
      first=0; int ansA=0;
      FORR(i,1,G.n) if(!G.in[i])
        ansA++;
      printf("%d\n",ansA);
    }

    VR<int> inZero;
    FORR(i,1,G.n) if(!G.in[i])
      inZero.push_back(i);
    //printf("ZERO\n");
    FORR(u,1,G.n) if(!G.out[u]){
      cnt += inZero.size();
      for(int v : inZero)
        G.addEdge(u,v);
    }

    // 建图 Tarjan
    tar.init(G.n);
    FORR(u,1,G.n) for(int v : G.G[u])
      tar.addEdge(u,v);

    tar.tarjan();
  }while(tar.sccnt>1);
  printf("%d\n",cnt);

  return 0;
}
*/
