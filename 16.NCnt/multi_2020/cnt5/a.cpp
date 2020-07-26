// Tag: iiiii DP
// 按我的智商怕是理解不了了……
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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 320;
const LL INF = 0x3f3f3f3f3f3f3f3fll;
int n,m,k,G[MAX][MAX];
LL f[MAX*2][MAX];

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  int u,v,w; MST(G,0x3f);
  while(m--){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v] = G[v][u] = min(G[u][v],w);
  }
  FORR(i,1,n) G[i][i] = 0;
  FORR(kk,1,n) FORR(i,1,n) FORR(j,1,n)
    G[i][j] = min(G[i][j], G[i][kk] + G[kk][j]);

  u = 1; k *= 2;
  MST(f,0x3f); f[0][1] = 0;
  FOR(i,0,k){
    scanf("%d",&v); // u -> v
    FORR(p,1,n) if(f[i][p] < INF){
      LL a = f[i][p];
      f[i+1][p] = min(f[i+1][p], a + G[u][v]);
      FORR(q,1,n){
        f[i+1][q] = min(f[i+1][q], a + G[u][q] + G[p][v]);
        f[i+1][q] = min(f[i+1][q], a + G[p][q] + G[q][v]);
      }
    }
    u = v;
  }
  LL ansMin = INF;
  FORR(i,1,n) ansMin = min(ansMin, f[k][i]);
  printf("%lld\n",ansMin);

  return 0;
}
