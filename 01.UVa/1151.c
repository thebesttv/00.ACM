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

const int MAXN=1004, MAXM=MAXN*MAXN/2;
int n,q,ansMin;
int x[MAXN],y[MAXN];
VR<int> used;

struct Plan{
  int w; VR<int> v;
}plan[10];

int dis2(int i, int j){
  int dx=x[i]-x[j], dy=y[i]-y[j];
  return dx*dx + dy*dy;
}

int tail=0;
struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAXM];
void addEdge(int u, int v, int w){
  edge[tail++]=Edge{u,v,w};
}

int p[MAXN];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int kruskal(int st){
  MST(p,-1);
  int ans=0,cnt=0;
  FOR(i,0,q) if(st&(1<<i)){
    Plan &t=plan[i]; ans+=t.w;
    FOR(j,1,t.v.size()){
      int x1=fa(t.v[j]), x2=fa(t.v[j-1]);
      if(x1!=x2){
        p[x1]=x2; ++cnt;
      }
    }
  }
  if(cnt>=n-1) return ans;

  FOR(i,0,n-1){
    Edge &e=edge[used[i]];
    int x1=fa(e.u), x2=fa(e.v);
    if(x1!=x2){
      p[x1]=x2; ans+=e.w;
      if(++cnt==n-1) return ans;
    }
  }
  return ans;
}

int main(void){
  bool first=1;
  int T; scanf("%d",&T);
  while(T--){
    used.clear(); tail=0;
    scanf("%d%d",&n,&q);
    FOR(i,0,q){
      plan[i].v.clear(); int tn,t;
      scanf("%d%d",&tn,&plan[i].w);
      while(tn--){
        scanf("%d",&t); plan[i].v.push_back(t);
      }
    }
    FORR(i,1,n){
      scanf("%d%d",&x[i],&y[i]);
      FOR(j,1,i) addEdge(i,j,dis2(i,j));
    }
    sort(edge,edge+tail);

    // 第一遍 Kruskal
    MST(p,-1);
    int ans=0, cnt=0;
    FOR(i,0,tail){
      Edge &e=edge[i];
      int x1=fa(e.u), x2=fa(e.v);
      if(x1!=x2){
        p[x1]=x2; ans+=e.w;
        used.push_back(i);  // 记录边
        if(++cnt==n-1) break;
      }
    }
    ansMin=ans;

    FOR(i,1,1<<q) ansMin=min(ansMin,kruskal(i));

    if(first) first=0;
    else putchar('\n');
    printf("%d\n",ansMin);
  }
  return 0;
}
