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

LL a,k;

int f(LL x){
  int tMin = 9, tMax = 0;
  while(x){
    tMin = min(1ll*tMin, x%10);
    tMax = max(1ll*tMax, x%10);
    x/=10;
  }
  return tMin * tMax;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&a,&k); --k;
    LL x; while(k--){
      x=f(a);
      if(!x) break;
      a += x;
    }
    printf("%lld\n",a);
  }

  return 0;
}
