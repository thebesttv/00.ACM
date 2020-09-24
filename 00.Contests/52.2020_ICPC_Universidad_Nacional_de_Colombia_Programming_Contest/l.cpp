// Tag: bfs
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

const int to[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};  // DLRU
const char *str = "DLRU";
const int MAX = 2000 * 2000 + 20;
int n,m,sp,ep; char G[2020][2020];
VR<int> vr[2020], vc[2020];

int idx(int x, int y){
  return (x-1) * m + y;
}

struct Node{
  int p,v[4];
}node[MAX];

struct Node2{
  int d,u;
  Node2(int d, int u): d(d), u(u) { }
  bool operator < (const Node2 &b) const {
    return d > b.d;
  }
};
PQ<Node2> q;

const int INF = 0x3f3f3f3f;
int d[MAX];
void Dij(int s){
  MST(d,0x3f); d[s] = 0;
  q.push(Node2(0,s));
  while(!q.empty()){
    auto t = q.top(); q.pop();
    if(t.d != d[t.u]) continue;
    int u = t.u, v;
    FOR(dd,0,4) if(v = node[u].v[dd]){
      if(d[v] > d[u] + 1){
        d[v] = d[u] + 1;
        q.push(Node2(d[v], v));
      }
    }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n){
    scanf("%s",G[i]+1);
    FORR(j,1,m) if(G[i][j] != 'X'){
      vr[i].pb(j); vc[j].pb(i);
      if(G[i][j] == 'S') sp = idx(i,j);
      else if(G[i][j] == 'E') ep = idx(i,j);
    }
  }

  FORR(i,1,n){
    int last = 0;
    for(int j : vr[i]){
      if(last){
        node[idx(i,j)].v[1] = idx(i,last);  // left
        node[idx(i,last)].v[2] = idx(i,j);  // right
#ifdef DEBUG
        printf("  (%d, %d) <-> (%d, %d)\n",i,last,i,j);
#endif
      }
      last = j;
    }
  }
  FORR(j,1,m){
    int last = 0;
    for(int i : vc[j]){
      if(last){
        node[idx(i,j)].v[3] = idx(last,j);  // up
        node[idx(last,j)].v[0] = idx(i,j);  // down
#ifdef DEBUG
        printf("  (%d, %d) <-> (%d, %d)\n",last,j,i,j);
#endif
      }
      last = i;
    }
  }

  Dij(ep);
#ifdef DEBUG
  FORR(i,1,n*m) if(d[i]!=INF)
    printf("d[%d]: %d\n",i,d[i]);
#endif
  if(d[sp] == INF){
    printf("-1\n"); return 0;
  }
  printf("%d\n",d[sp]);
  int p = sp, v;
  while(p != ep){
    FOR(dd,0,4) if(v=node[p].v[dd]){
      if(d[v]+1 != d[p]) continue;
      putchar(str[dd]);
      p = v; break;
    }
  }
  putchar('\n');

  return 0;
}
