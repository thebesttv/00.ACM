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

const double EPS = 1e-9;
const double PI = 3.141592653589793;
int n; double rad, theta;

double width(double a){
  double t, x, y, xMax = 0, yMax = 0;
  FOR(i,0,n<<1){
    t = a + i * theta;
    x = rad * cos(t);
    y = rad * sin(t);
    xMax = max(xMax, x);
    yMax = max(yMax, y);
  }
  return max(xMax, yMax)*2;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); theta = PI / n;
    rad = 0.5 / sin(theta/2);
#ifdef DEBUG
    printf("  rad: %.10lf\n",rad);
#endif
    double l = 0, r = theta;
    while(r - l > EPS){
      double x1 = l + (r-l)/3, x2 = r - (r-l)/3;
      double y1 = width(x1), y2 = width(x2);
      if(y1 <= y2) r = x2;
      else l = x1;
    }
    printf("%.10lf\n",width(l));
  }

  return 0;
}
