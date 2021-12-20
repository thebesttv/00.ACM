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

const int MAX=320;
int n;
Point P[MAX],Q[MAX*MAX];

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,n) scanf("%lf%lf",&P[i].x,&P[i].y);
    int tail=--n; FOR(i,0,tail) Q[i]=P[i];

    FOR(i,0,n) FOR(j,i+1,n)
      if(SegProperInter(P[i],P[i+1],P[j],P[j+1]))
        Q[tail++]=LineInter(P[i],P[i+1]-P[i],P[j],P[j+1]-P[j]);

    sort(Q,Q+tail); tail=unique(Q,Q+tail)-Q;
    int V=tail, E=n;
    FOR(i,0,tail) FOR(j,0,n)
      if(OnSeg(Q[i],P[j],P[j+1])) E++;
    printf("Case %d: There are %d pieces.\n",++kase,E-V+2);
  }

  return 0;
}

/*
const int MAX=320;
int n;
Point P[MAX],Q[MAX*MAX];

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    FORR(i,1,n) scanf("%lf%lf",&P[i].x,&P[i].y);
    int tail=n--; FOR(i,1,tail) Q[i]=P[i];

    FORR(i,1,n) FORR(j,i+1,n)
      if(SegProperInter(P[i],P[i+1],P[j],P[j+1]))
        Q[tail++]=LineInter(P[i],P[i+1]-P[i],P[j],P[j+1]-P[j]);

    sort(Q+1,Q+tail); tail=unique(Q+1,Q+tail)-Q;
    int V=tail-1, E=n;
    FOR(i,1,tail) FORR(j,1,n)
      if(OnSeg(Q[i],P[j],P[j+1])) E++;
#ifdef DEBUG
    FOR(i,1,tail) printf("  Q[%d]: (%.2lf,%.2lf)\n",i,Q[i].x,Q[i].y);
    printf("  E: %d, V: %d\n",E,V);
#endif
    printf("Case %d: There are %d pieces.\n",++kase,E-V+2);
  }

  return 0;
}
*/
