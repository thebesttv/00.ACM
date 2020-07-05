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

const int MAX=120;
const double EPS=1e-6;
int n,x[MAX],y[MAX];

double dis(int x, int y, int x2, int y2){
  x-=x2, y-=y2;
  return sqrt(x*x + y*y);
}
int dcmp(double x){
  if(fabs(x)<EPS) return 0;
  return x<0 ? -1 : 1;
}
int dcmp(double x, double y){
  return dcmp(x-y);
}

struct Edge{
  int u,v; double w;
  Edge(int u, int v, double w): u(u), v(v), w(w) { }
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
};
VR<Edge> edge;

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    edge.clear(); MST(p,-1);
    scanf("%d",&n);
    FORR(i,1,n){
      scanf("%d%d",&x[i],&y[i]);
      FOR(j,1,i){
        double d = dis(x[i],y[i],x[j],y[j]);
        if(dcmp(d,10)>=0 && dcmp(d,1000)<=0){
          edge.push_back(Edge(i,j,d));
        }
      }
    }
    sort(ALL(edge));
    int cnt=0; double ans=0;
    for(Edge &e : edge){
      int p1=fa(e.u), p2=fa(e.v);
      if(p1!=p2){
        p[p1]=p2; ans+=e.w;
        if(++cnt==n-1) break;
      }
    }
    if(cnt<n-1) printf("oh!\n");
    else printf("%.1lf\n",ans*100);
  }

  return 0;
}
