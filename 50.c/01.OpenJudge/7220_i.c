/*
描述
在潘多拉星球，纳威人也热衷于搞房地产卖给中国人。他们把空中的悬浮山切割成一个个的立方体，然后在上面盖房子。一个立方体就是一个公寓楼。在悬浮山的表面上，重力是朝向山体中心的，因此每个面都有能住人的房间。作为到处投资的中国IT新贵，你看上了一座悬浮公寓，想知道这个公寓里面有多少个房间，以及最大的房间有多大。自己写个程序解决这个问题吧。
立方体的每个面被划分为k*k(k<20)个方格，方格有可能是平地，也有可能墙，墙无法通过。连续的平地可以形成房间。房间可以跨越棱线。
平地用0表示，墙用1表示。

           E--------------F
          /|             /|
         / |            / |
        /  |           /  |
       /   |          /   |
      A--------------B    |
      |    |         |    |
      |    |         |    |
      |    G---------|----H
      |   /          |   /
      |  /           |  /
      | /            | /
      |/             |/
      C--------------D

输入
输入第一行为测试数据组数。
对每组测试数据：
输入第一行为k，接下来为6*k行，每行k个字符(空格分开，平地用0表示，墙用1表示)，分别表示ABDC，BFHD，FEGH，EACG，EFBA，GHDC这6个平面。
每个平面第一个字母是左上角，第二个字母是右上角。

输出
输出房间个数和最大的房间大小(包含的平地格子数目)

样例输入
1
3
0 0 0
0 1 0
1 1 1
1 0 0
1 1 0
1 0 0
0 1 0
0 0 1
1 1 0
1 1 1
0 1 1
1 1 0
0 0 1
1 1 1
1 0 0
0 0 0
1 1 1
1 0 0

样例输出
6 12
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAX=20;
const int MAX_COLOR=1200;
int a[6][MAX][MAX],edge[12][2][MAX];
int space[MAX_COLOR]; //并查集，面积用负数表示
int color,n;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node{
  int x,y;

  Node(int x_=0, int y_=0): x(x_), y(y_) { }
};

int bfs(int (*G)[MAX], int x, int y, int color); //染色并返回面积大小
void create_edge();
int getParent(int x);
void merge(int x, int y);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    color=2;
    memset(space,0,sizeof(space)); memset(a,0,sizeof(a)); memset(edge,0,sizeof(edge));
    scanf("%d",&n);
    for(int i=0;i<6;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) scanf("%d",&a[i][j][k]);
    for(int i=0;i<6;i++){
      for(int j=0;j<n;j++) for(int k=0;k<n;k++) if(!a[i][j][k]){
        space[color] = -bfs(a[i],j,k,color); color++;
      }
    }
#ifdef DEBUG
    printf("before merge:\n");
    for(int i=2;i<color;i++) printf("  space[%d]: %d\n",i,space[i]);
#endif

    create_edge();
    for(int ed=0;ed<12;ed++){
      int *e1=edge[ed][0], *e2=edge[ed][1];
      for(int i=0;i<n;i++) if(e1[i]>=2 && e2[i]>=2) merge(e1[i],e2[i]);
    }
#ifdef DEBUG
    printf("after merge:\n");
    for(int i=2;i<color;i++) printf("  space[%d]: %d\n",i,space[i]);
#endif
    int ansMax=0,cnt=0;
    for(int i=2;i<color;i++) if(space[i]<0){
      ansMax=max(ansMax,-space[i]); cnt++;
    }
    printf("%d %d\n",cnt,ansMax);
  }

  return 0;
}

int bfs(int (*G)[MAX], int x, int y, int color){ //染色并返回面积大小
  queue<Node> q;
  Node temp(x,y); G[x][y]=color;
  q.push(temp);
  int cnt=0;
  while(!q.empty()){
    temp=q.front(); q.pop();
    cnt++;
    for(int i=0;i<4;i++){
      int tx=temp.x+to[i][0];
      int ty=temp.y+to[i][1];
      if(tx>=0 && tx<=n-1 && ty>=0 && ty<=n-1){
        if(!G[tx][ty]){ //不用vis
          G[tx][ty]=color;
          Node t(tx,ty); q.push(t);
        }
      }
    }
  }
  return cnt;
}
void create_edge(){
  for(int i=0;i<4;i++){ //BD, FH, EG, AC
    for(int j=0;j<n;j++){
      edge[i][0][j]=a[i][j][n-1];
      edge[i][1][j]=a[i==3 ? 0 : i+1][j][0];
    }
  }
  //AB
  for(int i=0;i<n;i++){
    edge[4][0][i]=a[4][n-1][i];
    edge[4][1][i]=a[0][0][i];
  }
  //CD
  for(int i=0;i<n;i++){
    edge[5][0][i]=a[0][n-1][i];
    edge[5][1][i]=a[5][n-1][i];
  }
  //GH
  for(int i=0;i<n;i++){
    //edge[6][0][i]=a[2][n-1][i];
    //edge[6][1][i]=a[5][0][i];
    edge[6][0][i]=a[5][0][i];
    edge[6][1][i]=a[2][n-1][n-i-1];
  }
  //EF
  for(int i=0;i<n;i++){
    edge[7][0][i]=a[2][0][i];
    edge[7][1][i]=a[4][0][n-i-1];
  }

  //AE
  for(int i=0;i<n;i++){
    edge[8][0][i]=a[3][0][i];
    edge[8][1][i]=a[4][i][0];
  }
  //BF
  for(int i=0;i<n;i++){
    edge[9][0][i]=a[4][i][n-1];
    edge[9][1][i]=a[1][0][n-i-1];
  }
  //DH
  for(int i=0;i<n;i++){
    edge[10][0][i]=a[1][n-1][i];
    edge[10][1][i]=a[5][n-i-1][n-1];
  }
  //CG
  for(int i=0;i<n;i++){
    edge[11][0][i]=a[5][i][0];
    edge[11][1][i]=a[3][n-1][i];
  }
}
int getParent(int x){
  return space[x]<0 ? x : space[x]=getParent(space[x]);
}
void merge(int x, int y){
  int px=getParent(x), py=getParent(y);
  if(px==py) return;
  space[px]+=space[py];
  space[py]=px;
}
