// Tag: 树型DP 状压DP iii
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

const int MAX = 50002;
const LL MOD = 1e9+7;
int n,k,a[MAX],cnt[1<<10],f[MAX][1<<10],g[1<<10];
VR<int> G[MAX]; LL ans = 0, pow131[20], sum[20];

void dfs1(int u, int fa){
  const int &c = a[u]; f[u][c] = 1;
  for(int v : G[u]) if(v!=fa){
    dfs1(v,u);
    FOR(st,1,1<<k) (f[u][c|st] += f[v][st])%=MOD;
  }
}
void dfs2(int u, int fa){
  if(fa!=-1){
    const int &c = a[u]; memcpy(g,f[u],sizeof(f[u]));
    FOR(st,1,1<<k) if(f[fa][st]){
      int st1 = st & (~a[fa]);
      int st2 = st | a[fa];
      f[u][c|st] = ((1ll * f[u][c|st] + f[fa][st] - g[st1] - g[st2])%MOD + MOD)%MOD;
    }
  }
  FOR(st,1,1<<k) sum[cnt[st]] += f[u][st];
  for(int v : G[u]) if(v!=fa){
    dfs2(v,u);
  }
}

int cal(int x){
  int c = 0;
  while(x) ++c, x=(x-1)&x;
  return c;
}

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}
LL rev(LL x) { return pow_mod(x,MOD-2); }

int main(void){
  pow131[0] = 1;
  FORR(i,1,10) pow131[i] = pow131[i-1] * 131 %MOD;

  FOR(i,1,1<<10) cnt[i] = cal(i);
#ifdef DEBUG
  FORR(i,1,10) printf("cnt[%d]: %d\n",i,cnt[i]);
#endif

  scanf("%d%d",&n,&k);
  FORR(i,1,n) scanf("%d",&a[i]), a[i] = 1<<(a[i]-1);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].pb(v), G[v].pb(u);
  }

  dfs1(1, -1);
#ifdef DEBUG
  printf("dfs1\n");
  FORR(i,1,n) FOR(st,0,1<<k) if(f[i][st])
    printf("  f[%d][%d]: %d\n",i,st,f[i][st]);
#endif
  dfs2(1,-1);
#ifdef DEBUG
  printf("dfs2\n");
  int tv[20]; MST(tv,0);
  FORR(i,1,n) FOR(st,0,1<<k) if(f[i][st])
    printf("  f[%d][%d]: %d\n",i,st,f[i][st]), tv[cnt[st]] += f[i][st];
  FORR(i,1,10) printf("cnt[%d]: %d\n",i,tv[i]);
#endif
  sum[1] += n; LL rev2 = rev(2);
  FORR(i,1,k) ans = (ans + sum[i] * rev2 %MOD * pow131[i])%MOD;
  printf("%lld\n",ans);

  return 0;
}
