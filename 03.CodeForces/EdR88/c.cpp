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

LL c,t,h;

void update(LL x, double &dMin, LL &ansMin){
  if(x<1) return;
  double d = fabs( (x*h + (x-1.0)*c) / (2*x-1.0) - t);
#ifdef DEBUG
  printf("  %lld H + %lld C: %lf, d: %lf\n",x,x-1,(x*h + (x-1.0)*c) / (2*x-1),d);
#endif
  if(d < dMin){
    dMin = d;
    ansMin = 2 * x - 1;
  }else if(fabs(d-dMin) < 1e-8){
    ansMin = min(ansMin, 2*x-1);
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld",&h,&c,&t);
    if(h+c == t*2){
      printf("2\n"); continue;
    }

    double dMin = fabs((h+c)/2.0 - t);
    LL ansMin = 2;
    LL x = (c-t) / (h+c-2*t);

    update(x, dMin, ansMin);
    update(x-1, dMin, ansMin);
    update(x+1, dMin, ansMin);
    printf("%lld\n",ansMin);
  }

  return 0;
}
