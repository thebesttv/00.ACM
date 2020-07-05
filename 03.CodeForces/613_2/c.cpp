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

const int MAX = 2020;
LL n, prime[MAX];
int tail;

void div(LL n){
  int r = sqrt(n+0.5);
  tail = 1;
  FORR(i,2,r) if(n%i==0){
    LL &a = prime[tail++]; a = 1;
    while(n%i==0) n/=i, a*=i;
  }
  if(n>1) prime[tail++] = n;
  sort(prime+1,prime+tail);
}

LL f[MAX][MAX];
bool ok(LL m){
  LL l = ceil(1.0*n/m), r = m;
  if(l>m) return false;

  MST(f,0);
  f[1][0] = 1;
  f[1][1] = prime[1];
  if(l<=f[1][0] && f[1][0]<=r) return true;
  if(l<=f[1][1] && f[1][1]<=r) return true;
  FOR(i,2,tail){
    f[i][0] = 1;
    FORR(j,1,i){
      LL &a = f[i][j];
      a = f[i-1][j-1] * prime[i];
      if(l<=a && a<=r) return true;
      if(i>j){
        a = max(a, f[i-1][j]);
      }
      if(l<=a && a<=r) return true;
    }
  }
  return false;
}

int main(void){
  scanf("%lld",&n);
  div(n);
  LL l = 1, r = n;
  while(l<r){
    LL m = (l+r)/2;
    if(ok(m)){
      printf("  ok %lld\n",m);
      r = m;
    }else{
      printf("  bad %lld\n",m);
      l = m+1;
    }
  }
  r = n / l;
  if(l>r) swap(l,r);
  printf("%lld %lld\n",l,r);

  return 0;
}

/*
LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}
LL lcm(LL a, LL b){
  return a/gcd(a,b)*b;
}

pair<LL, LL> f(LL n){
  LL tMin = 0x3f3f3f3f;
  pair<LL, LL> r;
  FORR(i,1,n) if(n%i==0){
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
  FORR(i,5,100){
    auto p = f(i);
    printf("%d: %lld %lld\n",i, p.FI,p.SE);
  }

  return 0;
}
*/
