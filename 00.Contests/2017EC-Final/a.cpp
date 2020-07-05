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


const LL MOD = 1000000007;
LL n, k;

LL pow_mod(LL n){
  if(!n) return 1;
  LL ans = pow_mod(n/2);
  ans = ans * ans % MOD;
  if(n&1) ans = ans * 2ll % MOD;
  return ans;
}

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) d = a , x = 1, y = 0;
  else gcd(b, a%b, d, y, x), y-=x*(a/b);
}

LL rev(LL a){
  LL d,x,y;
  gcd(a, MOD, d, x, y);
  return (x%MOD + MOD)%MOD;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%lld%lld",&n,&k);
    LL ans = pow_mod(n), sum = 1, x = 1;
    FOR(i,1,k){
      x = x * (n-i+1) % MOD * rev(i) % MOD;
      sum = (sum + x)%MOD;
    }
    ans = (ans - sum + MOD)%MOD;
    printf("Case #%d: %lld\n",kase,ans);
  }

  return 0;
}
