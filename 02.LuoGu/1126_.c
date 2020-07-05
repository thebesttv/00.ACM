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
const int INF=0x3f3f3f3f;
const int to[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,sx,sy,ex,ey,dir;
int G[MAX][MAX];
bool vis[MAX][MAX][4];

struct Node{
  int x, y, dir, t;
  Node(int x, int y, int dir, int t):
    x(x), y(y), dir(dir), t(t) { }
};

bool canGo(int x, int y, int dir, int t){
  FOR(i,0,t){
    x += to[dir][0]; y += to[dir][1];
    if(x<1 || x>=n || y<1 || y>=m) return 0;
    if(G[x][y] || G[x][y+1] || G[x+1][y] || G[x+1][y+1]) return 0;
  }
  return 1;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) FORR(j,1,m) scanf("%d",&G[i][j]);
  scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
  do dir=getchar(); while(!isalpha(dir));
  switch(dir){
    case 'N': dir=0; break;
    case 'E': dir=1; break;
    case 'S': dir=2; break;
    case 'W': dir=3;
  }

  int ansMin=INF;
  queue<Node> q;
  q.push(Node(sx,sy,dir,0));
  vis[sx][sy][dir]=1;
  while(!q.empty()){
    Node t = q.front(); q.pop();
    if(t.x==ex && t.y==ey){
      ansMin=min(ansMin,t.t);
    }

    ROR(i,3,1)
      if(canGo(t.x,t.y,t.dir,i)){
        int tx = t.x + to[t.dir][0]*i;
        int ty = t.y + to[t.dir][1]*i;
        if(!vis[tx][ty][dir]){
          q.push(Node(tx,ty,t.dir,t.t+1));
          vis[tx][ty][t.dir]=1;
        }
      }

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
  printf("%d\n",ansMin < INF ? ansMin : -1);

  return 0;
}
