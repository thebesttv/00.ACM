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

const int MAXC=120, MAXN=420;
const int INF=0x3f3f3f3f;
int s,t,a,b;

struct sssp{
  int n;
  double d[MAXN],G[MAXN][MAXN];

  struct Node{
    double d;int u;
    Node(double d, int u): d(d), u(u) { }
    bool operator < (const Node &b) const {
      return d > b.d;
    }
  };
  PQ<Node> q;

  void init(int n){
    this->n = n;
    FORR(i,1,n){
      FOR(j,1,i) G[i][j]=G[j][i]=INF;
      G[i][i]=0;
    }
  }
  void addEdge(int u, int v, double w){
    G[u][v]=G[v][u]=w;
  }

  void Dij(int s){
    FORR(i,1,n) d[i]=INF; d[s]=0;
    q.push(Node(0,s));
    while(!q.empty()){
      Node t=q.top(); q.pop();
      if(t.d!=d[t.u]) continue;
      int u=t.u;
      FORR(v,1,n) if(d[v] > d[u] + G[u][v]){
        d[v] = d[u] + G[u][v];
        q.push(Node(d[v],v));
      }
    }
  }
}sp;

double dis(int x1, int y1, int x2, int y2){
  x1-=x2, y1-=y2; return sqrt(x1*x1 + y1*y1);
}
double dis2(int x1, int y1, int x2, int y2){
  x1-=x2, y1-=y2; return x1*x1 + y1*y1;
}
struct City{
  int t, x[4], y[4], idx[4];
  void init(){
    FOR(i,0,3) scanf("%d%d",&x[i],&y[i]);
    scanf("%d",&t);
    double d01 = dis2(x[0],y[0],x[1],y[1]);
    double d02 = dis2(x[0],y[0],x[2],y[2]);
    double d12 = dis2(x[1],y[1],x[2],y[2]);
    int p0,p1,p2;
    if(d01 > d02){
      if(d01 > d12){
        p0=0, p1=2, p2=1;
      }else{
        p0=1, p1=0, p2=2;
      }
    }else{  // d02>d01
      if(d02>d12){
        p0=0, p1=1, p2=2;
      }else{
        p0=1, p1=0, p2=2;
      }
    }
    int tx = x[p0] + x[p2];
    int ty = y[p0] + y[p2];
    x[3] = tx - x[p1];
    y[3] = ty - y[p1];
  }
}city[MAXC];

int main(void){
  scanf("%d%d%d%d",&s,&t,&a,&b);
  sp.init(4*s+2);
  FORR(i,1,s){
    city[i].init();
    FOR(j,0,4) city[i].idx[j] = (i-1)*4 + j+1;
  }
  FORR(i,1,s){
    City &c1=city[i];
    FOR(p1,0,4) FOR(p2,0,p1){
      sp.addEdge(c1.idx[p1], c1.idx[p2],
          dis(c1.x[p1],c1.y[p1],c1.x[p2],c1.y[p2])*c1.t);
    }

    FOR(j,1,i){
      City &c2=city[j];
      FOR(p1,0,4) FOR(p2,0,4){
        sp.addEdge(c1.idx[p1], c2.idx[p2],
            dis(c1.x[p1],c1.y[p1],c2.x[p2],c2.y[p2])*t);
      }
    }
  }
  int sa = 4*s+1, sb = 4*s+2;
  FOR(i,0,4) sp.addEdge(sa,city[a].idx[i],0);
  FOR(i,0,4) sp.addEdge(sb,city[b].idx[i],0);
  sp.Dij(sa);
  printf("%.2lf\n",sp.d[sb]);

  return 0;
}
