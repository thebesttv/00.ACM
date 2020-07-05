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

const int MAX = 2e5 + 20;
int n,a[MAX];
LL f, fMax, s[MAX];
VR<int> G[MAX];

bool vis[MAX];
void dfs1(int u, int d){
  vis[u] = 1;
  s[u] = a[u];
  f += 1ll*d*a[u];

  for(int v : G[u]) if(!vis[v]){
    dfs1(v, d+1);
    s[u] += s[v];
  }
}

void dfs2(int u, LL f){
  fMax = max(f, fMax);
  vis[u] = 1;
  for(int v : G[u]) if(!vis[v]){
    dfs2(v, f - s[v] + s[1] - s[v]);
  }
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  int u, v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs1(1, 0);

  MST(vis,0);

  dfs2(1, f);

  printf("%lld\n",fMax);

  return 0;
}
