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

const double EPS = 1e-6;
const int MAX = 100;
int n;
struct Point{
  double x,y;
}p[MAX];

inline int dcmp(double x){
  return fabs(x)<EPS ? 0 : ( x<0 ? -1 : 1 );
}

bool inBetween(int a, int b, int m){
  return dcmp(p[a].x+p[b].x-2*p[m].x)==0
      && dcmp(p[a].y+p[b].y-2*p[m].y)==0;
}

bool isTan(Point v1, Point v2){
  return dcmp(v1.x*v2.x + v1.y*v2.y)==0;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    int ans = 0;
    FOR(i,0,n) scanf("%lf%lf",&p[i].x,&p[i].y);
    FOR(a,0,n) FOR(b,a+1,n)
      FOR(m,0,n) if(inBetween(a,b,m)){
        Point v{p[a].x-p[b].x, p[a].y-p[b].y};
        double l1 = v.x*v.x + v.y*v.y;
        FOR(c,0,n){
          Point v2{p[m].x-p[c].x,p[m].y-p[c].y};
          if(!isTan(v,v2)) continue;
          double l2 = v2.x*v2.x+v2.y*v2.y;
          if(dcmp(l1-l2)) continue;
          ++ans;
        }
      }
    printf("Set #%d: %d\n\n",kase,ans);
  }

  return 0;
}
