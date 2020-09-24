// Tag: 层次图 最短路
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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 2e5 + 20;
const int INF = 0x3f3f3f3f;
int n,m,a,b,k;

int idx(int u, int k){
  return u + k*n;
}
struct Graph{
  struct Edge { int v,w; };
  VR<Edge> G[MAX];
  int d1[MAX],d2[MAX];

  void addEdge(int u, int v, int w){
    G[u].pb({v,w});
  }

  struct Node{
    int d,u;
    Node(int d, int u): d(d), u(u) { }
    bool operator < (const Node &b) const {
      return d > b.d;
    }
  };

  void Dij(int s, int *d){
    d[s] = 0; PQ<Node> q;
    q.push(Node(0,s));
    while(!q.empty()){
      auto t = q.top(); q.pop();
      if(t.d != d[t.u]) continue;
      int u = t.u;
      for(Edge &e : G[u]){
        if(d[e.v] > d[u] + e.w){
          d[e.v] = d[u] + e.w;
          q.push(Node(d[e.v], e.v));
        }
      }
    }
  }

  void cal(){
    MST(d1,0x3f); MST(d2,0x3f);
    Dij(a, d1); Dij(b, d2);
#ifdef DEBUG
  FORR(i,1,n) FORR(j,0,k)
    printf("(%d, %d): d1: %d, d2: %d\n",i,j,d1[idx(i,j)],d2[idx(i,j)]);
#endif
  }
}G1, G2;

int main(void){
  scanf("%d%d",&n,&m);
  scanf("%d%d%d",&a,&b,&k); ++a,++b;
  while(m--){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w); ++u, ++v;
    FOR(i,0,k){
      G1.addEdge(idx(u,i), idx(v,i), w);
      G2.addEdge(idx(v,i), idx(u,i), w);

      G1.addEdge(idx(u,i), idx(v,i+1), 0);
      G2.addEdge(idx(v,i), idx(u,i+1), 0);
    }

    G1.addEdge(idx(u,k), idx(v,k), w);
    G2.addEdge(idx(v,k), idx(u,k), w);
  }
  G1.cal(); G2.cal();

  int ansMin = INF, rec = -1;

  FORR(u,1,n) if(u!=a && u!=b){
    int ta = INF, tb = INF, tai=-1,taj=-1,tbi=-1,tbj=-1;
    FORR(i,0,k) FORR(j,0,k-i){
      ta = min(ta, G1.d1[idx(u,i)] + G2.d1[idx(u,j)]);
      tb = min(tb, G1.d2[idx(u,i)] + G2.d2[idx(u,j)]);
      /*
      if(d1[idx(u,i)] + d1[idx(u,j)] < ta){
        ta = d1[idx(u,i)] + d1[idx(u,j)];
        tai = i, taj = j;
      }
      if(d2[idx(u,i)] + d2[idx(u,j)] < tb){
        tb = d2[idx(u,i)] + d2[idx(u,j)];
        tbi = i, tbj = j;
      }
      */
    }
    if(ta + tb < ansMin){
      ansMin = ta + tb; rec = u;
    }
  }

  if(ansMin == INF) printf(">:(\n");
  else printf("%d %d\n",rec-1,ansMin);

  return 0;
}
