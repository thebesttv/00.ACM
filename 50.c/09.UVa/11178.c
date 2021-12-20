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

struct Point{
  double x,y;
  Point(): x(0.0), y(0.0) { }
  Point(double x_, double y_): x(x_), y(y_) { }
};
typedef Point Vr;
Vr operator + (Vr A, Vr B) { return Vr(A.x+B.x,A.y+B.y); }
Vr operator - (Point A, Point B) { return Vr(A.x-B.x,A.y-B.y); }
Vr operator * (Vr A, double p) { return Vr(A.x*p,A.y*p); }
Vr operator / (Vr A, double p) { return Vr(A.x/p,A.y/p); }

Point readP(){
  Point A; scanf("%lf%lf",&A.x,&A.y); return A;
}
double Dot(Vr A, Vr B) { return A.x*B.x + A.y*B.y; }
double Len(Vr A) { return sqrt(A.x*A.x + A.y*A.y); }
double Angle(Vr A, Vr B) { return acos( Dot(A,B) / Len(A) / Len(B) ) ; }
double Cross(Vr A, Vr B) { return A.x*B.y - A.y*B.x; }
Point LineInter(Point P, Vr v, Point Q, Vr w){
  Vr u=P-Q;
  double t = Cross(w,u) / Cross(v,w);
  return P + v*t;
}
Vr Rotate(Vr A, double ang){
  return Vr(A.x*cos(ang) - A.y*sin(ang), A.x*sin(ang) + A.y*cos(ang) );
}
Point get(Point A, Point B, Point C){
  Vr v,w; double ang1,ang2;
  ang1 = Angle(C-B,A-B)/3;
  v = Rotate(C-B,ang1);
  ang2 = Angle(B-C,A-C)/3;
  w = Rotate(B-C,-ang2);
  return LineInter(B,v,C,w);
}

int main(void){
  Point A,B,C,D,E,F;
  int T; scanf("%d",&T);
  while(T--){
    A=readP(); B=readP(); C=readP();
    D=get(A,B,C); E=get(B,C,A); F=get(C,A,B);
    printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
  }

  return 0;
}
