// Tag: 树上背包 TODO iii
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

const int MAX = 320;
int n,m,a[MAX],f[MAX][MAX]; VR<int> G[MAX];

void dfs(int u){
  f[u][0] = 0;
  if(G[u].empty()) { f[u][1] = a[u]; return; }
  for(int v : G[u]){
    dfs(v);
    ROR(k,m,0) FORR(j,0,k)
      f[u][k] = max(f[u][k], f[u][k-j] + f[v][j]);
  }
  ROR(k,m,1) f[u][k] = f[u][k-1] + a[u]; f[u][0] = 0;
#ifdef DEBUG
  FORR(i,0,m) if(f[u][i]>0) printf("f[%d][%d]: %d\n",u,i,f[u][i]);
#endif
}

int main(void){
  scanf("%d%d",&n,&m); ++m; int u;
  FORR(v,1,n){
    scanf("%d%d",&u,&a[v]); G[u].pb(v);
  }
  MST(f,-0x3f); dfs(0);
  printf("%d\n",f[0][m]);

  return 0;
}
