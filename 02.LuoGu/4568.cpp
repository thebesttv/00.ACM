// Tag: 分层图 最短路
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
int n,m,k,s,t,d[MAX];

int idx(int u, int i){
  return u + i*n;
}

struct Edge{
  int v,w;
};
VR<Edge> G[MAX];

struct Node{
  int d,u;
  Node(int d, int u): d(d), u(u) { }
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

void Dij(int s){
  MST(d,0x3f);
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


int main(void){
  scanf("%d%d%d",&n,&m,&k);
  scanf("%d%d",&s,&t); ++s, ++t;
  while(m--){
    int u,v,w; scanf("%d%d%d",&u,&v,&w);
    ++u, ++v;
    FOR(i,0,k){
      G[idx(u,i)].pb({idx(v,i),w});
      G[idx(v,i)].pb({idx(u,i),w});
      G[idx(u,i)].pb({idx(v,i+1),0});
      G[idx(v,i)].pb({idx(u,i+1),0});
    }
    G[idx(u,k)].pb({idx(v,k),w});
    G[idx(v,k)].pb({idx(u,k),w});
  }

  Dij(s);
  int ansMin = INT_MAX;
  FORR(i,0,k) ansMin = min(ansMin, d[idx(t,i)]);
  printf("%d\n",ansMin);

  return 0;
}
