// Tag: 树形DP 树上背包 ii
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

const int MAX = 3020;
const int INF = 0x3f3f3f3f;
int n,m,a[MAX],f[MAX][MAX];
struct Edge { int v, w; };
VR<Edge> G[MAX];

int dfs(int u){
  f[u][0] = 0;
  if(u > n-m){
    f[u][1] = a[u]; return 1;
  }

  int cnt = 0;
  for(Edge e : G[u]){
    int siz = dfs(e.v); cnt += siz;
    ROR(k,cnt,1) FORR(j,1,siz)
      f[u][k] = max(f[u][k], f[u][k-j] + f[e.v][j] - e.w);
  }
  return cnt;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(u,1,n-m){
    int k,v,w; scanf("%d",&k);
    while(k--){
      scanf("%d%d",&v,&w); G[u].pb({v,w});
    }
  }
  FORR(i,n-m+1,n) scanf("%d",&a[i]);
  MST(f,-0x3f); dfs(1);
  ROR(i,m,0) if(f[1][i]>=0){
    printf("%d\n",i); break;
  }

  return 0;
}
