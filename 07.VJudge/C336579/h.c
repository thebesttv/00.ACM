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
const double PI=acos(-1);
double x,y,v;

int dcmp(double x){
  if(fabs(x)<EPS) return 0;
  return x<0 ? -1 : 1;
}

double f(double t, double x){
  double a = 2 * v * v * cos(t) * cos(t); a = -9.8/a;
  double b = tan(t);
  return ( b + a*x )*x;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lf%lf%lf",&x,&y,&v);
    if(!dcmp(v)) { printf("-1\n"); continue; }
    if(!dcmp(x)){
      if(dcmp(v*v/9.8/2 - y)>=0) printf("%.6lf\n",PI/2);
      else printf("-1\n");
      continue;
    }
    double l=0, r=PI/2; bool possible=0;
    while(r-l>EPS){
      //printf("%lf, %lf\n",l,r);
      double m=(l+r)/2;
      if(dcmp(f(m,x)-y)>=0){
        r=m; possible=1;
      }else l=m;
    }
    if(possible) printf("%.6lf\n",l);
    else printf("-1\n");
  }

  return 0;
}
