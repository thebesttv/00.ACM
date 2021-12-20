#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

bool G[40][40];
bool vis[34][34][34][34]; //已知空格的位置和指定格的位置，即可重构出状态
int n,m,sx,sy,ex,ey;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node{
  int x,y;
  int sx,sy;
  int step;
  Node(int x_, int y_, int sx_, int sy_, int step_): x(x_), y(y_), sx(sx_), sy(sy_), step(step_) { }
};

int bfs(int x, int y);

int main(void){
  int q,t; scanf("%d%d%d",&n,&m,&q);
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
    scanf("%d",&t); G[i][j]=t;
  }
  int x,y;
  for(int i=0;i<q;i++){
    scanf("%d%d%d%d%d%d",&x,&y,&sx,&sy,&ex,&ey);
    int ans=bfs(x,y);
    printf("%d\n",ans);
  }

  return 0;
}

int bfs(int x, int y){
  queue<Node> q; q.push(Node(x,y,sx,sy,0));
  vis[x][y][sx][sy]=1;
  while(!q.empty()){
    Node t=q.front(); q.pop();
#ifdef DEBUG
    printf("  in bfs with q.front(): (%d,%d), from (%d,%d) to (%d,%d) with step: %d\n",t.x,t.y,t.sx,t.sy,ex,ey,t.step);
#endif
    if(t.sx==ex && t.sy==ey) return t.step;
    for(int i=0;i<4;i++){
      int tx=t.x+to[i][0];
      int ty=t.y+to[i][1];
      int tsx=t.sx,tsy=t.sy;
      if(tx<1 || tx>n || ty<1 || ty>m) continue;
      if(tx==t.sx && ty==t.sy) tsx=t.x,tsy=t.y; //与指定格交换
      if(!G[tx][ty] || vis[tx][ty][tsx][tsy]) continue;
      vis[tx][ty][tsx][tsy]=1;
      q.push(Node(tx,ty,tsx,tsy,t.step+1));
    }
  }
  return -1;
}
