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
typedef long long LL;
typedef long long unsigned LLU;

int n;
using pii = pair<LL, LL>;

LL gdb(LL a, LL b){
  return !b ? a : gdb(b, a%b);
}
pii simplify(pii x){
  LL d = abs(gdb(x.first, x.second));
  return { x.first / d, x.second / d };
}

int main(void){
  pii a,sum;
  scanf("%d",&n);

  scanf("%lld/%lld",&sum.first, &sum.second);
  sum = simplify(sum);

  FOR(i,1,n){
    scanf("%lld/%lld",&a.first, &a.second); a = simplify(a);
    pii t { a.first * sum.second + a.second * sum.first,
      a.second * sum.second };
    sum = simplify(t);
  }
  if(sum.first % n == 0) sum.first /= n;
  else sum.second *= n;
  sum = simplify(sum);

  if(sum.second == 1) printf("%lld\n",sum.first);
  else printf("%lld/%lld\n",sum.first,sum.second);

  return 0;
}
