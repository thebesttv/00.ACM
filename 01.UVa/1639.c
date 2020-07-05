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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 4e5 + 20;
const double EPS = 1e-5;
int n;
long double p;

inline int dcmp(long double x){
  if(fabs(x)<EPS) return 0;
  return x<0 ? -1 : 1;
}

long double v1(int i, long double C){
  return C + (n+1) * log(p) + (i-n) * log(1-p);
}

long double v2(int i, long double C){
  return C + (n+1) * log(1-p) + (i-n) * log(p);
}

int main(void){
  int kase = 0;
  while(scanf("%d%Lf",&n,&p)==2){
    long double ans = 0;
    if(!dcmp(p) || !dcmp(1-p)){
      ans = n;
    }else{
      long double C = 0;
      FORR(i,n,2*n){
        ans += (exp(v1(i,C)) + exp(v2(i,C))) * (n*2-i);
        C += log(i+1) - log(i+1-n);
      }
    }
    printf("Case %d: %.6Lf\n",++kase,ans);
  }

  return 0;
}
