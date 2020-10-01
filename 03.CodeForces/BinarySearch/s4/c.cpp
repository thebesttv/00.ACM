// Tag: 二分 i
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
int n,k,a[MAX],b[MAX]; double v[MAX];

bool ok(double x){
  FORR(i,1,n) v[i] = a[i] - x * b[i];
  sort(v+1,v+1+n,greater<double>());
  double sum = 0;
  FORR(i,1,k) sum += v[i];
#ifdef DEBUG
  printf("ok(%.2lf): %d\n",x,sum >= 0);
#endif
  return sum >= 0;
}

int main(void){
  n = read(), k = read();
  FORR(i,1,n) a[i] = read(), b[i] = read();
  double l = 0, r = 1e6;
  while(r - l > 1e-6){
    double m = (l+r)/2;
    if(ok(m)) l = m;
    else r = m;
  }
  printf("%.10lf\n",l);

  return 0;
}

