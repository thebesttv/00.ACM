// Tag: i
// 判断左右边最北点：与顶端连通的所有与左右相交的圆的最南点
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

const int MAX = 1020;
int n,p[MAX]; double x[MAX],y[MAX],r[MAX];

int fa(int x){
  return p[x] < 0 ? x : p[x] = fa(p[x]);
}
void merge(int x, int y){
  x = fa(x), y = fa(y);
  if(x == y) return;
  p[x] = y;
}

bool itc(int i, int j){
  double d2 = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
  return d2 < (r[i]+r[j]) * (r[i]+r[j]);
}

int main(void){
  while(scanf("%d",&n)==1){
    MST(p,-1);  // p[0]: up, p[n+1]: down
    FORR(i,1,n){
      scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
      if(y[i] + r[i] > 1000) merge(0, i);
      if(y[i] - r[i] < 0) merge(i, n+1);
      FOR(j,1,i) if(itc(i,j)) merge(i,j);
    }
    if(fa(0) == fa(n+1)) { printf("IMPOSSIBLE\n"); continue; }

    double al = 1000, ar = 1000;
    FORR(i,1,n) if(fa(0) == fa(i)){
      if(x[i] - r[i] < 0){ // left
        double d = y[i] - sqrt(r[i]*r[i] - x[i]*x[i]);
        al = min(al, d);
      }
      if(x[i] + r[i] > 1000){ // right
        double d = y[i] - sqrt(r[i]*r[i] - (1000-x[i])*(1000-x[i]));
        ar = min(ar, d);
      }
    }
    printf("%.2lf %.2lf %.2lf %.2lf\n",0.,al,1000.,ar);
  }

  return 0;
}
