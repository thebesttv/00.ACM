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

int n,m;
LL cp0,cp1,cq0,cq1;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    cp0=cp1=cq0=cq1=0;
    int q,p;

    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d",&p);
      if(p&1) ++cp1;
      else ++cp0;
    }

    scanf("%d",&m);
    FOR(i,0,m){
      scanf("%d",&q);
      if(q&1) ++cq1;
      else ++cq0;
    }
    LL ans = cp0*cq0 + cp1*cq1;
    printf("%lld\n",ans);
  }

  return 0;
}
