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
int n,m;
struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAX*MAX];

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(p,-1);
    m = n*(n-1)/2;
    int u,v,w,st;
    FOR(i,0,m){
      scanf("%d%d%d%d",&u,&v,&w,&st);
      edge[i]=Edge{u,v, st ? 0 : w};
    }
    sort(edge,edge+m);

    int cnt=0, ans=0;
    FOR(i,0,m){
      Edge &e = edge[i];
      int p1 = fa(e.u), p2 = fa(e.v);
      if(p1 != p2){
        p[p1]=p2; ans+=e.w;
        if(++cnt == n-1) break;
      }
    }
    printf("%d\n",ans);
  }

  return 0;
}
