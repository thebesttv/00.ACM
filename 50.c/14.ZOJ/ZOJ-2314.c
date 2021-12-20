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

const int MAX=220;
const int INF=0x3f3f3f3f;
int n,m,ans[MAX*MAX];
struct Edge{
  int u,v,cap,flow,num;
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
  void addEdge(int u, int v, int cap, int num=0){
    edge.push_back((Edge){u,v,cap,0,num});
    edge.push_back((Edge){v,u,0,0,0});
    m=edge.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
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

int main(void){
  int T; scanf("%d",&T);
  int s=0,t=MAX-1;
  while(T--){
    di.clear();
    scanf("%d%d",&n,&m);
    int u,v,b,c;
    FORR(i,1,m){
      scanf("%d%d%d%d",&u,&v,&b,&c);
      di.addEdge(s,v,b,0); di.addEdge(u,t,b,0);
      di.addEdge(u,v,c-b,i);
      ans[i]=b; //<b> </b>
    }
    //di.addEdge(t,s,INF,0);

    di.MF(s,t);

    bool ok=1; int siz=di.edge.size();
    FOR(i,0,siz){
      Edge & e=di.edge[i];
      if(e.u==s){
        if(e.flow<e.cap) {ok=0; break;}
      }else if(e.num){
        ans[e.num]+=e.flow;
      }
    }
    if(!ok) printf("NO\n");
    else{
      printf("YES\n");
      FORR(i,1,m) printf("%d\n",ans[i]);
    }
  }

  return 0;
}
