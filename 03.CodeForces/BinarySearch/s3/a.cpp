// Tag: notag
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

const int MAX = 1e5 + 20;
int n; LL x[MAX],v[MAX];

double f(double p){
  double tMax = 0;
  FORR(i,1,n) tMax = max(tMax, fabs(x[i]-p)/v[i]);
  return tMax;
}

int main(void){
  n = read();
  FORR(i,1,n) x[i] = nread(), v[i] = read();

  double l = -1e9, r = 1e9;
  while(r - l > 1e-6){
    double m1 = l + (r-l)/3;
    double m2 = r - (r-l)/3;
    double f1 = f(m1), f2 = f(m2);
    if(f1 < f2) r = m2;
    else l = m1;
  }
  printf("%.10lf\n",f(l));

  return 0;
}

