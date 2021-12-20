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
const double EPS=1e-6;
inline int dcmp(double x) { return fabs(x)<1e-6 ? 0 : ( x<0 ? -1 : 1 ) ; }
struct Point{
  double x,y;
  Point(): x(0.0), y(0.0) { }
  Point(double x_, double y_): x(x_), y(y_) { }

  bool operator < (const Point &b) const {
    return dcmp(x-b.x) ? dcmp(x-b.x)<0 : dcmp(y-b.y)<0 ;
  }
  bool operator != (const Point &b) const {
    return dcmp(x-b.x) || dcmp(y-b.y);
  }
};
typedef Point Vector;
typedef Vector Vr;
Vr operator + (Vr A, Vr B) { return Vr(A.x+B.x,A.y+B.y); }
Vr operator - (Point A, Point B) { return Vr(A.x-B.x,A.y-B.y); }
Vr operator * (Vr A, double p) { return Vr(A.x*p,A.y*p); }
Vr operator / (Vr A, double p) { return Vr(A.x/p,A.y/p); }
bool operator == (Vr A, Vr B) { return !(A<B) && !(B<A); }
struct Circle{
  Point c; double r;
  Circle() { }
  Circle(Point c, double r): c(c), r(r) { }

  Point point(double ang){
    return Point(c.x + r*cos(ang), c.y + r*sin(ang));
  }
};
typedef Circle Cir;
struct Line{
  Point p; Vector v;
  Line() { }
  Line(Point p, Vr v): p(p), v(v) { }
  Point point(double t) { return p + v*t; }
};

double Dot(Vr A, Vr B) { return A.x*B.x + A.y*B.y; }
double Cross(Vr A, Vr B) { return A.x*B.y - A.y*B.x; }
double Len(Vr A) { return sqrt(A.x*A.x + A.y*A.y); }
double Dis(Point A, Point B){
  double dx=A.x-B.x, dy=A.y-B.y; return sqrt(dx*dx+dy*dy);
}
double Angle(Vr A) { return atan2(A.y,A.x); }
double Angle(Vr A, Vr B) { return acos( Dot(A,B) / Len(A) / Len(B) ) ; }
Vr Rotate(Vr A, double ang){
  return Vr(A.x*cos(ang) - A.y*sin(ang), A.x*sin(ang) + A.y*cos(ang) );
}
Vr Normal(Vr A) {
  return Vr(-A.y,A.x)/Len(A);
}
Point readP(){
  Point P; scanf("%lf%lf",&P.x,&P.y); return P;
}
Circle readC(){
  Circle C; scanf("%lf%lf%lf",&C.c.x,&C.c.y,&C.r); return C;
}

