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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()

/*
const int MAX=3020;
const int INF=0x3f3f3f3f;
typedef long long unsigned LLU;
struct Edge{
  int u,v,cap,flow,cost;
};
VR<Edge> edge;
VR<int> G[MAX];
int a[MAX],p[MAX],d[MAX],cnt[MAX]; bool inq[MAX];
int n,m,r;
bool vis[MAX];

LLU mcmf(int s, int t);
bool bf(int s, int t, int & flow, LLU & cost);
void addEdge(int u, int v, int cap, int cost);

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d",&u,&w);
    addEdge(0,u,INF,w);
  }
  scanf("%d",&r);
  FOR(i,0,r){
    scanf("%d%d",&u,&v);
    addEdge(u,v,1,0);
  }
  FORR(i,1,n) addEdge(i,MAX-1,1,0);

  int cost=mcmf(0,MAX-1);
  bool flag=1; u=-1;
  for(int i=1;i<=n && flag;i++){
    FOR(j,0,G[i].size()) if(edge[G[i][j]].v==MAX-1 && edge[G[i][j]].flow==0){
      flag=0; u=i; break;
    }
  }
  if(!flag) printf("NO\n%d\n",u);
  else printf("YES\n%d\n",cost);

  return 0;
}

LLU mcmf(int s, int t){
  int flow=0; LLU cost=0;
  while(bf(s,t,flow,cost));
  return cost;
}
bool bf(int s, int t, int & flow, LLU & cost){
  MST(p,0); MST(a,0); MST(d,0x3f); MST(inq,0); MST(cnt,0); a[s]=INF; d[s]=0;
  queue<int> q; q.push(s); inq[s]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    inq[u]=false;
    FOR(i,0,G[u].size()){
      Edge & e=edge[G[u][i]];
      if(e.cap>e.flow && d[e.v]>d[u]+e.cost){
        a[e.v]=min(a[u],e.cap-e.flow);
        p[e.v]=G[u][i];
        d[e.v]=d[u]+e.cost;
        if(!inq[e.v]) {q.push(e.v); inq[e.v]=true;}
      }
    }
  }
  if(d[t]==INF || a[t]==0) return false;
  int tt;
  for(int i=t;i!=s;i=edge[p[i]].u){
    edge[p[i]].flow+=a[t];
    edge[p[i]^1].flow-=a[t];
    //edge[p[i]].cost=0;  //XXX
    if(edge[p[i]].u==s) tt=p[i];
  }
  flow+=a[t];
  if(!vis[tt]) cost+=1ll*a[t]*d[t],vis[tt]=true;
#ifdef DEBUG
  printf("  cost += %d * %d = %d\n",a[t],d[t],a[t]*d[t]);
#endif
  return true;
}
void addEdge(int u, int v, int cap, int cost){
  edge.push_back((Edge){u,v,cap,0,cost});
  edge.push_back((Edge){v,u,0,0,-cost});
  int m=edge.size();
  G[u].push_back(m-2); G[v].push_back(m-1);
}
*/
