/*
描述
定义一个二维数组：
int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 0, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。

输入
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。

输出
左上角到右下角的最短路径，格式如样例所示。

样例输入
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

样例输出
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
*/

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int a[6][6];
struct Node{
  int x,y;
  int f;
}q[30];
bool book[6][6];
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int bfs();
void print(int n);

int main(void){
  for(int i=0;i<5;i++) for(int j=0;j<5;j++) scanf("%d",&a[i][j]);
  int tail=bfs();
  print(tail);

  return 0;
}

int bfs(){
  q[0].x=0;q[0].y=0; q[0].f=-1;
  int head=0,tail=1;
  while(head<tail){
    Node temp=q[head];
    if(temp.x==4 && temp.y==4) return head;
    for(int i=0;i<4;i++){
      int tx=temp.x+to[i][0];
      int ty=temp.y+to[i][1];
      if(book[tx][ty] || a[tx][ty]) continue;
      if(tx>=0 && tx<=4 && ty>=0 && ty<=4){
        book[tx][ty]=1;
        q[tail].x=tx; q[tail].y=ty; q[tail].f=head; tail++;
      }
    }
    head++;
  }
  return -1;
}
void print(int n){
  stack<Node> st;
  while(q[n].f!=-1){
    st.push(q[n]);
    n=q[n].f;
  }
  st.push(q[0]);
  while(!st.empty()){
    Node temp=st.top(); st.pop();
    printf("(%d, %d)\n",temp.x,temp.y);
  }
}
