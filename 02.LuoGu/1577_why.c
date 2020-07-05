/*
解题报告：
  将所有数据乘以100，化为整数处理，确保精度

问题：为什么double不行？
*/
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
int n,k,a[MAX];

bool ok(int l){
  int sum=0;
  FOR(i,0,n) sum += a[i]/l;
  return sum>=k;
}

int main(void){
  scanf("%d%d",&n,&k);
  int l=0, r=0; double t;
  FOR(i,0,n){
    scanf("%lf",&t);
    a[i]=int(t*100);
    r=max(r,a[i]);
  }

  while(l<r){
    int m=((l+r)>>1)+1;
    if(ok(m)) l=m;
    else r=m-1;
  }
  printf("%d.%02d\n",l/100,l%100);

  return 0;
}

/*
const int MAX=10020;
const double EPS=1e-3;
int n,k;
double a[MAX];

int get(double x){
  int sum=0;
  FOR(i,0,n) sum += int(a[i]/x);
  return sum;
}

int main(void){
  scanf("%d%d",&n,&k);
  double l=0, r=0;
  FOR(i,0,n){
    scanf("%lf",&a[i]);
    r=max(r,a[i]);
  }

  while(r-l>EPS){
    long double m = (l+r)/2;
    #ifdef DEBUG
    printf("l: %lf, r: %lf, m: %lf\n",l,r,m);
    #endif
    if(get(m)>=k) l=m;
    else r=m;
  }
  int t=100*l;
  printf("%d.%02d\n",t/100,t%100);

  return 0;
}
*/
