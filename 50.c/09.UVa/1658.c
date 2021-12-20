#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
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

const int MAX=2020;
const int INF=0x3f3f3f3f;
struct Edge{
  int u,v,cap,flow,cost;
  Edge() { }
  Edge(int u_, int v_, int cap_, int flow_, int cost_): u(u_), v(v_), cap(cap_), flow(flow_), cost(cost_) { }
};
VR<Edge> edge;
VR<int> G[MAX];
int a[MAX],p[MAX],d[MAX],inq[MAX],cnt[MAX];
int n,m;

void addEdge(int u, int v, int cap, int cost);
bool bf(int s,int t, int & flow, int & cost);
int mcmf(int s, int t);

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    edge.CE(); FOR(i,0,MAX) G[i].CE();
    addEdge(1,n+1,2,0); //限制总流量为2
    int u,v,c;
    FOR(i,2,n) addEdge(i,i+n,1,0);
    FOR(i,0,m){
      scanf("%d%d%d",&u,&v,&c);
      addEdge(u+n,v,1,c);
    }
    int ans=mcmf(1,n);
    printf("%d\n",ans);
  }

  return 0;
}

void addEdge(int u, int v, int cap, int cost){
  edge.push_back((Edge){u,v,cap,0,cost});
  edge.push_back((Edge){v,u,0,0,-cost});
  int m=edge.size();
  G[u].push_back(m-2); G[v].push_back(m-1);
}
bool bf(int s,int t, int & flow, int & cost){
  MST(a,0); MST(inq,0); MST(d,0x3f); MST(cnt,0); MST(p,0); a[s]=INF; d[s]=0;
  queue<int> q; q.push(s); inq[s]=true;
  while(!q.empty()){
    int u=q.front(); q.pop();
    inq[u]=false;
    FOR(i,0,G[u].size()){
      Edge & e=edge[G[u][i]];
      if(e.cap>e.flow && d[e.v]>d[u]+e.cost){
        a[e.v]=min(a[u],e.cap-e.flow);
        p[e.v]=G[u][i];
        d[e.v]=d[u]+e.cost;
        if(!inq[e.v]) {q.push(e.v); inq[e.v]=true; if(++cnt[e.v]>n) break;}
      }
    }
  }
  if(!a[t] || d[t]==INF) return false;
  for(int i=t;i!=s;i=edge[p[i]].u){
    edge[p[i]].flow+=a[t];
    edge[p[i]^1].flow-=a[t];
  }
  flow+=a[t]; cost+=a[t]*d[t];
  return true;
}
int mcmf(int s, int t){
  int flow=0,cost=0;
  while(bf(s,t,flow,cost));
  return cost;
}
