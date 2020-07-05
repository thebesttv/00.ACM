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
typedef long long LL;
typedef long long unsigned LLU;

LL a,b,a_,b_,c,d,n,x,y,k;

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) { d=a; x=1; y=0; }
  else { gcd(b,a%b,d,y,x); y-=x*(a/b);}
}

int main(void){
  cin >> n >> c >> a >> b;
  gcd(a,b,d,x,y);
  if(c%d!=0) { printf("-1\n"); return 0;}
  x = x * (c / d); y = y * (c / d);
  a_ = a/d, b_ = b/d;
  LL l = (-1.0* x/b_)-1, r = y/a_ + 1;
  LL l2 = (1.0*n-x-y)/(b_ - a_)-1;
  LL ax=-1, ay=-1;
  for(LL k=max(l,l2);k<=r;k++){
    LL tx = x + k*b_, ty = y - k*a_;
    if(tx>=0 && ty>=0 && tx+ty<=n){
      ax=tx, ay=ty;
    }
  }
  if(ax==-1) printf("-1\n");
  else printf("%lld %lld %lld\n",ax,ay,n-ax-ay);

  return 0;
}
