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

const int MAX=1020;
const int INF=0x3f3f3f3f;
const double EPS=1e-6;
int n,d;

inline int dcmp(double x){
  return fabs(x)<EPS ? 0 : ( x>0 ? 1 : -1 );
}
struct Node{
  double l,r;
  bool operator < (const Node &b) const {
    return dcmp(r-b.r) ? dcmp(r-b.r)<0 : dcmp(l-b.l)<0;
  }
}node[MAX];

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&d)==2 && n){
    bool bad=0;
    FOR(i,0,n){
      int x,y; scanf("%d%d",&x,&y);
      if(y>d) { bad=1; continue; }
      double t = sqrt(d*d-y*y);
      node[i].l=x-t, node[i].r=x+t;
    }
    if(bad) { printf("Case %d: -1\n",++kase); continue; }
    sort(node,node+n);
    int i=0,cnt=0; double cur=-INF;
    while(i<n){
      if(node[i].l > cur){
        cnt++; cur=node[i].r;
      }
      i++;
    }
    printf("Case %d: %d\n",++kase,cnt);
  }

  return 0;
}
