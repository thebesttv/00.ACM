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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10020;
const int INF=0x3f3f3f3f;
const double R=6374, PI=acos(-1);
const double EPS=1e-6;
int n; double d[MAX];

int dcmp(double x){
  if(fabs(x)<EPS) return 0;
  return x<0 ? -1 : 1;
}

VR<int> G[MAX];

struct Point{
  double x,y,z;
  Point() { }
  Point(double t, double a){
    x = y = R * cos(a);
    x *= cos(t), y *= sin(t);
    z = R * sin(a);
  }
}p[MAX];

double dis(Point &a, Point &b){
  double dx = a.x - b.x,
         dy = a.y - b.y,
         dz = a.z - b.z;
  double d = sqrt(dx*dx + dy*dy + dz*dz);
  double t = asin( d / 2 / R);
  return R * t * 2;
}

struct Node{
  double d; int u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

void Dij(int s){
  FORR(i,1,n) d[i]=INF; d[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u = t.u;
    if(d[u]!=t.d) continue;
    for(int v : G[u]){
      double dd = dis(p[u],p[v]);
      if(d[v] > d[u] + dd){
        d[v] = d[u] + dd;
        q.push(Node{d[v],v});
      }
    }
  }
}


int main(void){
  scanf("%d",&n);
  int a,t; char c1, c2;
  FORR(i,1,n){
    scanf("%d%c %d%c\n",&t,&c1,&a,&c2);
    if(c1=='W') t=-t;
    if(c2=='S') a=-a;
    p[i] = Point(t*PI/180, a*PI/180);
#ifdef DEBUG
    printf("  get (%.1lf, %.1lf, %.1lf)\n", p[i].x, p[i].y, p[i].z);
#endif
  }
  int u,v;
  while(scanf("%d%d",&u,&v)==2)
    G[u].push_back(v);

  Dij(1);

  if(!dcmp(d[n]-INF)) printf("Impossible\n");
  else printf("%.2lf\n",d[n]);

  return 0;
}
