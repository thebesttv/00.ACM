const double PI=3.1415926535;
const double EPS=1e-6;
inline int dcmp(double x);
struct Point{ };
typedef Point Vector;
typedef Vector Vr;
Vr operator + (Vr A, Vr B);
Vr operator - (Point A, Point B);
Vr operator * (Vr A, double p);
Vr operator / (Vr A, double p);
bool operator == (Vr A, Vr B);
struct Circle{ };
typedef Circle Cir;
struct Line{ };

double Dot(Vr A, Vr B);
double Cross(Vr A, Vr B);
double Len(Vr A);
double Dis(Point A, Point B);
double Angle(Vr A);
double Angle(Vr A, Vr B);
Vr Rotate(Vr A, double ang);
Vr Normal(Vr A);
Vr Between(Vr A, Vr B); //返回角平分向量（单位向量）
Point readP();
Circle readC();

Point LineInter(Point P, Vr v, Point Q, Vr w);
double DisToLine(Point P, Point A, Point B);
double DisToSeg(Point P, Point A, Point B);
bool SegPropInter(Point A1, Point A2, Point B1, Point B2);
Point LineProj(Point P, Point A, Point B);
Point LineProj(Point P, Line L);
bool OnSeg(Point P, Point A, Point B);
double PolyArea(Point *P, int n);
int LineCirInter(Line L, Circle C, double &t1, double &t2, VR<Point> &res);
int CirInter(Circle C1, Circle C2, VR<Point> &res);
int Tangs(Point P, Circle C, VR<Point> &res);
int Tangs(Circle A, Circle B, Point *a, Point *b);

int PointInPoly(Point P, VR<Point> &poly); //1:多边形内，-1:多边形上，0:多边形外
void ConHull(VR<Point> &poly, VR<Point> &res);  //求凸包
