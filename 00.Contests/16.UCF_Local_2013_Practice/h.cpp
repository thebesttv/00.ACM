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

const int MAX = 120;
const double PI = 3.14159265;
int n,x,y,p[MAX],a[MAX],I[MAX];

bool within(int p, int a){
  double d = fabs(atan2(x-p,y))*180/PI;
#ifdef DEBUG
  printf("  (%d,0), a: %d, d: %lf\n",p,a,d);
#endif
  return d <= a+0.01;
}

double rnd(double x){
  x = (int)((x + 0.000501) * 1000) / 1000.0;
  return x;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d%d",&x,&y,&n);
    FOR(i,0,n) scanf("%d",&p[i]);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n) scanf("%d",&I[i]);
    double ans = 0;
    FOR(i,0,n) if(within(p[i],a[i])){
      int d =  (x-p[i])*(x-p[i]) + y*y;
      ans += 1.0*I[i]/d;
    }
    ans = rnd(ans);
    printf("Scene #%d: Spotlight intensity on Stacie is %.3lf\n\n",kase,ans);
  }

  return 0;
}
