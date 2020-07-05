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

const int MAX = 120;
const LL MOD = 1000000007;
int n,k,d;
LL dp[MAX];

LL f(int u, int d){
  if(u==0) return 1;
  LL &a = dp[u];
  if(a != -1) return a;

  a = 0;
  FORR(i,1,d) if(u >= i)
    a = (a + f(u-i, d)) % MOD;
  return a;
}

int main(void){
  scanf("%d%d%d",&n,&k,&d);
  MST(dp, -1);
  LL ans = f(n, k);
  MST(dp, -1);
  LL t = f(n, d-1);
  ans = (ans - t + MOD)%MOD;
  printf("%lld\n",ans);

  return 0;
}
