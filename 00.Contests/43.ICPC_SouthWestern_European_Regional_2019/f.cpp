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

const int MAX = 120;
int n;
struct Point{
  int x, y;
  double a;
  bool operator < (const Point &b) const {
    return a < b.a;
  }
  Point operator - (const Point &b) const {
    return {x - b.x, y - b.y};
  }
}p[MAX];

double cross(Point &a, Point &b){
  return 1.0 * a.x * b.y - 1.0 * a.y * b.x;
}

int main(void){
  int T; scanf("%d",&T);
  double ans = 0;
  while(T--){
    scanf("%d",&n);
    double ax = 0, ay = 0;
    FOR(i,0,n){
      scanf("%d%d",&p[i].x,&p[i].y);
      ax += p[i].x, ay += p[i].y;
    }
    ax /= n, ay /= n;
    FOR(i,0,n){
      p[i].a = atan2(p[i].y - ay, p[i].x - ax);
    }
    sort(p,p+n);

    FOR(i,1,n-1){
      Point v1 = p[i]-p[0], v2 = p[i+1]-p[0];
      ans += fabs(cross(v1,v2)/2.0);
    }
  }
  printf("%d\n",int(ans));

  return 0;
}
