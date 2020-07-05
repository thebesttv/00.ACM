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

const int MAX = 5e5 + 20;
const LL MOD = 998244353;
int n,k;
LL frac[MAX],rfrac[MAX];

LL powMod(LL a, LL x){
  LL ans = 1;
  while(x){
    if(x&1) ans = ans*a%MOD;
    a = a*a%MOD;
    x>>=1;
  }
  return ans;
}

LL rev(LL x){
  return powMod(x, MOD-2);
}

LL C(LL n, LL m){
  return frac[n] * rfrac[m] % MOD * rfrac[n-m] % MOD;
}

int main(void){
  frac[0] = rfrac[0] = frac[1] = rfrac[1] = 1;
  FORR(i,2,int(5e5))
    frac[i] = frac[i-1] * i % MOD,
    rfrac[i] = rev(frac[i]);
  scanf("%d%d",&n,&k);

  LL ans = 0;
  int i = 1, j;
  while(i <= n){
    j = n / (n/i);
    LL left = n/i - 1;
    if(left < k-1) break;
    ans = ( ans + (j-i+1) * C( left, k-1 ) % MOD) % MOD;
    i = j+1;
  }
  printf("%lld\n",ans);

  return 0;
}
