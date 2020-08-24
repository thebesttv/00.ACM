// Tag: 贪心 模拟
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
int n; LL s, sum;
struct Edge { int v,w; };
VR<Edge> G[MAX];

struct Node{
  int w,k; LL x;
  Node(int w, int k) : w(w), k(k) {
    x = 1ll * (w - w/2) * k;
  }
  bool operator < (const Node &b) const {
    return x < b.x;
  }
};
PQ<Node> q;

int dfs(int u, int fa){
  if(G[u].size() == 1 && G[u][0].v == fa) return 1;
  int cnt = 0;
  for(Edge e : G[u]) if(e.v!=fa){
    int siz = dfs(e.v, u); cnt += siz;
    sum += 1ll * e.w * siz;
    q.push(Node(e.w, siz));
  }
  return cnt;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    while(!q.empty()) q.pop();
    scanf("%d%lld",&n,&s);
    FORR(i,1,n) G[i].clear();
    int u,v,w;
    FOR(i,1,n){
      scanf("%d%d%d",&u,&v,&w);
      G[u].pb({v,w}), G[v].pb({u,w});
    }
    sum = 0; dfs(1, -1);

    int cnt = 0;
    while(sum > s){
      Node t = q.top(); q.pop();
      ++cnt; sum -= t.x;
      q.push(Node(t.w/2, t.k));
    }
    printf("%d\n",cnt);
  }

  return 0;
}
