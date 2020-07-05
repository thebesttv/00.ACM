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

typedef pair<LL,LL> pii;
int n;

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}

pii simplify(pii a){
  LL t = gcd(a.FI,a.SE);
  a.FI /= t, a.SE /= t;
  return a;
}

int main(void){
  while(scanf("%d",&n)==1){
    pii sum = {1,1};
    FORR(i,2,n){
      pii t = {1,i};
      sum = { sum.FI * t.SE + t.FI * sum.SE, sum.SE * t.SE };
      sum = simplify(sum);
    }
    sum.FI *= n;
    sum = simplify(sum);
    if(sum.SE==1){
      printf("%lld\n",sum.FI);
    }else{
      LL a = sum.FI / sum.SE, t;
      sum.FI %= sum.SE;

      int cntA = 0, cntF = 0, cntS = 0;
      t=a; while(t) ++cntA, t/=10;
      t=sum.FI; while(t) ++cntF, t/=10;
      t=sum.SE; while(t) ++cntS, t/=10;

      printf("%*s %lld\n",cntA,"",sum.FI);
      printf("%lld ",a);
      FOR(i,0,max(cntF,cntS)) putchar('-'); putchar('\n');
      printf("%*s %lld\n",cntA,"",sum.SE);
    }
  }

  return 0;
}
