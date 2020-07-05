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

const int MAX = 2e5 + 20;
const LL MOD = 998244353;
int n; LL p[MAX];

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) d = a, x = 1, y = 0;
  else gcd(b,a%b,d,y,x), y-=x*(a/b);
}

LL rev(LL a){
  LL d,x,y;
  gcd(a,MOD,d,x,y);
  return (x%MOD+MOD)%MOD;
}

int main(void){
  scanf("%d",&n);
  LL r = rev(100);
  FORR(i,1,n){
    scanf("%lld",&p[i]);
    p[i] = p[i] * r % MOD;
  }
  p[n+1] = 1;
  ROR(i,n,1){
    p[i] = p[i+1] * rev(p[i]) % MOD;
  }
  LL ans = 0;
  FORR(i,1,n) ans = (ans + p[i]) % MOD;
  printf("%lld\n",ans);

  return 0;
}

/*
const int MAX = 2e5 + 20;
const LL MOD = 998244353;
int n, p;

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) d = a, x = 1, y = 0;
  else gcd(b, a%b, d, y, x), y -= x * (a/b);
}

LL rev(LL a){
  LL d, x, y;
  gcd(a,MOD,d,x,y);
  return (x+MOD)%MOD;
}

int main(void){
  scanf("%d",&n);
  LL ans = 0;
  FOR(i,0,n){
    scanf("%d",&p);
    ans = (ans + 1ll)*100ll%MOD*rev(p)%MOD;
  }
  printf("%lld\n",ans);

  return 0;
}
*/
