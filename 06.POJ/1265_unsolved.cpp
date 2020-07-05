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

const int MAX = 120;
int n, xMax, yMax, xMin, yMin;

struct Point{
  int x, y;
  Point() { }
  Point(int x, int y): x(x), y (y) { }
}p[MAX];
typedef Point Vector;

Vector operator + (Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }

int Dot(Vector a, Vector b){
  return a.x * b.x + a.y * b.y;
}
int Cross(Vector a, Vector b){
  return a.x * b.y - a.y * b.x;
}

struct Line{
  Point s, t; Vector v;
  Line() {}
  Line(Point s, Point t): s(s), t(t), v(t-s) { }
  bool onSeg(Point p){
    if(Cross(p-s, v)) return 0;
    return min(s.x, t.x) <= p.x && p.x <= max(s.x, t.x)
        && min(s.y, t.y) <= p.y && p.y <= max(s.y, t.y);
  }
  bool isLeft(Point p){
    return Cross(v, p-s) > 0;
  }
}line[MAX];

int isPointInPoly(Point x){
  int wn = 0;
  FOR(i,0,n){
    if(line[i].onSeg(x)) return -1;
    int k = Cross(p[i+1] - p[i], x - p[i]);
    int d1 = p[i].y - x.y;
    int d2 = p[i+1].y - x.y;
    if(k>0 && d1<=0 && d2>0) ++wn;
    if(k<0 && d2<=0 && d1>0) --wn;
  }
  if(wn) return 1;
  return 0;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    int x = 0, y = 0, dx, dy;
    xMax = xMin = yMax = yMin = 0;

    scanf("%d",&n);
    double s = 0;
    p[0] = {0,0};
    FORR(i,1,n){
      scanf("%d%d",&dx,&dy);
      x += dx, y += dy;
      p[i] = {x,y};
      line[i-1] = Line(p[i-1], p[i]);

      if(x>xMax) xMax = x;
      else if(x<xMin) xMin = x;

      if(y>yMax) yMax = y;
      else if(y<yMin) yMin = y;

      if(i>=2 && i<n){
        s += Cross(p[i-1],p[i]);
      }
    }
    s = fabs(s/2.0);
    int I = 0, E = 0;
    FORR(x, xMin, xMax) FORR(y, yMin,yMax){
      switch(isPointInPoly(Point(x,y))){
        case -1: ++E; break;
        case 1:  ++I; break;
      }
    }
    printf("Scenario #%d:\n",kase);
    printf("%d %d %.1lf\n\n",I,E,s);
  }

  return 0;
}
