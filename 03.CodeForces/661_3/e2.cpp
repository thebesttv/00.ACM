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
struct Edge { int v,w,c; };
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
PQ<Node> q[3];

int dfs(int u, int fa){
  if(G[u].size() == 1 && G[u][0].v == fa) return 1;
  int cnt = 0;
  for(Edge e : G[u]) if(e.v!=fa){
    int siz = dfs(e.v, u); cnt += siz;
    sum += 1ll * e.w * siz;
    q[e.c].push(Node(e.w, siz));
  }
  return cnt;
}

void take(PQ<Node> &q){
  Node t = q.top(); q.pop();
  sum -= t.x; q.push(Node(t.w/2, t.k));
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FORR(i,1,2) while(!q[i].empty()) q[i].pop();
    scanf("%d%lld",&n,&s);
    FORR(i,1,n) G[i].clear();
    int u,v,w,c;
    FOR(i,1,n){
      scanf("%d%d%d%d",&u,&v,&w,&c);
      G[u].pb({v,w,c}), G[v].pb({u,w,c});
    }
    sum = 0; dfs(1, -1);

    int cnt = 0;
    if(q[2].empty()){
      while(sum > s) { take(q[1]); ++cnt; }
    }else if(q[1].empty()){
      while(sum > s) { take(q[2]); cnt+=2; }
    }else{
      while(sum > s){
        Node t1 = q[1].top(); q[1].pop();
        if(sum - t1.x <= s) { ++cnt; break; }

        Node t2(t1.w/2, t1.k);
        LL x = t1.x + max(t2.x, q[1].empty() ? 0 : q[1].top().x);

        if(x >= q[2].top().x){
          sum -= t1.x; ++cnt; q[1].push(t2);
        }else{
          q[1].push(t1);
          take(q[2]); cnt+=2;
        }
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}
