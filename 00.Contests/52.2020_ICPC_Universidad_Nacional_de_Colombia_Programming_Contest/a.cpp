// Tag: 三分
// 特判重点
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
typedef long double LD;
typedef pair<int,int> pii;

struct Point{
  LD x,y;
  Point() { }
  Point(LD x, LD y) : x(x), y(y) { }
  Point operator + (Point b) {
    return Point(x + b.x, y + b.y);
  }
}a,b,c,d;

Point operator * (LD k, Point p){
  return Point(p.x*k, p.y*k);
}

LL ax,ay,bx,by,cx,cy,dx,dy;
Point v1,v2;

LD dis(LL ax, LL ay, LL bx, LL by){
  return sqrt((ax-bx)*(ax-bx) + (ay-by) * (ay-by));
}
LD dis(Point a, Point b){
  return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}

LD cal(LD r){
  LD l = 0, dist = 1e20;
  LD EPS = 1e-9;
  while(fabs(l-r) > EPS){
    LD m1 = l + (r-l)/3,
           m2 = r - (r-l)/3;
    Point p1m1 = a + m1 * v1;
    Point p2m1 = c + m1 * v2;
    Point p1m2 = a + m2 * v1;
    Point p2m2 = c + m2 * v2;
    LD d1 = dis(p1m1, p2m1), d2 = dis(p1m2, p2m2);
    if(d1 < d2) r = m2, dist = d1;
    else l = m1, dist = d2;
  }
  return dist;
}

int main(void){
  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
  a = {ax,ay}, b = {bx,by}, c = {cx,cy}, d = {dx,dy};

  LD d1 = dis(ax,ay,bx,by), d2 = dis(cx,cy,dx,dy), dist = min(d1, d2);
  double EPS = 1e-6;
  if(d1 < EPS && d2 < EPS){
    printf("%.10Lf\n",dis(a,c));
    return 0;
  }

  v1 = Point((bx-ax)/d1, (by-ay)/d1);
  v2 = Point((dx-cx)/d2, (dy-cy)/d2);

  LD ansMin = 1e20;
  if(d1 > d2){
    swap(a,c), swap(b,d);
    swap(d1,d2); swap(v1, v2);
  }

  // d1 <= d2
  Point t = c + d1 * v2;
  ansMin = min(dis(t, b), dis(d, b));

  ansMin = min(ansMin, cal(dist));

  a = b; v1 = Point(0, 0);
  c = c + d1 * v2;

  ansMin = min(ansMin, cal(d2 - d1));

  printf("%.10Lf\n",ansMin);

  return 0;
}
