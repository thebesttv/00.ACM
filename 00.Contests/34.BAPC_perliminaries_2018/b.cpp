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

const int to[2][6][2] = {
  { // even
    {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,0}, {1,1}
  },
  { // odd
    {-1,-1}, {-1,0}, {0,-1}, {0,1}, {1,-1}, {1,0}
  }
};
const int MAX = 1e3 + 20;
int n, m, h; bool G[MAX][MAX], vis[MAX][MAX];
VR<int> com;

int dfs(int i, int j){
  vis[i][j] = 1; int cnt = 1;
  FOR(d,0,6){
    int tx = i + to[i&1][d][0],
        ty = j + to[i&1][d][1];
    if(tx < 1 || tx > n || ty < 1 || ty > m)
      continue;
    if(vis[tx][ty] || G[tx][ty])
      continue;
#ifdef DEBUG
    printf("  (%d, %d) -> (%d,%d)\n",i,j,tx,ty);
#endif
    cnt += dfs(tx,ty);
  }
  return cnt;
}

int main(void){
  scanf("%d%d%d",&h,&n,&m);
  int ch;
  FORR(i,1,n) FORR(j,1,m){
    do ch = getchar(); while(ch!='.' && ch!='#');
    G[i][j] = ch == '#';
  }
#ifdef DEBUG
  FORR(i,1,n){
    FORR(j,1,m) printf("%d ",G[i][j]);
    putchar('\n');
  }
#endif
  FORR(i,1,n) FORR(j,1,m) if(!vis[i][j] && !G[i][j]){
    int x = dfs(i,j);
#ifdef DEBUG
    printf("  (%d, %d): %d\n",i,j,x);
#endif
    com.push_back(x);
  }
  sort(ALL(com),greater<int>());

  int ans = 0;
  if(h) for(int x : com){
    h -= x; ++ans;
    if(h<=0) break;
  }
  printf("%d\n",ans);

  return 0;
}
