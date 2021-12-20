/*
描述
阿尔吉侬是一只聪明又慵懒的小白鼠，它最擅长的就是走各种各样的迷宫。今天它要挑战一个非常大的迷宫，研究员们为了鼓励阿尔吉侬尽快到达终点，就在终点放了一块阿尔吉侬最喜欢的奶酪。现在研究员们想知道，如果阿尔吉侬足够聪明，它最少需要多少时间就能吃到奶酪。
迷宫用一个R×C的字符矩阵来表示。字符S表示阿尔吉侬所在的位置，字符E表示奶酪所在的位置，字符#表示墙壁，字符.表示可以通行。阿尔吉侬在1个单位时间内可以从当前的位置走到它上下左右四个方向上的任意一个位置，但不能走出地图边界。

输入
第一行是一个正整数T（1 <= T <= 10），表示一共有T组数据。
每一组数据的第一行包含了两个用空格分开的正整数R和C（2 <= R, C <= 200），表示地图是一个R×C的矩阵。
接下来的R行描述了地图的具体内容，每一行包含了C个字符。字符含义如题目描述中所述。保证有且仅有一个S和E。

输出
对于每一组数据，输出阿尔吉侬吃到奶酪的最少单位时间。若阿尔吉侬无法吃到奶酪，则输出“oop!”（只输出引号里面的内容，不输出引号）。每组数据的输出结果占一行。

样例输入
3
3 4
.S..
###.
..E.
3 4
.S..
.E..
....
3 4
.S..
####
..E.

样例输出
5
1
oop!
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

bool a[204][204],vis[204][204];
int startx,starty,endx,endy;
int r,c;
struct Node{
  int x,y;
  int step;
};
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void read();
int bfs();

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    memset(a,0,sizeof(a)); memset(vis,0,sizeof(vis));
    scanf("%d%d",&r,&c);
    read();
    int ans=bfs();
    if(ans!=-1) printf("%d\n",ans);
    else printf("oop!\n");
  }

  return 0;
}

void read(){
  int ch;
  for(int i=0;i<r;i++){
    getchar();
    for(int j=0;j<c;j++){
      ch=getchar();
      if(ch=='#') a[i][j]=1;
      else if(ch=='S') {startx=i; starty=j;}
      else if(ch=='E') {endx=i; endy=j;}
    }
  }
}
int bfs(){
  Node temp;
  temp.x=startx; temp.y=starty; temp.step=0;
  vis[temp.x][temp.y]=1;
  queue<Node> q;
  q.push(temp);
  while(!q.empty()){
    temp=q.front(); q.pop();
    if(temp.x==endx && temp.y==endy) return temp.step;
    for(int i=0;i<4;i++){
      int tx=temp.x+to[i][0];
      int ty=temp.y+to[i][1];
      if(tx>=0 && tx<=r-1 && ty>=0 && ty<=c-1){
        if(!a[tx][ty] && !vis[tx][ty]){
          Node a;
          a.x=tx; a.y=ty; a.step=temp.step+1;
          vis[tx][ty]=1;
          q.push(a);
        }
      }
    }
  }
  return -1;
}
