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

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}
LL lcm(LL a, LL b){
  return a/gcd(a,b)*b;
}

pair<LL, LL> f(LL n){
  LL tMin = 0x3f3f3f3f3f3f3f3f;
  pair<LL, LL> r;
  int rr = sqrt(n+0.5);
  FORR(i,1,rr) if(n%i==0){
    LL a = i, b = n/i;
    if(lcm(a,b)==n){
      if(max(a,b) < tMin){
        tMin = max(a,b);
        r = {a,b};
      }
    }
  }
  return r;
}

int main(void){
  LL n; scanf("%lld",&n);
  auto p = f(n);
  if(p.FI > p.SE) swap(p.FI, p.SE);
  printf("%lld %lld\n",p.FI, p.SE);

  return 0;
}
