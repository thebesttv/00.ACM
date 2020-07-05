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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1020;
const int MOD = 1e9 + 7;
const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,a[MAX][MAX];
LL f[MAX][MAX][4];

struct Node{
  int x, y, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
}node[MAX*MAX];

bool isEnd(int x, int y){
  FOR(k,0,4){
    int tx = x + to[k][0],
        ty = y + to[k][1];
    if(tx<1 || tx>n || ty<1 || ty>m) continue;
    if(a[x][y]+1 == a[tx][ty]) return 0;
  }
  return 1;
}
bool ok(int x, int y){
  FOR(k,0,4){
    int tx = x + to[k][0],
        ty = y + to[k][1];
    if(tx<1 || tx>n || ty<1 || ty>m) continue;
    if(a[x][y] == a[tx][ty]+1) return 0;
  }
  return 1;
}

int main(void){
  scanf("%d%d",&n,&m); int tail = 0;
  FORR(i,1,n){
    FORR(j,1,m){
      scanf("%d",&a[i][j]);
      node[tail++] = {i,j,a[i][j]};
    }
  }
  sort(node,node+tail);

  FORR(i,1,n) FORR(j,1,m) if(isEnd(i,j)){
    f[i][j][1] = 1;
  }

  int x, y;
  FOR(i,0,tail){
    x = node[i].x, y = node[i].y;
    FOR(k,0,4){
      int tx = x + to[k][0],
          ty = y + to[k][1];
      if(tx<1 || ty<1 || tx>n || ty>m) continue;
      if(a[tx][ty] != a[x][y]+1){
        continue;
      }

      f[x][y][2] = (f[x][y][2] + f[tx][ty][1])%MOD;
      f[x][y][3] = (f[x][y][3] + f[tx][ty][2])%MOD;
      f[x][y][4] = (f[x][y][4] + f[tx][ty][3] + f[tx][ty][4])%MOD;
    }
#ifdef DEBUG
printf("  (%d,%d): %lld %lld %lld\n",x,y,f[x][y][2],f[x][y][3],f[x][y][4]);
#endif
  }
  LL ans = 0;
  FORR(i,1,n) FORR(j,1,m) if(ok(i,j)){
    ans = (ans + f[i][j][4])%MOD;
  }
  printf("%lld\n",ans);

  return 0;
}
