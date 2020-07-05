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

LL n,k;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&n,&k);
    LL ansMax = (n/k)*k;

    /*
    LL h = min(n, k/2);
    LL a = (n-h)/k;
#ifdef DEBUG
    printf("  a: %d, h: %d\n",a,h);
#endif
    ansMax = max(ansMax, min(n, k*a + h));
    */
    n -= ansMax;
    ansMax = max(ansMax, ansMax + min(n, k/2) );

    printf("%lld\n", ansMax);
  }

  return 0;
}
