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

const int MAX=120;
int n,v,w,a[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&v,&w);
    FOR(i,0,n) scanf("%d",&a[i]);
    sort(a,a+n);
    int s=0,cnt=0;
    FOR(i,0,n){
      int t=s+a[i];
      if(1.0*t/(cnt+1) > w) break;
      s+=a[i], cnt++;
    }
    if(!cnt) printf("0 0.00\n");
    else{
      double ave=1.0*s/cnt; ave=floor(ave+0.5);
      printf("%d %.2lf\n",cnt*v,ave/100);
    }
  }

  return 0;
}
