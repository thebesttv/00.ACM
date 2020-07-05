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

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}

LL phi(LL n){
  if(n==1) return 1;
  int r = sqrt(n+0.5);
  LL ans = n;
  FORR(i,2,r) if(n%i==0){
    ans -= ans / i;
    while(n%i==0) n/=i;
  }
  if(n>1) ans -= ans/n;
  return ans;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&a,&m);
    LL g = gcd(a,m);
    printf("%lld\n", phi(m/g));
  }

  return 0;
}

/*
LL a, m;
VR<LL> p;

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}

LL f(LL n){
  if(n < 1) return 0;
  LL ans = 0;
  int sz = p.size();
  FOR(st, 0, (1<<sz)){
    int cnt = 0;
    LL div = 1;
    FOR(i,0,sz) if(st & (1<<i)){
      div *= p[i]; ++cnt;
    }
    ans += n / div * (cnt&1 ? -1 : 1);
#ifdef DEBUG
    printf("  + %lld / %lld * %d\n", n, div, (cnt&1 ? -1 : 1));
#endif
  }
#ifdef DEBUG
  printf("-> %lld\n",ans);
#endif
  return ans;
}

void div(LL n){
  int r = sqrt(n + 0.5);
  FORR(i,2,r) if(n%i==0){
    p.push_back(i);
    while(n%i==0) n/=i;
    if(n==1) break;
  }
  if(n!=1) p.push_back(n);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    p.clear();
    scanf("%lld%lld",&a,&m);
    div(m);
    LL g = gcd(a, m);
    LL ans = f( (a+m-1)/g ) - f( a/g - 1);
    printf("%lld\n", ans);
  }

  return 0;
}
*/
