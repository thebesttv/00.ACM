// Tag: 树形DP iii
//  f[u][0]: (u) < k, all <= k
//  f[u][1]: (u) = k, all <= k
//  f[u][2]: (u) < k, exist v > k
//  f[u][3]: (u) = k, exist v > k
//  f[u][4]: (u) > k, only u > k

//    f[u][0] = sum { f[v][0] + w(u,v) | biggest < k ones }
//    f[u][1] = sum { f[v][0] + w(u,v) | biggest k ones or 0}
//    f[u][4] = sum { f[v][0] + w(u,v) | biggest > k ones or 0}

//    f[u][2/3] <- f[v][1/2/4] 懒得写了……
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<LL,int> pii;

const int MAX = 2e5 + 20;
int n,k,fa[MAX]; LL dp[MAX][5];
struct Edge { int v,w; };
VR<Edge> G[MAX]; bool vis[MAX];

void bfs(int u){
  queue<int> q; fa[u] = 0;
  q.push(u); vis[u] = 1;
  while(!q.empty()){
    u = q.front(); q.pop();
    for(Edge e : G[u]) if(!vis[e.v]){
      fa[e.v] = u; vis[e.v] = 1;
      q.push(e.v);
    }
  }
}

struct Node{
  LL sum; int v,w;
  bool operator < (const Node &b) const {
    return sum > b.sum;
  }
};

LL f(int u, int st){
  LL &a = dp[u][st];
  if(a!=-1) return a;
  a = 0;
  if(st <= 1 || st == 4){
    VR<LL> vec;
    for(Edge e : G[u]) if(fa[e.v] == u){
      vec.push_back(f(e.v,0) + e.w);
    }
    sort(ALL(vec), greater<LL>());
#ifdef DEBUG
    printf("f(%d, %d) vec:",u,st);
    for(LL x : vec) printf(" %lld",x); putchar('\n');
#endif

    if(st == 0){  // (i) < k, all <= k
      LL sum = 0;
      FOR(i,0,min(k-1,(int)vec.size())) sum += vec[i];
      a = sum;
    }else if(st == 1){  // (i) == k, all <= k
      if(vec.size() >= k){
        LL sum = 0; FOR(i,0,k) sum += vec[i];
        a = sum;
      }
    }else{  // only (i) > k
      if(vec.size() >= k+1){
        LL sum = 0; for(LL x : vec) sum += x; // choose all
        a = sum;
      }
    }
  }else if(st == 2){
    if(k > 1){
      VR<Node> vec;
      for(Edge e : G[u]) if(fa[e.v] == u){
        vec.push_back({f(e.v, 0) + e.w, e.v, e.w});
      }
      sort(ALL(vec));
#ifdef DEBUG
      for(Node p : vec) printf(" %lld",p.sum); putchar('\n');
#endif
      LL sum = 0;
      FOR(i,0,min(k-1,(int)vec.size())) sum += vec[i].sum;

      // [1] v == k, all in v <= k
      // [2] v < k, exist in v > k
      FOR(i,0,min(k-1,(int)vec.size())){
        int v = vec[i].v;
        LL tsum = sum - vec[i].sum + vec[i].w;
        a = max(a, tsum + f(v, 1));
        a = max(a, tsum + f(v, 2));
        a = max(a, tsum + f(v, 4));
      }

      if(vec.size() > k-1){
        if(k-2 >= 0) sum -= vec[k-2].sum;
        FOR(i,k-1,vec.size()){
          int v = vec[i].v;
          LL tsum = sum + vec[i].w;
          a = max(a, tsum + f(v, 1));
          a = max(a, tsum + f(v, 2));
          a = max(a, tsum + f(v, 4));
        }
      }
    }
  }else{
    VR<Node> vec;
    for(Edge e : G[u]) if(fa[e.v] == u){
      vec.push_back({f(e.v, 0) + e.w, e.v, e.w});
    }
    if(vec.size() >= k){
      sort(ALL(vec));
#ifdef DEBUG
      for(Node p : vec) printf(" %lld",p.sum); putchar('\n');
#endif
      LL sum = 0;
      FOR(i,0,k) sum += vec[i].sum;
      // [1] v == k, all in v <= k
      // [2] v < k, exist in v > k
      FOR(i,0,k){
        int v = vec[i].v;
        LL tsum = sum - vec[i].sum + vec[i].w;
        a = max(a, tsum + f(v, 1));
        a = max(a, tsum + f(v, 2));
        a = max(a, tsum + f(v, 4));
      }

      if(vec.size() > k){
        sum -= vec[k-1].sum;
        FOR(i,k,vec.size()){
          int v = vec[i].v;
          LL tsum = sum + vec[i].w;
          a = max(a, tsum + f(v, 1));
          a = max(a, tsum + f(v, 2));
          a = max(a, tsum + f(v, 4));
        }
      }
    }
  }
#ifdef DEBUG
  printf("f(%d, %d): %lld\n",u,st,a);
#endif
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    FORR(i,1,n){
      G[i].clear(); vis[i] = 0;
      dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = dp[i][4] = -1;
    }

    int u,v,w;
    FOR(i,1,n){
      scanf("%d%d%d",&u,&v,&w);
      G[u].push_back({v,w});
      G[v].push_back({u,w});
    }
    if(k == 0) { printf("0\n"); continue; }
    bfs(1);

    LL ansMax = 0;
    FORR(u,1,n) FOR(i,0,5)
      ansMax = max(ansMax, f(u,i));
    printf("%lld\n",ansMax);
  }

  return 0;
}
