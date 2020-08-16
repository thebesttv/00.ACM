// Tag: 坑 树型DP 逆元
// 在求 rev(f[v]+1) 时，若 f[v]+1 == 0，则不能求逆元，只能重新计算
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

const LL MOD = 1e9+7;
const int MAX = 1e6 + 20;
int n; VR<int> G[MAX];
LL f[MAX],g[MAX];

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}
LL rev(LL x) { return pow_mod(x,MOD-2); }

LL dfs1(int u, int fa){
  LL &a = f[u]; a = 1;
  for(int v : G[u]) if(v!=fa){
    a = a * (dfs1(v,u)+1) %MOD;
  }
  return a;
}

void dfs2(int u, int fa){
  LL t = g[u] * f[u] %MOD;
  for(int v : G[u]) if(v!=fa){
    if(f[v]+1 == MOD){  // 不算逆元
      LL &x = g[v]; x = g[u];
      for(int v2 : G[u]) if(v2 != v && v2 != fa){
        x = x * (f[v2] + 1)%MOD;
      }
      x = (x+1)%MOD;
    }else{
      g[v] = (t * rev(f[v]+1) + 1) %MOD;
    }
    dfs2(v,u);
  }
}

int main(void){
  scanf("%d",&n);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].pb(v), G[v].pb(u);
  }

  MST(f,-1), MST(g,-1); g[1] = 1;
  dfs1(1,-1); dfs2(1,-1);
#ifdef DEBUG
  FORR(i,1,n) printf("%d: f: %lld, g: %lld\n",i,f[i],g[i]);
#endif
  FORR(i,1,n) printf("%lld\n", f[i]*g[i] %MOD);

  return 0;
}
