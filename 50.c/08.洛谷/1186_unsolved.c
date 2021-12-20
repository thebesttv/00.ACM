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

const int MAX=1020;
const int INF=0x3f3f3f3f;
struct Edge{
  int u,v,w;
}edge[MAX*MAX];
int G[MAX][MAX],gtail[MAX];
struct Node{
  int u,d;
  bool operator < (const Node & b) const {
    return d>b.d;
  }
};
int d[MAX],p[MAX];
int n,m,tail=0;
bool first=1;

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(t.d!=d[u]) continue;
    FOR(i,0,gtail[u]){
      Edge & e=edge[G[u][i]];
      if(d[e.v]>d[u]+e.w){
        d[e.v]=d[u]+e.w;
        if(first) p[e.v]=G[u][i];
        q.push((Node){e.v,d[e.v]});
      }
    }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    edge[tail++]=(Edge){u,v,w};
    G[u][gtail[u]++]=tail-1;
    edge[tail++]=(Edge){v,u,w};
    G[v][gtail[v]++]=tail-1;
  }
  Dij(1);
  int ansMax=0; first=0;
  FORR(i,2,n){
    w=edge[p[i]].w; edge[p[i]].w=edge[p[i]^1].w=INF;
    Dij(1);
    edge[p[i]].w=edge[p[i]^1].w=w;
    ansMax=max(ansMax,d[n]);
  }
  printf("%d\n",ansMax);

  return 0;
}

/*
const int MAX=1020;
const int INF=0x3f3f3f3f;
struct Edge{
  int u,v,w;
}edge[MAX*MAX];
vector<int> G[MAX];
struct Node{
  int u,d;
  bool operator < (const Node & b) const {
    return d>b.d;
  }
};
int d[MAX],p[MAX];
int n,m,tail=0;
bool first=1;

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(t.d!=d[u]) continue;
    FOR(i,0,G[u].size()){
      Edge & e=edge[G[u][i]];
      if(d[e.v]>d[u]+e.w){
        d[e.v]=d[u]+e.w;
        if(first) p[e.v]=G[u][i];
        q.push((Node){e.v,d[e.v]});
      }
    }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    edge[tail]=(Edge){u,v,w};
    G[u].push_back(tail++);
    edge[tail]=(Edge){v,u,w};
    G[v].push_back(tail++);
  }
  Dij(1);
  int ansMax=0; first=0;
  FORR(i,2,n){
    w=edge[p[i]].w; edge[p[i]].w=edge[p[i]^1].w=INF;
    Dij(1);
    edge[p[i]].w=edge[p[i]^1].w=w;
    ansMax=max(ansMax,d[n]);
  }
  printf("%d\n",ansMax);

  return 0;
}
*/
