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
int n=100,G[MAX][MAX];
bool vis[MAX];

int main(void){
  int u, v, kase = 0;
  while(scanf("%d%d",&u,&v)==2 && u){
    MST(G,0x3f); MST(vis,0);

    G[u][v]=1; vis[u] = vis[v] = 1;
    while(scanf("%d%d",&u,&v)==2 && u){
      G[u][v]=1; vis[u] = vis[v] = 1;
    }
    FORR(i,1,n) if(vis[i]) G[i][i]=0;

    FORR(k,1,n) FORR(i,1,n) FORR(j,1,n)
      G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

    int sum = 0, cnt = 0;
    FORR(i,1,n) if(vis[i]){
      cnt++;
      FORR(j,1,n) if(vis[j]){
        sum += G[i][j];
      }
    }
    printf("Case %d: average length between pages = %.3lf clicks\n",
        ++kase, 1.0*sum/cnt/(cnt-1));
  }

  return 0;
}
