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
double L,L2,n,c;

int main(void){
  while(scanf("%lf%lf%lf",&L,&n,&c)==3){
    if(L<0 && n<0 && c<0) break;
    L2 = (1 + n*c)*L;
    double l=0, r=L/2;
    while(r-l>EPS){
      double m=(l+r)/2;
      //double R = ( L*L/4 + m*m )/2/m;
      double R = (L*L + 4*m*m)/8/m;
      double s = 2 * R * asin(L/R/2);
      if(s < L2) l=m;
      else r=m;
    }
    printf("%.3lf\n",l);
  }

  return 0;
}
