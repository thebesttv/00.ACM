#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAXN=400;
const int MAXM=1220;
const int MAX=MAXN+MAXM;
const int INF=0x3f3f3f3f;
int n,m,L[MAXN][MAXM];
bool first=1;
struct Edge{
  int u,v,cap,flow;
};
struct Dinic{
  int n,m,s,t;
  VR<Edge> edge;
  VR<int> G[MAX];
  int cur[MAX],d[MAX];
  bool vis[MAX];
  int q[MAX],head,tail;

  void clear(int n=MAX-1){
    edge.clear();
    FORR(i,0,n) G[i].clear();
  }
  void addEdge(int u, int v, int cap){
    edge.push_back((Edge){u,v,cap,0});
    edge.push_back((Edge){v,u,0,0});
    m=edge.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
  }
  void addEdge2(int ss, int tt, int u, int v, int b, int c){
    addEdge(ss,v,b); addEdge(u,tt,b);
    addEdge(u,v,c-b);
  }
  bool bfs(){
    MST(vis,0);
    head=tail=0;
    q[tail++]=s; d[s]=0; vis[s]=1;
    while(head<tail){
      int u=q[head++];
      FOR(i,0,G[u].size()){
        Edge & e=edge[G[u][i]];
        if(!vis[e.v] && e.cap>e.flow){
          vis[e.v]=1;
          d[e.v]=d[u]+1; q[tail++]=e.v;
        }
      }
    }
    return vis[t];
  }
  int dfs(int u, int a){
    if(u==t || !a) return a;
    int ans=0,f;
    for(int &i=cur[u];i<G[u].size();i++){
      Edge & e=edge[G[u][i]];
      if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(a,e.cap-e.flow)))>0){
        e.flow+=f; edge[G[u][i]^1].flow-=f;
        ans+=f; a-=f;
        if(!a) break;
      }
    }
    return ans;
  }
  int MF(int s_, int t_){
    s=s_,t=t_;
    int ans=0;
    while(bfs()){
      MST(cur,0); ans+=dfs(s,INF);
    }
    return ans;
  }
}di;

void print(int a){
  if(first) first=0;
  else putchar('\n');

  printf("%d\n",a);
  if(a==-1) return;

  FORR(i,1,n){  //对每天
    int siz=di.G[i].size();
    FORR(j,0,siz){  //对每个女孩
      Edge & e=di.edge[di.G[i][j]];
      if(e.v<MAXN || e.v>MAX-10) continue;  //指向源点
      printf("%d\n",e.flow+L[i][e.v-MAXN]);
    }
  }
}

int main(void){
  int s=0,t=MAX-6;
  int ss=MAX-5,tt=MAX-4;
  while(scanf("%d%d",&n,&m)==2){
    di.clear();
    int g,c,d;
    FORR(i,1,m){  //对每个女孩，序号 [MAXN+1 : MAXN+m]
      scanf("%d",&g);
      di.addEdge2(ss,tt,MAXN+i,t,g,INF);
    }
    FORR(i,1,n){  //对每天，序号 [1:n]
      scanf("%d%d",&c,&d);
      di.addEdge2(ss,tt,s,i,0,d); //最多拍d张
      int t,l,r;
      while(c--){ //对每个女孩
        scanf("%d%d%d",&t,&l,&r);
        di.addEdge2(ss,tt,i,MAXN+t+1,l,r);
        L[i][t+1]=l;
      }
    }
    di.addEdge(t,s,INF);  //<b> </b>
    di.MF(ss,tt);
    bool ok=1; int siz=di.G[ss].size();
    FOR(i,0,siz){
      Edge & e=di.edge[di.G[ss][i]];
      if(e.flow<e.cap) {ok=0; break;}
    }
    if(!ok) {print(-1); continue;}
    int ans=di.MF(s,t);
    print(ans);
  }

  return 0;
}
