// Tag: notag
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

const int MAX = 1e5 + 20;
int n,m,d[MAX]; VR<int> G[MAX];

struct Node{
  int d,u;
  Node(int d, int u): d(d), u(u) { }
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
PQ<Node> q;

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  q.push(Node(0,s));
  while(!q.empty()){
    Node t=q.top(); q.pop();
    if(t.d!=d[t.u]) continue;
    int u=t.u;
    for(int v : G[u]){
      if(d[v] > d[u] + 1){
        d[v] = d[u] + 1;
        q.push(Node(d[v], v));
      }
    }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  if(n == 1) { printf("0\n"); return 0; }

  while(m--){
    int u,v; scanf("%d%d",&u,&v);
    G[u].pb(v), G[v].pb(u);
  }
  Dij(1);
#ifdef DEBUG
  FORR(i,1,n) printf("d[%d]: %d\n",i,d[i]);
#endif
  printf("%d\n",max(d[n] - 1, 0));

  return 0;
}
