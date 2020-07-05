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

LL a,b,c,d;

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}

void simplify(LL &a, LL &b){
  LL g = gcd(a,b);
  a/=g, b/=g;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    LL t1 = a*d, t2 = c*b;
    simplify(t1,t2);
    LL n = t1, m = t2;
    LL g1 = a, g2 = b*n;
    simplify(g1,g2);

    /*
    LL l1 = a*c, l2 = b*d;
    simplify(l1,l2);
    l1 *= g2, l2 *= g1;
    simplify(l1,l2);
    */
    LL l1 = a*m, l2 = b;
    simplify(l1,l2);

    printf("%lld/%lld %lld/%lld\n",g1,g2,l1,l2);
  }

  return 0;
}
