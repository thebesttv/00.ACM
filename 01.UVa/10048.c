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

const int MAX=106;
const int INF=0x3f3f3f3f;
int n,m,q,G[MAX][MAX];

int main(void){
  int kase=0;
  while(scanf("%d%d%d",&n,&m,&q)==3 && n){
    MST(G,0x3f);
    int u,v,w;
    FOR(i,0,m){
      scanf("%d%d%d",&u,&v,&w);
      G[u][v]=G[v][u]=w;
    }
    FORR(k,1,n) FORR(i,1,n) FORR(j,1,n)
      G[i][j] = min(G[i][j], max(G[i][k],G[k][j]));

    if(kase) putchar('\n');
    printf("Case #%d\n",++kase);
    FOR(i,0,q){
      scanf("%d%d",&u,&v);
      if(G[u][v]==INF) printf("no path\n");
      else printf("%d\n",G[u][v]);
    }
  }

  return 0;
}
