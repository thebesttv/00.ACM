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
const int INF=0x3f3f3f3f;
int n,G[MAX][MAX];

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(G,0x3f);
    FORR(i,1,n) G[i][i]=0;

    int v,w,m;
    FORR(u,1,n){
      scanf("%d",&m);
      while(m--){
        scanf("%d%d",&v,&w); G[u][v]=w;
      }
    }

    FORR(k,1,n) FORR(i,1,n) FORR(j,1,n)
      G[i][j] = min(G[i][j], G[i][k]+G[k][j]);

    bool connected=0;
    int ansMin=INF, r=-1;
    FORR(i,1,n){
      bool broken=0;
      int tMax=0;
      FORR(j,1,n){
        if(G[i][j]==INF){
          broken=1; break;
        }
        tMax=max(tMax,G[i][j]);
      }
      if(!broken){
        connected=1;
        if(tMax<ansMin){
          ansMin=tMax; r=i;
        }
      }
    }
    if(connected) printf("%d %d\n",r,ansMin);
    else printf("disjoint\n");
  }

  return 0;
}
