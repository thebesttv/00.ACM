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

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) { d = a, x = 1, y = 0; }
  else { gcd(b, a%b, d, y, x); y -= x * (a/b); }
}

LL get(LL a, LL b, LL c){
  if(!a) return -1;
  LL d, x, y;
  gcd(a,b,d,x,y);
  if(c%d) return -1;
  x *= c / d; b = abs(b/d);
  x = (x%b+b)%b;
  return x;
  //x = (x%b+b)%b;
  //b /= d;
  //return x % b;
}

int main(void){
  LL x, y, m, n, l;
  cin >> x >> y >> m >> n >> l;
  LL ans = get(m-n, l, y-x);
  if(ans==-1) printf("Impossible\n");
  else printf("%lld\n",ans);

  return 0;
}
