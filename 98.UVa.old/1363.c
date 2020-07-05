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

LL n, k;

LL sum(LL a, LL d, LL n){
  return n*a + n*(n-1)/2*d;
}

int main(void){
  while(scanf("%lld%lld",&n,&k)==2){
    LL i = 1, ans = 0;
    while(i<=n){
      LL p = k / i;
      if(!p) break;
      LL j = min(k / p, n);
      ans += sum(k%i, -p, j-i+1);
      i = j+1;
    }
    ans += sum(k, 0, n-i+1);
    printf("%lld\n",ans);
  }

  return 0;
}
