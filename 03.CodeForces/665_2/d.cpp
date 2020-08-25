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
const LL MOD = 1e9+7;
int n,m,dp[MAX];LL p[MAX];
VR<int> G[MAX]; VR<LL> cnt;

int f(int u, int fa){
  int &a = dp[u];
  if(a!=-1) return a;
  a = 1;
  for(int v : G[u]) if(v!=fa){
    int x = f(v,u); a += x;
    cnt.pb(1ll * x * (n-x));
  }
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    cnt.clear();
    scanf("%d",&n); FORR(i,1,n) G[i].clear(), dp[i]=-1;
    int u,v;
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      G[u].pb(v), G[v].pb(u);
    }

    scanf("%d",&m);
    FOR(i,0,m) scanf("%lld",&p[i]);
    if(m < n-1) FOR(i,m,n-1) p[i]=1, m=n-1;
    sort(p,p+m);

    if(m > n-1){
      FOR(i,n-1,m) p[n-2] = p[n-2] * p[i]%MOD;
      m = n-1;
    }

    f(1, -1);
    sort(ALL(cnt));
#ifdef DEBUG
    FOR(i,0,cnt.size()) printf("%d: cnt: %lld, p: %lld\n",i,cnt[i],p[i]);
#endif
    LL ans = 0;
    FOR(i,0,n-1){
      cnt[i] %= MOD;
      ans = (ans + cnt[i] * p[i]%MOD)%MOD;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
