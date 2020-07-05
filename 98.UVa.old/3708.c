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

int main(void){
  int n,m;
  while(scanf("%d%d",&n,&m)==2){
    double ans=0;
    FOR(i,1,n){
      double pos = (double)i * (m+n)/n;
      ans += fabs( pos - floor(pos+0.5) ) / (m+n);
    }
    printf("%.4lf\n",ans*10000);
  }
  return 0;
}

/*
const int MAX=1020;
double n,m,a[MAX],b[MAX*2];

int main(void){
  while(scanf("%lf%lf",&n,&m)==2){
    FOR(i,0,n) a[i]=i/n;
    FOR(i,0,n+m) b[i]=i/(n+m);
    double ans=0; int j=0;
    FOR(i,1,n){
      while(j<m+n){
        if(b[j]<=a[i] && a[i]<b[j+1]){
          ans += min( abs(a[i]-b[j]), abs(a[i]-b[j+1]) );
#ifdef DEBUG
          printf("n: %.lf, m: %.lf, %d placed in (%d, %d), ans gained %lf\n",
              n, m, i, j, j+1,min( abs(a[i]-b[j]), abs(a[i]-b[j+1]) ));
#endif
          j++; break;
        }else j++;
      }
    }
    printf("%.4lf\n",ans*10000);
  }

  return 0;
}
*/
