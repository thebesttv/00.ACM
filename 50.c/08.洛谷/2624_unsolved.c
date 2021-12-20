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

const int MAX=200020;
const int INF=0x3f3f3f3f;
int n,m,a[MAX];
int q[MAX],head,tail;
struct Edge{
  int u,v,cap,flow;
};
struct Dinic{
  int s,t;
  VR<Edge> edge;
  VR<int> G[MAX];
  int cur[MAX],d[MAX];
  bool vis[MAX];
  void init(int s_, int t_){
    s=s_; t=t_;
  }
  void clear(){
    edge.clear();
    FOR(i,0,MAX) G[i].clear();
  }
  void addEdge(int u, int v, int cap){
    edge.push_back((Edge){u,v,cap,0});
    edge.push_back((Edge){v,u,0,0});
    int siz=edge.size();
    G[u].push_back(siz-2); G[v].push_back(siz-1);
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
          d[e.v]=d[u]+1; vis[e.v]=1; q[tail++]=e.v;
        }
      }
    }
    return vis[t];
  }
  int dfs(int u, int a){
    if(u==t || !a) return a;
    int ans=0,f;
    for(int & i=cur[u];i<G[u].size();i++){
      Edge & e=edge[G[u][i]];
      if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(a,e.cap-e.flow)))>0){
        e.flow+=f; edge[G[u][i]^1].flow-=f;
        ans+=f; a-=f;
        if(!a) break;
      }
    }
    return ans;
  }
  int MF(){
    int ans=0;
    while(bfs()){
      MST(cur,0); ans+=dfs(s,INF);
    }
#ifdef DEBUG
    printf("  in Dinic::MF(), get: %d\n",ans);
#endif
    return ans;
  }
};

int main(void){
  scanf("%d%d",&n,&m);
  int sum=0;
  FORR(i,1,n) {scanf("%d",&a[i]); sum+=a[i];}

  if(m>(n>>1)) {printf("Error!\n"); return 0;}
  Dinic di; int ansMax=0;
  if(n&1){  //n为奇数，建两次
    di.init(0,n+2);
    //1.有1无n
    for(int i=1;i<n;i+=2) di.addEdge(0,i,a[i]);
    for(int i=2;i<n;i+=2) di.addEdge(i,n+2,a[i]);
    for(int i=3;i<n;i+=2){
      di.addEdge(i,i+1,INF); di.addEdge(i,i-1,INF);
    }
    di.addEdge(1,2,INF);
    ansMax=sum-a[n]-di.MF();
    //2.有n无1
    di.clear();
    for(int i=3;i<=n;i+=2) di.addEdge(0,i,a[i]);
    for(int i=2;i<=n;i+=2) di.addEdge(i,n+2,a[i]);
    for(int i=3;i<n;i+=2){
      di.addEdge(i,i+1,INF); di.addEdge(i,i-1,INF);
    }
    di.addEdge(n,n-1,INF);
    ansMax=max(ansMax,sum-a[1]-di.MF());
  }else{  //n为偶数，建一次
    di.init(0,n+2);
    for(int i=1;i<=n;i+=2) di.addEdge(0,i,a[i]);    //s->X
    for(int i=2;i<=n;i+=2) di.addEdge(i,n+2,a[i]);  //Y->t
    for(int i=3;i<n;i+=2){                          //X->Y
      di.addEdge(i,i+1,INF); di.addEdge(i,i-1,INF);
    }
    di.addEdge(1,2,INF); di.addEdge(1,n,INF);
    ansMax=sum-di.MF();
  }
  printf("%d\n",ansMax);

  return 0;
}
