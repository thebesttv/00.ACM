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

const int MAX = 1e6 + 20;
const LL MOD = 1e9+7;
int n,m,a[MAX];
LL frac[MAX],rfrac[MAX];

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    if(x&1) ans = ans * a % MOD;
    a = a * a % MOD;
    x>>=1;
  }
  return ans;
}

LL rev(LL n){
  return pow_mod(n,MOD-2);
}

LL C(int n, int m){
  return frac[n] * rfrac[m] % MOD * rfrac[n-m] % MOD;
}

int main(void){
  int T; scanf("%d",&T);
  frac[0] = frac[1] = 1;
  rfrac[0] = rfrac[1] = 1;
  FORR(i,2,int(1e6)){
    frac[i] = frac[i-1]*i%MOD;
    rfrac[i] = rev(frac[i]);
  }

  while(T--){
    scanf("%d%d",&n,&m);
    FOR(i,0,n) scanf("%d",&a[i]);
    sort(a,a+n);
    LL ans = 0;
    FOR(i,m-1,n){
      ans = (ans + a[i]*C(i,m-1)%MOD)%MOD;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
