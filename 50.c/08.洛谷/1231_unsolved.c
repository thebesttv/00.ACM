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

const int MAX=62000;
const int INF=0x3f3f3f3f;
struct Node{
  char name[30];
  int n;
  bool operator < (const Node & b) const {
    return strcmp(name,b.name)<0;
  }
};
set<Node> st;
struct Edge{
  int u,v,cap,flow;
  Edge() { }
  Edge(int u_, int v_, int cap_, int flow_): u(u_), v(v_), cap(cap_), flow(flow_) { }
};
vector<Edge> edge;
vector<int> G[MAX*2];
int a[MAX],p[MAX];
int vis[10020];

void addEdge(int u, int v, int cap);
int maxflow(int s, int t);

int main(void){
  int n1,n2,n3,m; scanf("%d%d%d",&n1,&n2,&n3);
  int u,v; int t1=n1+n2+n3,t2=n1,t3=n1+n2;
  scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    addEdge(0,u,1); addEdge(0,u+t1,1);
    addEdge(v+t2,MAX-1,1); addEdge(u,v+t2,1);
  }
  scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    addEdge(u+t1,v+t3,1); addEdge(v+t3,MAX-1,1);
  }
  maxflow(0,MAX-1);
  int ans=0;
  FOR(i,0,G[0].size()){
    Edge & e=edge[G[0][i]];
    if(e.flow==1) vis[e.v>t1 ? e.v-t1 : e.v]++;
  }
  FORR(i,1,n1) if(vis[i]==2) ans++;
  printf("%d\n",ans);

  return 0;
}

void addEdge(int u, int v, int cap){
  edge.push_back(Edge(u,v,cap,0));
  edge.push_back(Edge(v,u,0,0));
  int m=edge.size();
  G[u].push_back(m-2); G[v].push_back(m-1);
}
int maxflow(int s, int t){
  int flow=0; MST(p,0);
  while(1){
    MST(a,0); a[s]=INF;
    queue<int> q; q.push(s);
    while(!q.empty()){
      int u=q.front(); q.pop();
      FOR(i,0,G[u].size()){
        Edge & e=edge[G[u][i]];
        if(!a[e.v] && e.cap>e.flow){
          a[e.v]=min(a[u],e.cap-e.flow);
          p[e.v]=G[u][i];
          q.push(e.v);
        }
      }
      if(a[t]) break;
    }
    if(!a[t]) break;
    for(int i=t;i!=s;i=edge[p[i]].u){
      edge[p[i]].flow+=a[t];
      edge[p[i]^1].flow-=a[t];
    }
    flow+=a[t];
  }
  return flow;
}

