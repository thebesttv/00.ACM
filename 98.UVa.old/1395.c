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

const int MAXN=120;
const int MAXM=MAXN*MAXN/2;
const int INF=0x3f3f3f3f;
int n,m,ansMin;

struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAXM];

int p[MAXN];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int mst(int l){
  MST(p,-1);
  int ans=INF, cnt=0;
  FOR(i,l,m){
    Edge &e=edge[i];
    int x1=fa(e.u), x2=fa(e.v);
    if(x1!=x2){
      p[x1]=x2;
      if(e.w-edge[l].w > ansMin)
        return ansMin;  // 当前解不会更优,但之后 l'>l 可能得到更优解
      if(++cnt==n-1){
        ans=e.w-edge[l].w;
        break;
      }
    }
  }
  return ans;
}

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    FOR(i,0,m) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    sort(edge,edge+m);

    ansMin=INF;
    FOR(l,0,m){
      int t=mst(l);
      if(t==INF) break;
      ansMin=min(ansMin,t);
    }
    printf("%d\n",ansMin == INF ? -1 : ansMin);
  }

  return 0;
}
