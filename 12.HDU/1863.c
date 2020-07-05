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

const int MAX=120;
int n,m,fa[MAX];
struct Edge{
  int u,v,w;
  Edge(int u, int v, int w): u(u), v(v), w(w) { }
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
};
VR<Edge> edge;

void addEdge(int u, int v, int w){
  edge.push_back(Edge(u,v,w));
}
int p(int x){
  return fa[x]==-1 ? x : fa[x]=p(fa[x]);
}

int main(void){
  while(scanf("%d%d",&m,&n)==2 && m){
    edge.clear(); MST(fa,-1);
    int u,v,w;
    FOR(i,0,m){
      scanf("%d%d%d",&u,&v,&w);
      addEdge(u,v,w);
    }
    sort(edge.begin(),edge.end());
    int cnt=0,ans=0;
    for(Edge &e : edge){
      int p1=p(e.u),p2=p(e.v);
      if(p1!=p2){
        fa[p1]=p2; cnt++; ans+=e.w;
        if(cnt==n-1) break;
      }
    }
    if(cnt<n-1) printf("?\n");
    else printf("%d\n",ans);
  }

  return 0;
}
