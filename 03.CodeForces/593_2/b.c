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
typedef long long LL;
typedef long long unsigned LLU;

const LL MOD = 1e9 + 7;
LL powmod(LL x, LL y){
  if(y==0) return 0ll;
  if(y==1) return x;
  LL ans = powmod(x,y/2);
  ans = ans * ans % MOD;
  if(y&1) ans = ans * x % MOD;
  return ans;
}

int main(void){
  LL m,n; scanf("%lld%lld",&n,&m);
  LL ans = (powmod(2,m)-1ll+MOD)%MOD;
  ans = powmod(ans,n);
  printf("%lld\n",ans);

  return 0;
}
