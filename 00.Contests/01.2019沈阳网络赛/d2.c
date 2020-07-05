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

const int MAX=10020;
const int INF=0x3f3f3f3f;

int dis[MAXN];
struct Edge{
  int u,w,next;
}from[MAXM],to[MAXM]; //from为记忆化搜索服务，to为最短路服务
int se[MAXN],tailS=1;
int ee[MAXN],tailE=1;
struct Node{  //for Dij
  int u,d;
  bool operator < (const Node & b) const { return d>b.d; };
};

inline void addEdge(int u, int v, int w){
  int t=tailS++;
  to[t]=(Edge){v,w,se[u]}; se[u]=t;
  t=tailE++;
  from[t]=(Edge){u,w,ee[v]}; ee[v]=t;
}
void Dij(int s){
  MST(dis,0x3f); dis[s]=0;
  PQ<Node> q; q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u,v;
    if(dis[u]!=t.d) continue;
    for(int i=se[u];i;i=to[i].next)
      if(dis[v=to[i].u]>t.d+to[i].w){
        dis[v]=t.d+to[i].w;
        q.push((Node){v,dis[v]});
      }
  }
}

int main(void){
  while(scanf("%d",&n)==1){
    int u,v,d;
    FOR(i,1,n){
      scanf("%d%d%d",&u,&v,&d);
      addEdge(u,v,d);
    }
    Dij(0);

    FOR(//
  }

  return 0;
}
