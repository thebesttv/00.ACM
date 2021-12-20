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
typedef long long LL;
typedef long long unsigned LLU;

const double PI=3.1415926535;
inline int dcmp(double x) { return fabs(x)<1e-6 ? 0 : ( x<0 ? -1 : 1 ) ; }
struct Point{
  double x,y;
  Point(): x(0.0), y(0.0) { }
  Point(double x_, double y_): x(x_), y(y_) { }

  bool operator < (const Point &b) const {
    return dcmp(x-b.x) ? dcmp(x-b.x)<0 : dcmp(y-b.y)<0 ;
  }
};
typedef Point Vr;
Vr operator + (Vr A, Vr B) { return Vr(A.x+B.x,A.y+B.y); }
Vr operator - (Point A, Point B) { return Vr(A.x-B.x,A.y-B.y); }
Vr operator * (Vr A, double p) { return Vr(A.x*p,A.y*p); }
Vr operator / (Vr A, double p) { return Vr(A.x/p,A.y/p); }
bool operator == (Vr A, Vr B) { return !(A<B) && !(B<A); }

double Dot(Vr A, Vr B) { return A.x*B.x + A.y*B.y; }
double Len(Vr A) { return sqrt(A.x*A.x + A.y*A.y); }
double Angle(Vr A, Vr B) { return acos( Dot(A,B) / Len(A) / Len(B) ) ; }
double Cross(Vr A, Vr B) { return A.x*B.y - A.y*B.x; }
Vr Rotate(Vr A, double ang){
  return Vr(A.x*cos(ang) - A.y*sin(ang), A.x*sin(ang) + A.y*cos(ang) );
}
double Angle(Vr A) { return atan2(A.y,A.x); }

struct Tang{
  Point s,t; double l;
  bool operator < (const Tang &b) const {
    return dcmp(s.x-b.s.x) ? dcmp(s.x-b.s.x)<0 : dcmp(s.y-b.s.y)<0 ;
  }
};
struct Circle{
  Point c; double r;
  Circle() { }
  Circle(Point c, double r): c(c), r(r) { }

  Point point(double ang){
    return Point(c.x + r*cos(ang), c.y + r*sin(ang));
  }
}A,B;

bool read(){
  scanf("%lf%lf%lf",&A.c.x,&A.c.y,&A.r);
  scanf("%lf%lf%lf",&B.c.x,&B.c.y,&B.r);
  return dcmp(A.c.x) || dcmp(A.c.y) || dcmp(A.r)
      || dcmp(B.c.x) || dcmp(B.c.y) || dcmp(B.r) ;
}
int Tangents(Circle A, Circle B, Point *a, Point *b){
  int tail=0; if(dcmp(A.r-B.r)<0) swap(A,B), swap(a,b);
  double d=Len(A.c-B.c), rsum=A.r+B.r, rsub=A.r-B.r;
  if(dcmp(d)==0 && dcmp(A.r-B.r)==0) return -1; //重合
  if(dcmp(d-rsub)<0) return 0;  //内含
  double base = Angle(B.c-A.c);
  if(dcmp(d-rsub)==0){  //内切
    a[tail]=A.point(base), b[tail]=B.point(base); tail++;
    return 1;
  }
  double ang = acos(rsub/d);
  a[tail]=A.point(base+ang), b[tail]=B.point(base+ang); tail++;
  a[tail]=A.point(base-ang), b[tail]=B.point(base-ang); tail++;
  if(dcmp(d-rsum)==0){  //外切
    a[tail]=A.point(base), b[tail]=B.point(base+PI); tail++;
  }else if(dcmp(d-rsum)>0){
    double ang2 = acos(rsum/d);
    a[tail]=A.point(base+ang2), b[tail]=B.point(base+ang2+PI); tail++;
    a[tail]=A.point(base-ang2), b[tail]=B.point(base-ang2+PI); tail++;
  }
  return tail;
}

int main(void){
  while(read()){
    Point a[10],b[10]; Tang tang[10];
    int res=Tangents(A,B,a,b);
    if(res>0){
      FOR(i,0,res){
        tang[i].s=a[i], tang[i].t=b[i];
        tang[i].l=Len(a[i]-b[i]);
      }
      sort(tang,tang+res);
    }
    printf("%d\n",res);
    FOR(i,0,res){
      Tang &t=tang[i];
      printf("%.5lf %.5lf %.5lf %.5lf %.5lf\n", t.s.x, t.s.y, t.t.x, t.t.y, t.l);
    }
  }

  return 0;
}
