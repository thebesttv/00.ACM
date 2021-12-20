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
int n=200;
double a[MAX];

double f1(double x){
  double ans=a[0];
  FORR(i,1,n){
    ans += a[i] * pow(x,i);
  }
  return ans;
}

/*
double f2(double x){
  double ans=0;
  ROR(i,n,1){
    ans+=a[i]; ans*=x;
  }
  ans+=a[0];
  return ans;
}
*/
double f2(double x){
  double ans=a[n];
  ROR(i,n-1,0) ans = a[i] + ans*x;
  return ans;
}

void test_time(double (*f)(double), double x){
  clock_t ts=clock();
  double ans = f(x);
  ts=clock()-ts;
  printf("function returns %lf\n",ans);
  printf("time: %lf\n",(double)ts/CLOCKS_PER_SEC);
}

int main(void){
  a[0]=1; FORR(i,1,n) a[i] = 1.0/i;

  printf("f1:\n");
  test_time(f1,1.1);

  printf("f2:\n");
  test_time(f2,1.1);

  return 0;
}
