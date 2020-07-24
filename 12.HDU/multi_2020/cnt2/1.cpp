// Tag: 正难则反 并查集 连通块
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

const int MAX = 100020;
int n,m; pii b[MAX]; bool ok[MAX];
VR<int> G[MAX];

int fa[MAX];
int p(int x){
  return fa[x] < 0 ? x : fa[x] = p(fa[x]);
}
bool merge(int x, int y){
  x = p(x), y = p(y);
  if(x == y) return false;
  fa[x] = y;
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    FORR(i,1,n) G[i].clear(), fa[i] = -1, ok[i] = 0;
    FORR(i,1,n) scanf("%d",&b[i].FI), b[i].SE = i;
    sort(b+1,b+1+n,greater<pii>());
    b[n+1] = {0,0};

    int u,v;
    while(m--){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int i = 1; LL ans = 0; int cnt = 0;
    while(i <= n){
      int j = i+1;
      while(j <= n && b[j].FI == b[i].FI) ++j;
#ifdef DEBUG
      printf("  cnt += %d\n",j-i);
#endif
      cnt += j - i;
      FOR(k,i,j) ok[b[k].SE] = 1;
      FOR(k,i,j){
        u = b[k].SE;
        for(int v : G[u]) if(ok[v] && merge(u,v)){
          --cnt;
#ifdef DEBUG
          printf("  merged(%d, %d)\n",u,v);
#endif
        }
      }
#ifdef DEBUG
      printf("  -> %d,  add %d\n",cnt,b[i].FI - b[j].FI);
#endif
      ans += 1ll * cnt * (b[i].FI - b[j].FI);
      i = j;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
