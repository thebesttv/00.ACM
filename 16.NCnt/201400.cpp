// Tag: 树型DP
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

const int MAX = 1e6 + 20;
int n,f[MAX]; LL ansMin;
VR<int> G[MAX];

int dfs1(int u, int dep, int fa){
  ansMin += dep;
  int &a = f[u]; a = 1;
  for(int v : G[u]) if(v!=fa){
    a += dfs1(v, dep+1, u);
  }
  return a;
}

void dfs2(int u, LL sum, int fa){
  ansMin = min(ansMin, sum);
  for(int v : G[u]) if(v!=fa){
    dfs2(v, sum - f[v] + n - f[v], u);
  }
}

int main(void){
  scanf("%d",&n); int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].pb(v), G[v].pb(u);
  }
  dfs1(1,0,-1);
  dfs2(1,ansMin,-1);
  printf("%lld\n",ansMin);

  return 0;
}