Point LineInter(Point P, Vr v, Point Q, Vr w){
  Vr u=P-Q;
  double t = Cross(w,u) / Cross(v,w);
  return P + v*t;
}
double DisToLine(Point P, Point A, Point B){
  return fabs(Cross(P-A,P-B))/Len(A-B);
}
double DisToSeg(Point P, Point A, Point B){
  Vr v1=B-A, v2=P-A, v3=P-B;
  if(A==B) return Len(v2);
  if(dcmp(Dot(v1,v2))<0) return Len(v2);
  if(dcmp(Dot(v1,v3))>0) return Len(v3);
  return fabs(Cross(v1,v2))/Len(v1);
}
bool SegPropInter(Point A1, Point A2, Point B1, Point B2){
  return dcmp(Cross(A2-A1,B1-A1))*dcmp(Cross(A2-A1,B2-A1))<0
      && dcmp(Cross(B2-B1,A1-B1))*dcmp(Cross(B2-B1,A2-B1))<0;
}
Point LineProj(Point P, Point A, Point B){
  Vr v = B-A; double t = Dot(v,P-A) / Dot(v,v);
  return A+v*t;
}
Point LineProj(Point P, Line L){
  double t = Dot(L.v,P-L.p) / Dot(L.v,L.v);
  return L.point(t);
}
bool OnSeg(Point P, Point A, Point B){
  return dcmp(Cross(A-P,B-P))==0 && dcmp(Dot(A-P,B-P))<0;
}
double PolyArea(Point *P, int n){
  double ans=0; n--;
  FOR(i,1,n) ans += Cross(P[i]-P[0],P[i+1]-P[0]);
  return ans/2;
}
int LineCirInter(Line L, Circle C, VR<Point> &res){
  double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
  double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d - C.r*C.r;
  double delta = f*f - 4*e*g; double t1,t2;

  if(dcmp(delta)<0) return 0;
  if(dcmp(delta)==0){
    t1 = t2 = -f/e/2; res.push_back(L.point(t1));
    return 1;
  }else{
    t1 = (-f+sqrt(delta)) / (2*e); res.push_back(L.point(t1));
    t2 = (-f-sqrt(delta)) / (2*e); res.push_back(L.point(t2));
    return 2;
  }
}
int LineCirInter(Line L, Circle C, double &t1, double &t2, VR<Point> &res){
  double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
  double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d - C.r*C.r;
  double delta = f*f - 4*e*g;

  if(dcmp(delta)<0) return 0;
  if(dcmp(delta)==0){
    t1 = t2 = -f/e/2; res.push_back(L.point(t1));
    return 1;
  }else{
    t1 = (-f+sqrt(delta)) / (2*e); res.push_back(L.point(t1));
    t2 = (-f-sqrt(delta)) / (2*e); res.push_back(L.point(t2));
    return 2;
  }
}
int CirInter(Circle C1, Circle C2, VR<Point> &res){
  double d = Len(C1.c-C2.c);
  //无交点或无穷个交点
  if(!dcmp(d)){
    if(!dcmp(C1.r-C2.r)) return -1;
    else return 0;
  }
  if(dcmp(C1.r+C2.r-d)<0 || dcmp(fabs(C1.r-C2.r)-d)>0) return 0;

  //1或2个交点
  double base = Angle(C2.c-C1.c);
  double ang = acos( (C1.r*C1.r - C2.r*C2.r + d*d) / (2*C1.r*d) );
  Point P1=C1.point(base+ang), P2=C1.point(base-ang);
  res.push_back(P1);
  if(P1==P2) return 1;
  res.push_back(P2);
  return 2;
}
int Tangs(Point P, Circle C, VR<Point> &res){
  double d=Dis(P,C.c);
  if(dcmp(d-C.r)<0) return 0;
  double base = Angle(P-C.c);
  if(dcmp(d-C.r)==0){
    res.push_back(C.point(base)); return 1;
  }
  double ang = acos(C.r/d);
  res.push_back(C.point(base+ang)); res.push_back(C.point(base-ang));
  return 2;
}
int Tangs(Circle A, Circle B, Point *a, Point *b){
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




const char ori[7][100]={
  "",
  "CircumscribedCircle",
  "InscribedCircle",
  "TangentLineThroughPoint",
  "CircleThroughAPointAndTangentToALineWithRadius",
  "CircleTangentToTwoLinesWithRadius",
  "CircleTangentToTwoDisjointCirclesWithRadius"
};
int read(){
  char t1[100]; if(scanf("%s",t1)==EOF) return 0;
  FORR(i,1,6) if(!strcmp(t1,ori[i])) return i;
}
void Print(VR<Point> &v){
  sort(v.begin(),v.end());
  putchar('[');
  FOR(i,0,v.size()){
    if(i) putchar(',');
    printf("(%.6lf,%.6lf)",v[i].x,v[i].y);
  }
  putchar(']'); putchar('\n');
}
void Print(VR<double> &v){  //把弧度转化为角度
  FOR(i,0,v.size()){
    double a = v[i]*180/PI; a-=floor(a/180)*180;
    v[i]=a;
  }
  sort(v.begin(),v.end());

  putchar('[');
  FOR(i,0,v.size()){
    if(i) putchar(','); printf("%.6lf",v[i]);
  }
  putchar(']'); putchar('\n');
}
void s1(){  //CircumscribedCircle 外接圆（中垂线交点）
  Point A,B,C; A=readP(), B=readP(), C=readP();
  Vr v1=Normal(B-A), v2=Normal(C-A);
  Point P = LineInter((A+B)/2,v1,(A+C)/2,v2);
  double r = Dis(A,P);
  printf("(%.6lf,%.6lf,%.6lf)\n",P.x,P.y,r);
}
//[1]
Vr Between(Vr A, Vr B){ //返回角平分向量
  double a1=Angle(A),a2=Angle(B);
  if(a1>a2) swap(A,B), swap(a1,a2);
  double ang=a2-a1; return Rotate(A,ang/2);
}
void s2(){  //InscribedCircle 内切圆（角平分线交点）
  Point A,B,C; A=readP(), B=readP(), C=readP();
  Vr v1=Between(B-A,C-A), v2=Between(A-B,C-B);
  Point P = LineInter(A,v1,B,v2);
  double r = DisToLine(P,A,B);
  printf("(%.6lf,%.6lf,%.6lf)\n",P.x,P.y,r);
}
/*
//[2]
void s2(){
  Point A,B,C; A=readP(), B=readP(), C=readP();
  double a=Dis(B,C), b=Dis(A,C), c=Dis(A,B);
  Point P = (A*a+B*b+C*c)/(a+b+c);
  double r = DisToLine(P,A,B);
  printf("(%.6lf,%.6lf,%.6lf)\n",P.x,P.y,r);
}
*/
void s3(){  //TangentLineThroughPoint 点对圆的切线
  Circle C=readC(); Point P=readP(); VR<double> v;

  double d = Dis(C.c,P), base = Angle(C.c-P);
  if(dcmp(d-C.r)==0) v.push_back(base+PI/2);
  else if(dcmp(d-C.r)>0){
    double ang = asin(C.r/d);
    v.push_back(base+ang), v.push_back(base-ang);
  }
  Print(v);
}
void s4(){  //CircleThroughAPointAndTangentToALineWithRadius
  Point P,A,B; P=readP(), A=readP(), B=readP();
  double r; scanf("%lf",&r); Circle C(P,r);
  Vr v1=B-A, v2=Normal(B-A);
  Line L1(A+v2*r, v1), L2(A-v2*r, v1);  //平移直线
  VR<Point> res; LineCirInter(L1,C,res), LineCirInter(L2,C,res);
  Print(res);
}
void s5(){
  Point A1,A2,B1,B2; A1=readP(), A2=readP(), B1=readP(), B2=readP();
  double r; scanf("%lf",&r);
  Line L[4]; Vr v1=A2-A1, v2=Normal(A2-A1);
  L[0] = Line(A1+v2*r,v1), L[1]=Line(A1-v2*r,v1);
  v1=B2-B1, v2=Normal(B2-B1);
  L[2] = Line(B1+v2*r,v1), L[3]=Line(B1-v2*r,v1);
  VR<Point> res;
  FOR(i,0,2) FOR(j,2,4) res.push_back(LineInter(L[i].p,L[i].v,L[j].p,L[j].v));
  Print(res);
}
void s6(){
  Circle C1,C2; C1=readC(), C2=readC();
  double r; scanf("%lf",&r); C1.r+=r, C2.r+=r;
  VR<Point> res; CirInter(C1,C2,res);
  Print(res);
}

int main(void){
  int opt;
  while(opt=read()){
    switch(opt){
      case 1: s1(); break;
      case 2: s2(); break;
      case 3: s3(); break;
      case 4: s4(); break;
      case 5: s5(); break;
      case 6: s6(); break;
    }
  }

  return 0;
}
