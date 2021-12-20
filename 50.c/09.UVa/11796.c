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
Point LineInter(Point P, Vr v, Point Q, Vr w){
  Vr u=P-Q;
  double t = Cross(w,u) / Cross(v,w);
  return P + v*t;
}
bool SegProperInter(Point A1, Point A2, Point B1, Point B2){
  return dcmp(Cross(A2-A1,B1-A1))*dcmp(Cross(A2-A1,B2-A1))<0
    && dcmp(Cross(B2-B1,A1-B1))*dcmp(Cross(B2-B1,A2-B1))<0;
}
bool OnSeg(Point P, Point A, Point B){
  return dcmp(Cross(A-P,B-P))==0 && dcmp(Dot(A-P,B-P))<0;
}
Vr Rotate(Vr A, double ang){
  return Vr(A.x*cos(ang) - A.y*sin(ang), A.x*sin(ang) + A.y*cos(ang) );
}
double DisToSeg(Point P, Point A, Point B){
  Vr v1=B-A, v2=P-A, v3=P-B;
  if(A==B) return Len(v2);
  if(dcmp(Dot(v1,v2))<0) return Len(v2);
  if(dcmp(Dot(v1,v3))>0) return Len(v3);
  return fabs(Cross(v1,v2))/Len(v1);
}

const int MAX=80;
int A,B;
double ansMin,ansMax;
Point P[MAX],Q[MAX];

void update(Point P, Point A, Point B){
  ansMin=min(ansMin, DisToSeg(P,A,B));
  ansMax=max(ansMax, max(Len(P-A),Len(P-B)));
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    ansMin=1e9, ansMax=0.0;
    scanf("%d%d",&A,&B);
    FORR(i,1,A) scanf("%lf%lf",&P[i].x,&P[i].y);
    FORR(i,1,B) scanf("%lf%lf",&Q[i].x,&Q[i].y);

    double Lena=0,Lenb=0;
    FOR(i,1,A) Lena+=Len(P[i+1]-P[i]);
    FOR(i,1,B) Lenb+=Len(Q[i+1]-Q[i]);

    Point Pa=P[1],Pb=Q[1];
    int Na=min(2,A),Nb=min(2,B);
    double La,Lb,Ta,Tb,T;
    while(Na<=A && Nb<=B){
      La=Len(P[Na]-Pa), Lb=Len(Q[Nb]-Pb);
      Ta=La/Lena, Tb=Lb/Lenb; T=min(Ta,Tb);

      Vr Va = (P[Na]-Pa)/La*Lena*T;
      Vr Vb = (Q[Nb]-Pb)/Lb*Lenb*T;
      update(Pa,Pb,Pb+(Vb-Va));

      Pa=Pa+Va, Pb=Pb+Vb;
      if(Pa==P[Na]) Na++;
      if(Pb==Q[Nb]) Nb++;
    }
#ifdef DEBUG
    printf("  min: %lf, max: %lf\n",ansMin,ansMax);
#endif
    printf("Case %d: %.0lf\n",kase,ansMax-ansMin);
  }

  return 0;
}
