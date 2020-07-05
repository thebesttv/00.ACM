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
  Point(double x=0, double y=0): x(x), y(y) { }
};
typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }

bool operator < (const Point &a, const Point &b) {
  return a.x<b.x || (a.x==b.x && a.y < b.y);
}

const double EPS=1e-10;
int dcmp(double x){
  if(fabs(x)<EPS) return 0;
  else return x<0 ? -1 : 1;
}
bool operator == (const Point &a, const Point &b){
  return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);
}

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(A.x*A.x + A.y*A.y); }
double Angle(Vector A, Vector B) { return acos( Dot(A,B) / Length(A) / Length(B) ); }
double Cross(Vector A, Vector B) { return A.x*B.y - B.x*A.y; }
double Area2(Point A, Point B, Point C) { return Cross(B-A, C-A); }

Vector Rotate(Vector A, double rad) {
  return Vector( A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad) );
}
Vector Normal(Vector A) {
  double l = Length(A);
  return Vector( -A.y/l, A.x/l );
}

int main(void){

  return 0;
}
