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

const int MAX=60;
const int to[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int n,m,sx,sy,sdir,ex,ey;
int G[MAX][MAX]; bool vis[MAX][MAX][4];

struct Node{
  int x,y,dir,t;
  Node(int x, int y, int dir, int t):
    x(x), y(y), dir(dir), t(t) { }
};

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) FORR(j,1,m) scanf("%d",&G[i][j]);
  scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
  do sdir = getchar(); while(!isalpha(sdir));
  switch(sdir){
    case 'N': sdir=0; break;
    case 'E': sdir=1; break;
    case 'S': sdir=2; break;
    case 'W': sdir=3;
  }

  queue<Node> q;
  q.push(Node(sx,sy,sdir,0)); vis[sx][sy][sdir]=1;
  while(!q.empty()){
    Node t = q.front(); q.pop();
    if(t.x==ex && t.y==ey){
      printf("%d\n",t.t); return 0;
    }

    // go
    FORR(i,1,3){
      int tx = t.x + to[t.dir][0]*i;
      int ty = t.y + to[t.dir][1]*i;
      if(tx<1 || tx>=n || ty<1 || ty>=m) break;
      if(G[tx][ty] || G[tx][ty+1] || G[tx+1][ty] || G[tx+1][ty+1]) break;
      if(!vis[tx][ty][t.dir]){
        q.push(Node(tx,ty,t.dir,t.t+1));
        vis[tx][ty][t.dir]=1;
      }
    }

    // turn
    int d = (t.dir+1)%4;
    if(!vis[t.x][t.y][d]){
      q.push(Node(t.x,t.y,d,t.t+1));
      vis[t.x][t.y][d]=1;
    }
    d = (t.dir-1+4)%4;
    if(!vis[t.x][t.y][d]){
      q.push(Node(t.x,t.y,d,t.t+1));
      vis[t.x][t.y][d]=1;
    }
  }

  printf("-1\n");

  return 0;
}
