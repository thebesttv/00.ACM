/*
描述
Nemo is a naughty boy. One day he went into the deep sea all by himself. Unfortunately, he became lost and couldn't find his way home. Therefore, he sent a signal to his father, Marlin, to ask for help.
After checking the map, Marlin found that the sea is like a labyrinth with walls and doors. All the walls are parallel to the X-axis or to the Y-axis. The thickness of the walls are assumed to be zero.
All the doors are opened on the walls and have a length of 1. Marlin cannot go through a wall unless there is a door on the wall. Because going through a door is dangerous (there may be some virulent medusas near the doors), Marlin wants to go through as few doors as he could to find Nemo.
We assume Marlin's initial position is at (0, 0). Given the position of Nemo and the configuration of walls and doors, please write a program to calculate the minimum number of doors Marlin has to go through in order to reach Nemo.

输入
The input consists of several test cases. Each test case is started by two non-negative integers M and N. M represents the number of walls in the labyrinth and N represents the number of doors.
Then follow M lines, each containing four integers that describe a wall in the following format:
x y d t
(x, y) indicates the lower-left point of the wall, d is the direction of the wall -- 0 means it's parallel to the X-axis and 1 means that it's parallel to the Y-axis, and t gives the length of the wall.
The coordinates of two ends of any wall will be in the range of [1,199].
Then there are N lines that give the description of the doors:
x y d
x, y, d have the same meaning as the walls. As the doors have fixed length of 1, t is omitted.
The last line of each case contains two positive float numbers: f1 f2
(f1, f2) gives the position of Nemo. And it will not lie within any wall or door.
A test case of M = -1 and N = -1 indicates the end of input, and should not be processed.

输出
For each test case, in a separate line, please output the minimum number of doors Marlin has to go through in order to rescue his son. If he can't reach Nemo, output -1.

样例输入
8 9
1 1 1 3
2 1 1 3
3 1 1 3
4 1 1 3
1 1 0 3
1 2 0 3
1 3 0 3
1 4 0 3
2 1 1
2 2 1
2 3 1
3 1 1
3 2 1
3 3 1
1 2 0
3 3 0
4 3 1
1.5 1.5
4 0
1 1 0 1
1 1 1 1
2 1 1 1
1 2 0 1
1.5 1.7
-1 -1

样例输出
5
-1
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX=220;
int G[MAX][MAX],door[MAX][MAX],n,m,startx,starty;
bool vis[MAX][MAX];
int to[4][3]={{-1,0,1},{0,1,2},{1,0,4},{0,-1,8}};   //u,r,d,l
struct Node{
  int x,y;
  int step;

  Node(int x_, int y_, int step_): x(x_), y(y_), step(step_) { }
  Node(): x(0), y(0), step(0) { }

  bool operator < (const Node & b) const {
    return step>b.step;
  }
};

inline bool canGo(int x, int y, int dir);
inline bool haveDoor(int x, int y, int dir);
void setBit(int & a, int dir, bool tar);
int bfs();
void debug_print(int n){
  for(int i=0;i<4;i++){
    printf("%d",(n>>i)&1);
  }
}

int main(void){
  while(scanf("%d%d",&m,&n)==2 && m!=-1){
    int x,y,d,l;
    memset(vis,0,sizeof(vis)); memset(door,0,sizeof(door));
    for(int i=1;i<MAX-1;i++) for(int j=1;j<MAX-1;j++) G[i][j]=15;
    for(int i=0;i<MAX;i++){
      G[i][0]=7; G[i][MAX-1]=13;
      G[0][i]=14; G[MAX-1][i]=11;
    }

    for(int i=0;i<m;i++){
      scanf("%d%d%d%d",&y,&x,&d,&l);
      if(!d){
        for(int j=0;j<l;j++){
          setBit(G[x-1][y+j],2,0);
          setBit(G[x][y+j],0,0);
        }
      }else{
        for(int j=0;j<l;j++){
          setBit(G[x+j][y-1],1,0);
          setBit(G[x+j][y],3,0);
        }
      }
    }
    for(int i=0;i<n;i++){
      scanf("%d%d%d",&y,&x,&d);
      if(!d){
        setBit(G[x-1][y],2,1);
        setBit(G[x][y],0,1);
        setBit(door[x-1][y],2,1);
        setBit(door[x][y],0,1);
      }else{
        setBit(G[x][y-1],1,1);
        setBit(G[x][y],3,1);
        setBit(door[x][y-1],1,1);
        setBit(door[x][y],3,1);
      }
    }
#ifdef DEBUG
    printf("G:\n");
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        debug_print(G[i][j]); printf(" ");
      }
      printf("\n");
    }
    printf("door:\n");
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        debug_print(door[i][j]); printf(" ");
      }
      printf("\n");
    }
#endif
    float sx,sy; scanf("%f%f",&sy,&sx); startx=sx; starty=sy;
    int ans;
    if(sx<0 || sx>199 || sy<0 || sy>199) ans=0;
    else ans=bfs();
    printf("%d\n",ans);
  }

  return 0;
}

int bfs(){
  priority_queue<Node> q;     //使用pq，每次选取step最少的扩展，类似于倒水问题。贪心？
  //queue<Node> q;            //不能使用普通队列
  Node temp(startx,starty,0);
  q.push(temp);
  vis[temp.x][temp.y]=1;
  while(!q.empty()){
    temp=q.top(); q.pop();
#ifdef DEBUG
    printf("  bfs: (%d,%d), doors: %d\n",temp.x,temp.y,temp.step);
#endif
    if(temp.x==0 && temp.y==0) return temp.step;
    int x=temp.x, y=temp.y;
    for(int dir=0;dir<4;dir++){
      int tx=x+to[dir][0],ty=y+to[dir][1];
      if(tx<0 || tx>MAX-1 || ty<0 || ty>MAX-1) continue;
      if(canGo(x,y,dir) && !vis[tx][ty]){
        vis[tx][ty]=1;  //莫忘
        Node t(tx,ty,temp.step);
        if(haveDoor(x,y,dir)) t.step++;
        //if(x<minx || y<miny || x>maxx || y>maxy) return temp.step;
        q.push(t);
      }
    }
  }
  return -1;
}
inline bool canGo(int x, int y, int dir){
  return G[x][y] & to[dir][2];
}
inline bool haveDoor(int x, int y, int dir){
  return door[x][y] & to[dir][2];
}
void setBit(int & a, int dir, bool tar){
  if(tar) a|=to[dir][2];
  else a&=(~to[dir][2]);
}
