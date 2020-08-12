// Tag: 
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const LL MOD = 998244353;
LL m,p,q;

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}
LL rev(LL x) { return pow_mod(x, MOD-2); }

int main(void){
  LL rev100 = rev(100);
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld",&m,&p,&q);
    LL x1 = ((-m * (q-100))%MOD + q + MOD)%MOD;
    LL x2 = (q * (p-100) %MOD +MOD)%MOD * rev(p)%MOD * m%MOD;
    LL ans = (x1 + x2)%MOD * rev100 %MOD;
    printf("%lld\n",ans);
  }

  return 0;
}
