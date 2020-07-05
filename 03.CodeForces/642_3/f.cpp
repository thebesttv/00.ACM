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

const int MAX = 120;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n,m; LL a[MAX][MAX], f[MAX][MAX];

LL solve(int x, int y, int r, int c, LL ini){
  if(a[x][y] < ini) return INF;
  f[1][1] = a[x][y] - ini;

  FORR(i,1,r) FORR(j,1,c){
    if(i!=1 || j!=1) f[i][j] = INF;
    LL tar = ini + i + j - 2, delta = a[x+i-1][y+j-1] - tar;
    if(delta < 0) continue;
    if(i > 1) f[i][j] = min(f[i][j], f[i-1][j] + delta);
    if(j > 1) f[i][j] = min(f[i][j], f[i][j-1] + delta);
#ifdef DEBUG
    printf("    f[%d][%d]: %lld, tar: %lld, delta: %lld\n",i,j,f[i][j],tar,delta);
#endif
  }
  return f[r][c];
}

LL cal(int x, int y){
  LL ans = 0;
#ifdef DEBUG
  printf("  cal(%d, %d):\n",x,y);
#endif
  if(x != 1 || y != 1){
    ans += solve(1, 1, x, y, a[x][y] + 2 - x - y);
#ifdef DEBUG
    printf("    solve(%d, %d, %d, %d): %lld\n",1,1,x,y,solve(1, 1, x, y, a[x][y] + 2 - x - y));
#endif
  }

  if(x != n || y != m){
    ans += solve(x, y, n-x+1, m-y+1, a[x][y]);
#ifdef DEBUG
    printf("    solve(%d, %d, %d, %d): %lld\n",x,y,n-x+1,m-y+1,solve(x, y, n-x+1, m-y+1, a[x][y]));
#endif
  }
  return ans;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    FORR(i,1,n) FORR(j,1,m)
      scanf("%lld",&a[i][j]);

    LL ans = INF;
    FORR(i,1,n) FORR(j,1,m)
      ans = min(ans, cal(i,j));
    printf("%lld\n",ans);
  }

  return 0;
}
