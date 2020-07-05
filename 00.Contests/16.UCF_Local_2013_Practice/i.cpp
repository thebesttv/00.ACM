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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const double PI = 3.14159;
int n,a,b;

double rnd(double x){
  /*
  FORR(i,0,n) x *= 10;
  int t = x;
  x = ((t+5)/10);
  FOR(i,0,n) x/=10;
  return x;
  */
  //return int(x*1000+5)/10/100.;
  //return round(x*100)/100;
  x = (int)((x + 0.00501) * 100) / 100.0;
  return x;
}

int main(void){
  scanf("%d",&n);
  FORR(kase,1,n){
    scanf("%d%d",&a,&b);
    int r1 = b, r2 = a-b;
    double tot = PI * a * a;
    double su = PI * b * b;
    double sl = PI * (a-b) * (a-b);
    double si = (tot-su-sl)/2;
    double yin = sl + si;
    double yang = su + si;
    // double yin = PI * (r2*r2 + (a*a-r1*r1-r2*r2)/2.0);
    // double yang = PI*a*a - yin;
    yin = rnd(yin); yang = rnd(yang);
    printf("Taijitu #%d: yin %.2lf, yang %.2lf\n\n",kase,yin,yang);
  }

  return 0;
}
