const double PI=3.1415926535;
const double EPS=1e-6;
inline int dcmp(double x) { return fabs(x)<EPS ? 0 : ( x<0 ? -1 : 1 ) ; }
struct Point{
  double x,y;
  Point(): x(0.0), y(0.0) { }
  Point(double x_, double y_): x(x_), y(y_) { }

  bool operator < (const Point &b) const {
    return dcmp(x-b.x) ? dcmp(x-b.x)<0 : dcmp(y-b.y)<0 ;
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
/*
Vr Between(Vr A, Vr B){ //返回角平分向量
  double a1=Angle(A),a2=Angle(B);
  if(a1>a2) swap(A,B), swap(a1,a2);
  double ang=a2-a1; return Rotate(A,ang/2);
}
*/
Vr Between(Vr A, Vr B){ //返回角平分向量（单位向量）
  double ang=(Angle(A)+Angle(B))/2;
  return Vr(cos(ang),sin(ang));
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

int PointInPoly(Point P, VR<Point> &poly); //1:多边形内，-1:多边形上，0:多边形外
  int wn=0,n=poly.size();
  FOR(i,0,n){
    if(OnSeg(P,poly[i],poly[(i+1)%n]) return -1;
    int k = dcmp(Cross(poly[(i+1)%n]-poly[i],P-poly[i]));
    int d1 = dcmp(poly[i].y-P.y);
    int d2 = dcmp(poly[(i+1)%n].y-P.y);
    if(k>0 && d1<=0 && d2>0) wn++;
    if(k<0 && d2<=0 && d1>0) wn--;
  }
  return wn!=0;
}
void ConHull(VR<Point> &poly, VR<Point> &res){  //求凸包
  sort(poly.begin(),poly.end());
  int n=poly.size(),m;
  FOR(i,0,n){
    while((m=res.size())>1 && Cross(res[m-1]-res[m-2], poly[i]-res[m-2])<=0) v.pop_back();
    v.push_back(poly[i]);
  }
  int k=res.size();
  ROR(i,n-2,0){
    while((m=res.size())>k && Cross(res[m-1]-res[m-2], poly[i]-res[m-2])<=0) v.pop_back();
    v.push_back(poly[i]);
  }
  if(n>1) v.pop_back(); //<b> </b>
}
