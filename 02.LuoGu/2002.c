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

const int MAX=100020;
int n,m;

struct Tarjan{
  int dfn[MAX],dfscnt,low[MAX];
  bool inst[MAX]; stack<int> st;
  int belong[MAX],sccnt;
  VR<int> G[MAX];

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
      inst[v]=0; belong[v]=sccnt;
    }while(v!=u);
  }
}tar;

struct Graph{
  int n;
  VR<int> G[MAX]; int in[MAX];
  void addEdge(int u, int v){
    G[u].push_back(v); in[v]++;
  }
}G;

int main(void){
  int u,v;
  scanf("%d%d",&n,&m);
  while(m--){
    scanf("%d%d",&u,&v);
    if(u!=v) tar.addEdge(u,v);
  }
  tar.tarjan();

  G.n = tar.sccnt;
  FORR(i,1,n){
    u = tar.belong[i];
    for(int j : tar.G[i]){
      v = tar.belong[j];
      if(u!=v) G.addEdge(u,v);
    }
  }
  int cnt=0;
  FORR(i,1,G.n) if(!G.in[i])
    cnt++;
  printf("%d\n",cnt);

  return 0;
}
