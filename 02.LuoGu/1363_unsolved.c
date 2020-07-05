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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1520;
const int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,sx,sy; bool canEsc;
char G[MAX][MAX];
int vis[MAX][MAX];

void dfs(int x, int y, int b){  // b: 穿过边界的次数
  if(x==0 || x==n-1 || y==0 || y==m-1) b++;
  vis[x][y]=b;
#ifdef DEBUG
  printf("(%d,%d), %d\n",x,y,b);
#endif
  FOR(k,0,4){
    int tx=(x+to[k][0]+n)%n, ty=(y+to[k][1]+m)%m;
    if(G[tx][ty]!='#'){
      if(G[tx][ty]=='S' && b>=2+1){
#ifdef DEBUG
        printf("  in (%d,%d) -> (%d,%d), get yes\n",x,y,tx,ty);
#endif
        canEsc=1; return;
      }else if(vis[tx][ty]!=b) dfs(tx,ty,b);
    }
  }
}

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    MST(vis,0); canEsc=0;
    FOR(i,0,n){
      scanf("%s",G[i]);
      FOR(j,0,m) if(G[i][j]=='S')
        sx=i, sy=j;
    }

    dfs(sx,sy,1);
    printf("%s\n",canEsc ? "Yes" : "No" );
  }

  return 0;
}

/*
const int MAX=1520;
const int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m; char G[MAX][MAX];
bool vis[MAX][MAX];

void dfs(int x, int y){
  vis[x][y]=1;
  FOR(k,0,4){
    int tx=x+to[k][0], ty=y+to[k][1];
    if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
    if(G[tx][ty]!='#' && !vis[tx][ty]){
      dfs(tx,ty);
    }
  }
}

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    MST(vis,0);
    int sx=-1,sy=-1;
    FOR(i,0,n){
      scanf("%s",G[i]);
      if(sx==-1) FOR(j,0,m) if(G[i][j]=='S'){
        sx=i, sy=j; break;
      }
    }
    dfs(sx,sy);

    bool canEsc=0;
    FOR(i,0,n) if(vis[i][0] && vis[i][m-1]) canEsc=1;
    FOR(j,0,m) if(vis[0][j] && vis[n-1][j]) canEsc=1;
    printf("%s\n",canEsc ? "Yes" : "No" );
  }

  return 0;
}
*/
