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
#include<complex>
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

int dcmp(double x){
  if(fabs(x)<0.05) return 0;
  return x < 0 ? -1 : 1;
}
void print(complex<double> a){
  char op = '+';
  if(dcmp(a.imag())<0) op = '-';
  printf("(%.1lf%c%.1lfi)",a.real(),op,fabs(a.imag()));
}
void cal(complex<double> a, complex<double> b, char op){
  complex<double> r;
  switch(op){
    case '+': r = a + b; break;
    case '-': r = a - b; break;
    case '*': r = a * b; break;
    case '/': r = a / b; break;
  }
  print(a); printf(" %c ",op); print(b);
  printf(" = ");
  if(!dcmp(r.real()) && !dcmp(r.imag())){
    printf("0.0");
  }else if(!dcmp(r.real())){
    printf("%.1lfi",r.imag());
  }else if(!dcmp(r.imag())){
    printf("%.1lf",r.real());
  }else{
    char op = '+';
    if(dcmp(r.imag())<0) op = '-';
    printf("%.1lf%c%.1lfi",r.real(),op,fabs(r.imag()));
  }
  putchar('\n');
}

int main(void){
  double x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  complex<double> a{x1,y1}, b{x2,y2};

  cal(a, b, '+');
  cal(a, b, '-');
  cal(a, b, '*');
  cal(a, b, '/');

  return 0;
}
