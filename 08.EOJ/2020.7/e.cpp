// Tag: 格雷码 todo
// 改为格雷码实现
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

const int MAX = 40020;
int n,f[15][MAX],k[MAX]; LL p[MAX];

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    if(x&1) ans *= a;
    a *= a;
    x >>= 1;
  }
  return ans;
}

int main(void){
  scanf("%d",&n); LL c = 1, s, t = 1;
  FOR(i,0,n) scanf("%lld%d",&p[i],&k[i]), c *= k[i]+1;

  FOR(i,0,n){
    if(i) t *= (k[i-1] + 1);

    s = c; int rev = 0, tail = 0;
    while(s){
      if(!rev) FORR(j,0,k[i]) FOR(kk,0,t) f[i][tail++] = j;
      else ROR(j,k[i],0) FOR(kk,0,t) f[i][tail++] = j;
      s -= (k[i]+1) * t;
      rev ^= 1;
    }
  }
#ifdef DEBUG
  FOR(i,0,c){
    FOR(j,0,n) printf(" %d",f[j][i]); putchar('\n');
  }
#endif
  FOR(i,0,c){
    LL t = 1;
    FOR(j,0,n) t *= pow_mod(p[j],f[j][i]);
    printf("%lld\n",t);
  }

  return 0;
}
