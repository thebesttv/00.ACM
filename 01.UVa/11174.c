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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 40020;
const LL MOD = 1000000007;
int n, m, s[MAX];
VR<int> G[MAX];

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) d = a, x = 1, y = 0;
  else gcd(b,a%b,d,y,x), y-=x*(a/b);
}

LL rev(LL a){
  LL d, x, y;
  gcd(a, MOD, d, x, y);
  return (x+MOD)%MOD;
}

int dfs(int u){
  int &a = s[u];
  if(a) return a;
  a = 1;
  for(int v : G[u])
    a += dfs(v);
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(s,0);
    scanf("%d%d",&n,&m);
    FORR(i,1,n) G[i].clear();

    int u, v;
    while(m--){
      scanf("%d%d",&v,&u);
      if(u<=n) G[u].push_back(v);
    }

    LL ans = 1;
    FORR(i,2,n) ans = ans * i % MOD;

    LL q = 1;
    FORR(i,1,n){
      q = q * dfs(i) % MOD;
    }
    ans = ans * rev(q) % MOD;

    printf("%lld\n",ans);
  }

  return 0;
}
