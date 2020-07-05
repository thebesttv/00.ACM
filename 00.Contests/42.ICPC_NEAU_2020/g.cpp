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
LL s[MAX], ans[MAX], ori;
bool vis[MAX];
VR<int> G[MAX];

void dfs(int u, int d){
  s[u] = a[u];
  ori += 1ll * d * a[u];
  for(int v : G[u]) if(!s[v]){
    dfs(v, d+1); s[u] += s[v];
  }
}

void cal(int u, LL f){
#ifdef DEBUG
  printf("  cal (%d, %lld)\n",u,f);
#endif
  ans[u] = f; vis[u] = 1;
  for(int v : G[u]) if(!vis[v]){
    cal(v, f - s[v] + s[1] - s[v]);
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    ori = 0;

    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]), G[i].clear(), s[i]=0, vis[i]=0;
    int u, v;
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);
    }

    dfs(1, 1);
    cal(1, ori);

    FORR(i,1,n) printf("%lld ",ans[i]);
    putchar('\n');
  }

  return 0;
}
