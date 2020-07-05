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

const int MAX=200020;
int n,m,fa[5020];
struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAX];

int p(int x){
  return fa[x]==-1 ? x : fa[x]=p(fa[x]);
}

int main(void){
  MST(fa,-1);
  scanf("%d%d",&n,&m);
  FOR(i,0,m) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
  sort(edge,edge+m);
  int ans=0,cnt=0,eMax=0;
  FOR(i,0,m){
    int x1=p(edge[i].u), x2=p(edge[i].v);
    if(x1!=x2){
      cnt++, ans+=edge[i].w, fa[x1]=x2;
      eMax=max(eMax,edge[i].w);
      if(cnt==n-1) break;
    }
  }
  printf("%d %d\n",cnt,eMax);

  return 0;
}
