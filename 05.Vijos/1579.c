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

const int MAX=20020;
int n;
struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
};
VR<Edge> edge;

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}
void merge(int x, int y){
  x=fa(x), y=fa(y);
  if(x!=y){
    p[y]+=p[x]; p[x]=y;
  }
}
int main(void){
  MST(p,-1);
  scanf("%d",&n);
  int u,v,w;
  FOR(i,1,n){
    scanf("%d%d%d",&u,&v,&w);
    edge.push_back(Edge{u,v,w});
  }
  sort(ALL(edge));
  LL ans=0;
  for(Edge e : edge){
    int x=fa(e.u), y=fa(e.v);
    ans += e.w;
    ans += (e.w+1ll) * (p[x]*p[y] - 1ll);
    merge(x,y);
  }
  printf("%lld\n",ans);

  return 0;
}
