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

const double EPS=1e-6;
double x,y,l,d;

double f(double t){
  return l*cos(t) - x/tan(t) + d/sin(t);
}

double fMax(double l, double r){
  double ansMax=0;
  while(r-l>EPS){
    double m1 = l + (r-l)/3;
    double m2 = r - (r-l)/3;
    double f1 = f(m1), f2 = f(m2);
    if(f1 > f2){
      r = m2; ansMax=max(ansMax,f1);
    }else{
      l = m1; ansMax=max(ansMax,f2);
    }
  }
  return ansMax;
}

int main(void){
  while(cin >> x >> y >> l >> d){
    if(x<=d || y<=d) { printf("no\n"); continue; }
    double t = sqrt(l*l+d*d);
    double ll = asin(x/t);
    double rr = acos(d/x);
    printf("%s\n", fMax(ll,rr)<y ? "yes" : "no" );
  }

  return 0;
}

/*
const double PI=acos(-1);
double x,y,l,d;

double f(double t){
  return l*cos(t) - x/tan(t) + d/sin(t);
}

int main(void){
  cin >> x >> y >> l >> d;
  double t = sqrt(l*l+d*d);
  double ll = asin(x/t);
  double rr = acos(d/x);
  printf("s: %lf\n",ll);
  double ansMax=0,ansMin=10000;
  for(double th = ll; th < rr; th += 1e-2){
    double tt = f(th);
    printf("%lf\n",tt);
    ansMax=max(ansMax,tt);
    ansMin=min(ansMin,tt);
  }

  printf("%lf, %lf\n",ansMin,ansMax);

  return 0;
}
*/
