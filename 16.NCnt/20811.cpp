// Tag: iiii 树上背包 WHY TODO
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const LL MOD = 998244353;
const int MAX = 2020;
int n,m; LL f[MAX][MAX];
VR<int> G[MAX];

int dfs(int u, int fa){
  int siz = 1; f[u][1] = 1;
  for(int v : G[u]) if(v!=fa){

    /*
    int cnt = dfs(v, u); siz += cnt;
    ROR(j,min(m,siz),1){
      f[u][j] = f[u][j] * f[v][0]%MOD;
      FOR(k,1,min(j,cnt+1)){
        f[u][j] = (f[u][j] + f[u][j-k] * f[v][k])%MOD;
#ifdef DEBUG
        printf("  f[%d][%d] += f[%d][%d](%lld) * f[%d][%d](%lld) = %lld\n",
            u,j,u,j-k,f[u][j-k],v,k,f[v][k],f[u][j]);
#endif
      }
    }
    */

    int cnt = dfs(v, u);
    ROR(j,min(m,siz),1){
      //FORR(k,1,min(cnt,m)) if(j+k<=m)
      FORR(k,1,min(cnt,m-j))
        f[u][j+k] = (f[u][j+k] + f[u][j] * f[v][k])%MOD;
      f[u][j] = f[u][j] * f[v][0]%MOD;
    }
    siz += cnt;
  }

  FORR(i,1,min(siz,m)) f[u][0] = (f[u][0] + f[u][i])%MOD;
#ifdef DEBUG
  FORR(i,1,m) if(f[u][i]) printf("f[%d][%d]: %lld\n",u,i,f[u][i]);
#endif
  return siz;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].pb(v), G[v].pb(u);
  }
  dfs(1,-1);
  printf("%lld\n",f[1][0]);

  return 0;
}
