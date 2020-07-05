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

int n;

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    int n; double a, b, s; double ans = 0;
    scanf("%d",&n);
    FORR(i,0,n){
      scanf("%lf",&s); ans += s;
    }
    double bMax = 0;
    FOR(i,0,n){
      scanf("%lf%lf",&a,&b);
      bMax = max(bMax, b);
    }
    ans += bMax;
    printf("Case #%d: %lf\n",kase,ans);
  }

  return 0;
}
