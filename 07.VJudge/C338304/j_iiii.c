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

const int MAX=1e5+20;
int n,m;
struct Edge{
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w < b.w;
  }
};
VR<Edge> edge;

int p[MAX];
int fa(int x){
  return p[x] < 0 ? x : p[x] = fa(p[x]);
}

int mst(){
  MST(p,-1);
  int cnt=0, ans=0;
  for(Edge &e : edge){
    int p1 = fa(e.u), p2 = fa(e.v);
    if(p1 == p2) continue;
    p[p1] = p2; ans += e.w;
    if(++cnt == n-1) break;
  }
  return cnt==n-1 ? ans : -1;
}

bool ok(int l, int r){
  int x1 = 1, x2 = 1;
  while(x2 < l){
    int t = x1 + x2;
    x1 = x2, x2 = t;
  }
  return x2 <= r;
}

int main(void){
  int u,v,w, kase=0;
  int T; scanf("%d",&T);
  while(T--){
    printf("Case #%d: ",++kase);

    edge.clear();
    scanf("%d%d",&n,&m);
    while(m--){
      scanf("%d%d%d",&u,&v,&w);
      edge.push_back(Edge{u,v,w});
    }

    sort(ALL(edge));
    int l = mst();
    if(l==-1){
      printf("No\n"); continue;
    }

    reverse(ALL(edge));
    int r = mst();
    printf("%s\n", ok(l,r) ? "Yes" : "No");
  }

  return 0;
}
