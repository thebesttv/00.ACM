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
typedef pair<int,int> pii;

//#define DEBUG

const int MAX = 2020;
int n,m,r,r2; double G[MAX][MAX];
struct Point{
  int v[102]; double dis; int dis2; // distance from blackhole
  int &operator [] (int x) { return v[x]; }
  void read(){
    FOR(i,0,n) scanf("%d",&v[i]);
  }
}p[MAX],b;

double dis(Point &p1, Point &p2){
  int sum = 0;
  FOR(i,0,n) sum += (p1[i]-p2[i]) * (p1[i]-p2[i]);
  return sqrt(sum);
}

int dis2(Point &p1, Point &p2){
  int sum = 0;
  FOR(i,0,n) sum += (p1[i]-p2[i]) * (p1[i]-p2[i]);
  return sum;
}

bool ok(double l1, double l2, double h, double l3){
  double th1 = acos(h/l1), th2 = acos(h/l2);
  double x = sqrt(l1 * l1 + l2 * l2 - 2 * l1 * l2 * cos(th1+th2));
  #ifdef DEBUG
    printf("in ok, th1: %.2lf, th2: %.2lf, x: %.2lf\n", th1, th2, x);
  #endif
  return fabs(l3 - x) > 1e-6;
}

double cal(Point &p1, Point &p2){
  double l1 = p1.dis, l2 = p2.dis, l3 = dis(p1, p2);
  double th = acos( (l1*l1 + l2*l2 - l3*l3) / (2 * l1 * l2));
  double area2 = l1 * l2 * sin(th);
  double h = area2 / l3;
  #ifdef DEBUG
  printf("l1: %.2lf, l2: %.2lf, l3: %.2lf, th: %.2lf, h: %.2lf\n",
    l1,l2,l3,th,h);
  #endif
  if(h >= r || (h < r && ok(l1,l2,h,l3))){
    #ifdef DEBUG
    printf("  away\n");
    #endif
    return l3;
  }
  double ans = sqrt(p1.dis2 - r2) + sqrt(p2.dis2 - r2);
  double th1 = acos(r / l1), th2 = acos(r / l2);
  #ifdef DEBUG
  printf("  through\n");
  printf("    d1: %.2lf, d2: %.2lf, mid: %.2lf\n",
     sqrt(p1.dis2 - r2), sqrt(p2.dis2 - r2),r * (th - th1 - th2));
  #endif
  ans += r * (th - th1 - th2);
  return ans;
}

int main(void){
  #ifdef DEBUG
  freopen("in.txt","r",stdin);
  #endif
  scanf("%d%d%d",&n,&m,&r); r2 = r*r;
  b.read();
  FORR(i,1,m) p[i].read(), p[i].dis = dis(b, p[i]), p[i].dis2 = dis2(b, p[i]);
  
  FORR(i,1,m) FORR(j,i+1,m)
    G[i][j] = G[j][i] = cal(p[i], p[j]);
    
  FORR(i,1,m){
    double sum = 0;
    FORR(j,1,m) sum += G[i][j];
    printf("%.20lf\n",sum);
  }
  
  return 0;
}