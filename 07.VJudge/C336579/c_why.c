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

const double EPS=1e-8;
double y;

double f(double x){
  return 6 + ( 3 + ( 2 + ( 7 + 8*x )*x )*x )*x - y;
}

int dcmp(double x){
  if(fabs(x)<EPS) return 0;
  return x<0 ? -1 : 1;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lf",&y);
    double l=0,r=100;
    if(dcmp(f(l))>0 || dcmp(f(r))<0){
      printf("No solution!\n"); continue;
    }
    while(r-l>EPS){
      double m=(l+r)/2;
      if(dcmp(f(l)*f(m))<0) r=m;
      else l=m;
    }
    printf("%.4lf\n",l);
  }

  return 0;
}
