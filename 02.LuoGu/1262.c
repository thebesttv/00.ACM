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

const int MAX=3020;
const int INF=0x3f3f3f3f;
int n,p,m;

struct Node{
  int w, u;
  bool operator < (const Node &b) const {
    return w < b.w;
  }
};
// 缩点，所得点的权值为SC中最小权值
struct Tarjan{
  int dfn[MAX],dfscnt,low[MAX];
  int belong[MAX],sccnt;
  int w[MAX]; VR<int> G[MAX];
  stack<int> st; bool inst[MAX];

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
    int v; sccnt++;
    do{
      v = st.top(); st.pop();
      belong[v] = sccnt; inst[v]=0;
    }while(v!=u);
  }
}tar;

struct Graph{
  int n;
  int w[MAX],in[MAX];  // 每个节点的入度
  bool vis[MAX];
  VR<int> G[MAX];

  void addEdge(int u, int v){
    G[u].push_back(v); in[v]++;
  }
  bool cal(int &ans){
    ans = 0;
    FORR(i,1,n) if(!in[i] && w[i]<INF){
      ans += w[i]; go(i);
    }
    bool ok=1;
    FORR(i,1,n) if(!vis[i]){
      ok=0; break;
    }
    if(ok) return 1;
    FORR(i,1,n) if(!vis[i] && w[i]<INF){
      ans += w[i]; go(i);
    }
    return 0;
  }
  void go(int u){
    vis[u]=1;
    for(int v : G[u])
      if(!vis[v]) go(v);
  }
}G;

int main(void){
  scanf("%d%d",&n,&p);
  int u,v,c;
  MST(tar.w,0x3f);
  FOR(i,0,p){
    scanf("%d%d",&u,&c);
    tar.w[u] = c;
  }
  scanf("%d",&m);
  while(m--){
    scanf("%d%d",&u,&v);
    tar.addEdge(u,v);
  }
  tar.tarjan();

  // 缩点，构造
  MST(G.w,0x3f);
  G.n = tar.sccnt;
  FORR(i,1,n){
    u = tar.belong[i];
    G.w[u] = min(G.w[u], tar.w[i]);
    for(int j : tar.G[i]){
      v = tar.belong[j];
      if(u!=v){
        G.addEdge(u,v);
#ifdef DEBUG
        printf(" %d -> %d ( %d -> %d )\n",u,v,i,j);
#endif
      }
    }
  }
#ifdef DEBUG
  FORR(i,1,G.n) printf("  G.w[%d]: %d\n",i,G.w[i]);
#endif

  int res; bool ok;
  ok = G.cal(res);
  if(ok) printf("YES\n%d\n",res);
  else{
    printf("NO\n"); int id=INF;
    FORR(i,1,G.n) if(!G.vis[i]){
      FORR(j,1,n) if(tar.belong[j]==i){
        id = min(id, j); break;
      }
    }
    printf("%d\n",id);
  }

  return 0;
}
