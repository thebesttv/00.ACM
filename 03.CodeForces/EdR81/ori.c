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

LL a, m;
VR<LL> p;

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&a,&m);
    LL g = gcd(a,m);
    LL ans = 0;
    FOR(x,0,m) if(gcd(a+x,m) == g){
#ifdef DEBUG
      printf("  (%lld, %lld) = %lld\n",(a+x)/g,m/g,g);
#endif
      ++ans;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
