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

int n; LL s, x;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    s = x = 0;
    LL v; scanf("%d",&n);
    while(n--){
      scanf("%lld",&v);
      s += v, x ^= v;
    }
    LL a = s + x;
    if(s + x + a == 2 * (x^x^a)){
      printf("2\n%lld %lld\n",x,a);
    }
    /*
    if(s == 2*x){
      printf("0\n\n"); continue;
    }

    LL a = (2*x - s)/2;
    if(a>=0 && s + a + a == 2*x){
      printf("2\n%lld %lld\n",a,a); continue;
    }

    a = (2*(x ^ 1ll) - s - 1) / 2;
    if(a>=0 && (s+a+a+1) == 2*(x^1ll)){
      printf("3\n%lld %lld %lld\n",a,a,1ll);
    }
    */
  }

  return 0;
}
