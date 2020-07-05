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

LL X1, Y1, X2, Y2;

LL s(LL n){
  return n*(n+1)/2;
}

LL s3(LL n, LL d){
  return n * (n * n - 1 - 3 * d * (d-1)) / 6;
}

LL s2(LL d, LL n){
  n = n + d - 1;
  return s3(n, d) - s3(d-1, d);
}

LL f(LL x, LL y, LL dx){
  LL a = s(x+y-2) + x;
  LL ans = a * dx + s2(x+y-1, dx);
#ifdef DEBUG
  printf("  f(%lld, %lld, %lld): %lld, a: %lld, s2: %lld\n",x,y,dx,ans,a,s2(x+y-1, dx));
#endif
  return ans;
}

LL g(LL x, LL y, LL dx){
  LL a = s(x+y-2) + x;
  LL ans = a * dx + s2(x+y, dx);
#ifdef DEBUG
  printf("  g(%lld, %lld, %lld): %lld, a: %lld\n",x,y,dx,ans,a);
#endif
  return ans;
}

LL h(LL x, LL y){
  return s(x+y-2) + x;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld%lld",&X1,&Y1,&X2,&Y2);
    LL dx = X2 - X1 + 1;
    LL dy = Y2 - Y1 + 1;
    LL ans1 = f(X1, Y1, dy) + g(X1, Y2, dx) - h(X1,Y2);
    LL ans2 = f(X2, Y1, dy) + g(X1, Y1, dx) - h(X2,Y1);
#ifdef DEBUG
    printf("  ans1: %lld, ans2: %lld\n",ans1,ans2);
#endif
    printf("%lld\n",ans2 - ans1 + 1);
  }
  
  return 0;
}
