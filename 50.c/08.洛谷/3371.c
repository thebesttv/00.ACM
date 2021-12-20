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

const int MAXN=10020;
const int MAXM=500020;
const int INF=0x3f3f3f3f;
const int ANS_INF=2147483647;

int n,m,s;
struct Edge{
  int v,w,next;
}edge[MAXM];
int se[MAXN],tailE=1;
int d[MAXN],cnt[MAXN];
bool inq[MAXN];

inline void addEdge(int u, int v, int w){
  int t=tailE++;
  edge[t] = (Edge){v,w,se[u]}; se[u]=t;
}
bool SPFA(int s){
  MST(d,0x3f); MST(cnt,0); MST(inq,0);
  queue<int> q; q.push(s);
  d[s]=0; inq[s]=1; cnt[s]=1;
  while(!q.empty()){
    int u=q.front(),v; q.pop();
    inq[u]=0;
    for(int i=se[u];i;i=edge[i].next){
      if(d[v=edge[i].v]>d[u]+edge[i].w){
        d[v]=d[u]+edge[i].w;
        if(!inq[v]){
          q.push(v);
          if(++cnt[v]>=n) return false;
        }
      }
    }
  }
  return true;
}

int main(void){
  scanf("%d%d%d",&n,&m,&s);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
  }

  SPFA(s);

  FORR(i,1,n) printf("%d ",d[i]>=INF ? ANS_INF : d[i]);
  putchar('\n');

  return 0;
}

/*
const int MAXN=10020;
const int MAXM=500020;
const int INF=0x3f3f3f3f;
const int ANS_INF=2147483647;

int n,m,s;
struct Edge{
  int v,w,next;
}edge[MAXM];
int se[MAXN],tailE=1;
int d[MAXN];
bool vis[MAXN];
struct Node{
  int u,d;
  bool operator < (const Node & b) const {return d>b.d;}
};
PQ<Node> q;

inline void addEdge(int u, int v, int w){
  int t=tailE++;
  edge[t] = (Edge){v,w,se[u]}; se[u]=t;
}
//void Dij(int s){
//  MST(d,0x3f); d[s]=0;
//  FOR(i,0,n){
//    RE int tMin=INF,u=-1;
//    FORR(j,1,n) if(d[j]<tMin && !vis[j]) tMin=d[u=j];
//    vis[u]=1;
//    for(int i=se[u];i;i=edge[i].next){
//      Edge & e=edge[i];
//      d[e.v]=min(d[e.v],d[u]+e.w);
//    }
//  }
//}
void Dij(int s){
  MST(d,0x3f); d[s]=0;
  q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(d[u]!=t.d) continue;
    for(int i=se[u];i;i=edge[i].next){
      Edge & e=edge[i];
      if(d[e.v]>d[u]+e.w){
        d[e.v]=d[u]+e.w;
        q.push((Node){e.v,d[e.v]});
      }
    }
  }
}

int main(void){
  scanf("%d%d%d",&n,&m,&s);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
  }

  Dij(s);

  FORR(i,1,n) printf("%d ",d[i]>=INF ? ANS_INF : d[i]);
  putchar('\n');

  return 0;
}
*/
