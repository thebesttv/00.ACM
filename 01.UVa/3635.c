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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10020;
//const double PI=3.141592653589793;  // 注意精度
const double PI=acos(-1.0);
const double EPS=1e-6;
int n,f;
double a[MAX];

bool ok(double s){
  int tot=0;
  FOR(i,0,n) tot += floor(a[i]/s);
  return tot>=f;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&f); f++;
    double sMax=0;
    FOR(i,0,n){
      int r; scanf("%d",&r);
      a[i]=r*r*PI; sMax=max(sMax,a[i]);
    }
    double l=0,r=sMax;
    while(r-l>EPS){
      double m=(l+r)/2;
      if(ok(m)) l=m;
      else r=m;
    }
    printf("%.4lf\n",l);
  }

  return 0;
}
