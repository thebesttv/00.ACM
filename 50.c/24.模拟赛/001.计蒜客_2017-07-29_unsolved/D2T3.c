/*
蒜头君是一个乐于助人的好孩子，这天他所在的乡村发生了洪水，有多名村民被困于孤岛上，于是蒜头君决定去背他们离开困境，假设蒜头君所在的村子是 n*m 的网格，网格中 . 号代表平地， # 号代表该地已被洪水淹没，A、B...等大写字母表示该地有村民被困，s代表蒜头君的起点，t代表蒜头君的终点。
蒜头君的初始速度为 k 秒一格，他每次可以向上下左右 4 个方向中的一个移动 1 格。在背上一个村民后，他的速度可能会降低，也可能会加快，但他的速度不能快于 1 秒每格，那么蒜头君想知道，他最快需要多长时间将所有村民救出？
注意：不能在终点以外的地方放下村民；可以同时背多个村民。

输入格式
第一行 3 个正整数 n,m,k，分别表示村庄长度、宽度、蒜头君初始速度。
接下来 n 行，每行一个长度为 m 的字符串，表示村庄的地形，字符串意义如上所述。
接下来若干行，每行一个大写字母、一个整数，表示该编号的村民会使 k 增加/减少多少。行数等同于地形中大写字母的个数。大写字母按字典序，即A、B、C的顺序排列，保证前后两行的字母是连续的。

输出格式
输出 1 个整数，表示最小用时。

数据规模
对于 10% 的数据，满足 1≤n,m≤5，村民个数为 1；
对于 50% 的数据，满足 1≤n,m≤5，村民个数小于等于 5；
对于 100% 的数据，满足 1≤n,m≤10，村民个数小于等于 10。

样例输入
4 4 2
s.##
..A#
.B##
...t
A -3
B 4

样例输出
17
*/

/*
  得分：30
  解题报告：
  一开始准备只写只有一个村民时的情况，暴力10分，后来发现和 OpenJudge 的 拯救公主 非常相似，几乎照搬代码，只把队列改为优先队列。但最后可能因为代码写错，自己写的测试数据都没过。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<queue>
#include<set>
using namespace std;

char G[20][20];
bool vis[20][20][1<<11];
int tot=0,r,c,ori_speed;
int ansMin=1<<30;
int startx,starty;
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int speed[20];
struct Node{
  int x,y;
  int saved,step;
  int speed;

  Node(int x_, int y_, int step_, int saved_, int speed_): x(x_), y(y_), step(step_), saved(saved_), speed(speed_) { }

  bool operator < (const Node & b) const {
    return speed>b.speed;
  }
};
priority_queue<Node> q;

int bfs();

int main(void){
  scanf("%d%d%d",&r,&c,&ori_speed);
  for(int i=0;i<r;i++){
    getchar();
    for(int j=0;j<c;j++){
      G[i][j]=getchar();
      if(isupper(G[i][j])) tot++;
      else if(G[i][j]=='s') startx=i,starty=j;
    }
  }
  for(int i=0;i<tot;i++){
    int s; char ch;
    do ch=getchar(); while(!isupper(ch));
    scanf("%d",&s);
    speed[ch-'A']=s;
  }
#ifdef DEBUG
  printf("get:\n");
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++) putchar(G[i][j]);
    putchar('\n');
  }
  printf("tot: %d\n",tot);
  for(int i=0;i<tot;i++) printf("%c: %d\n",i+'A',speed[i]);
#endif
  int ans=bfs();
  printf("%d\n",ans);

  return 0;
}

int bfs(){
  q.push(Node(startx,starty,0,0,ori_speed));
  vis[startx][starty][0]=1;
  while(!q.empty()){
    Node temp=q.top(); q.pop();
#ifdef DEBUG
    printf("  (%d,%d), step: %d, speed: %d, saved: %d\n",temp.x,temp.y,temp.step,temp.speed,temp.saved);
#endif
    if(G[temp.x][temp.y]=='t' && temp.saved==((1<<tot)-1)) return temp.step;
    for(int i=0;i<4;i++){
      int tx=temp.x+to[i][0];
      int ty=temp.y+to[i][1];
      int ts=temp.speed;
      if(tx<0 || tx>=r || ty<0 || ty>=c) continue;
      if(G[tx][ty]=='#' || vis[tx][ty][temp.saved]) continue;
      if(!isupper(G[tx][ty])){
        q.push(Node(tx,ty,temp.step+temp.speed,temp.saved,ts));
        vis[tx][ty][temp.saved]=1;
      }else{
        q.push(Node(tx,ty,temp.step+temp.speed,temp.saved,ts));
        vis[tx][ty][temp.saved]=1;
        int num=G[tx][ty]-'A';
        //ts = (ts+speed[num]<1 ? 1 : ts+speed[num]);
        int tsaved=(temp.saved)|(1<<num);
        ts=ori_speed;
        for(int i=0;i<tot;i++) if(tsaved & (1<<i)) ts+=speed[i];
        ts = ts<1 ? 1 : ts;
        q.push(Node(tx,ty,temp.step+temp.speed,tsaved,ts));
#ifdef DEBUG
    printf("    push (%d,%d), step: %d, speed: %d, saved: %d, if saved: %c\n",tx,ty,temp.step+temp.speed,temp.speed,tsaved,num+'A');
#endif
        vis[tx][ty][tsaved]=1;
      }
    }
  }
  return -1;
}
