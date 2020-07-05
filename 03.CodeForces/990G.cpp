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
typedef pair<int,int> pii;

const int MAX = 2e5, MAX_ = MAX+20;
int n, a[MAX_], mu[MAX_];
LL g[MAX_];
VR<int> d[MAX_], v[MAX_], G[MAX_];
int vis[MAX_], col;

void init(){
  mu[1] = 1;
  FORR(i,1,MAX){
    d[i].push_back(i);
    for(int j=i+i;j<=MAX;j+=i){
      d[j].push_back(i);
      mu[j] -= mu[i];
    }
  }
}

int dfs(int u, int d){
  vis[u] = col;
  int s = 1;
  for(int v : G[u]) if(a[v]%d==0 && vis[v]!=col){
    s += dfs(v, d);
  }
  return s;
}

int main(void){
  init();
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    for(int x : d[a[i]])
      v[x].push_back(i);
  }
  int x, y;
  FOR(i,1,n){
    scanf("%d%d",&x,&y);
    G[x].push_back(y);
    G[y].push_back(x);
  }

  // g
  FORR(d,1,MAX) if(v[d].size()){
    ++col;
    LL &a = g[d];
    for(int u : v[d]) if(vis[u]!=col){
      int t = dfs(u, d);
      a += (t+1ll)*t/2;
    }
#ifdef DEBUG
    if(a) printf("  g(%d): %lld\n",d,a);
#endif
  }

  FORR(d,1,MAX){
    LL ans = 0;
    ROR(k,MAX/d,1)
      ans += mu[k] * g[k*d];
    if(ans) printf("%d %lld\n",d,ans);
  }

  return 0;
}
