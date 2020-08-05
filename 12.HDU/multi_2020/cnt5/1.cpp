// Tag: 期望 前缀和
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

const LL MOD = 998244353;
const int MAX = 6e6 + 20;

int n; LL f[MAX];

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    //ans = x&1 ? (ans*a%MOD) : ans;
    if(x&1) ans = ans*a%MOD;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}

LL rev(LL x){
  return pow_mod(x,MOD-2);
}

int main(void){
  f[1] = 1;
  FORR(i,2,int(6e6)){
    f[i] = rev(i);
    f[i] = (f[i-1] + f[i]*f[i]%MOD)%MOD;
  }

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    printf("%lld\n", 3*f[n]*rev(n)%MOD);
  }

  return 0;
}
