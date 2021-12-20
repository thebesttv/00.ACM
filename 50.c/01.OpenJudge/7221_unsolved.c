/*
描述
多灾多难的公主又被大魔王抓走啦！国王派遣了第一勇士阿福去拯救她。
身为超级厉害的术士，同时也是阿福的好伙伴，你决定祝他一臂之力。你为阿福提供了一张大魔王根据地的地图，上面标记了阿福和公主所在的位置，以及一些不能够踏入的禁区。你还贴心地为阿福制造了一些传送门，通过一个传送门可以瞬间转移到任意一个传送门，当然阿福也可以选择不通过传送门瞬移。传送门的位置也被标记在了地图上。此外，你还查探到公主所在的地方被设下了结界，需要集齐K种宝石才能打开。当然，你在地图上也标记出了不同宝石所在的位置。
你希望阿福能够带着公主早日凯旋。于是在阿福出发之前，你还需要为阿福计算出他最快救出公主的时间。
地图用一个R×C的字符矩阵来表示。字符S表示阿福所在的位置，字符E表示公主所在的位置，字符#表示不能踏入的禁区，字符$表示传送门，字符.表示该位置安全，数字字符0至4表示了宝石的类型。阿福每次可以从当前的位置走到他上下左右四个方向上的任意一个位置，但不能走出地图边界。阿福每走一步需要花费1个单位时间，从一个传送门到达另一个传送门不需要花费时间。当阿福走到宝石所在的位置时，就视为得到了该宝石，不需要花费额外时间。

输入
第一行是一个正整数T（1 <= T <= 10），表示一共有T组数据。
每一组数据的第一行包含了三个用空格分开的正整数R、C（2 <= R, C <= 200）和K，表示地图是一个R×C的矩阵，而阿福需要集齐K种宝石才能够打开拘禁公主的结界。
接下来的R行描述了地图的具体内容，每一行包含了C个字符。字符含义如题目描述中所述。保证有且仅有一个S和E。$的数量不超过10个。宝石的类型在数字0至4范围内，即不会超过5种宝石。

输出
对于每一组数据，输出阿福救出公主所花费的最少单位时间。若阿福无法救出公主，则输出“oop!”（只输出引号里面的内容，不输出引号）。每组数据的输出结果占一行。

样例输入
1
7 8 2
........
..S..#0.
.##..1..
.0#.....
...1#...
...##E..
...1....

样例输出
11
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

char G[220][220];
int vis[220][220][1<<6],r,c,k;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node{
  int x,y;
  int step,jew;

  Node(): x(0), y(0), step(0), jew(0) { }
  Node(int x_, int y_, int step_, int jew_): x(x_), y(y_), step(step_), jew(jew_) { }
  int countJew(){
    int cnt=0;
    for(int i=0;i<5;i++) if(jew & (1<<i)) cnt++;
    return cnt;
  }
}tp[20];
int doors;
queue<Node> q;

int bfs(int startx, int starty);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    memset(G,0,sizeof(G)); memset(vis,0,sizeof(vis)); memset(tp,0,sizeof(tp)); doors=0; while(!q.empty()) q.pop();
    scanf("%d%d%d",&r,&c,&k);
    int ch,startx,starty;
    for(int i=0;i<r;i++){
      getchar();
      for(int j=0;j<c;j++){
        G[i][j]=ch=getchar();
        if(ch=='$'){
          tp[doors++]=Node(i,j,0,0);
        }else if(ch=='S'){
          startx=i; starty=j;
        }
      }
    }
#ifdef DEBUG
    printf("get:\n");
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++) putchar(G[i][j]); putchar('\n');
    }
    printf("doors: %d\n",doors);
    for(int i=0;i<doors;i++) printf("(%d,%d),",tp[i].x,tp[i].y); printf("\n");
#endif
    int ans=bfs(startx,starty);
    if(ans==-1) printf("oop!\n");
    else printf("%d\n",ans);
  }

  return 0;
}

int bfs(int startx, int starty){
  q.push(Node(startx,starty,0,0));
  vis[startx][starty][0]=1;
  while(!q.empty()){
    Node temp=q.front(); q.pop();
    //if(G[temp.x][temp.y]=='E' && temp.countJew()>=k) return temp.step;
#ifdef DEBUG
    printf("  (%d,%d), step: %d, jew: %d\n",temp.x,temp.y,temp.step,temp.countJew());
#endif
    if(G[temp.x][temp.y]=='E' && temp.jew==(1<<k)-1) return temp.step;
    for(int i=0;i<4;i++){
      int tx=temp.x+to[i][0];
      int ty=temp.y+to[i][1];
      int tjew=temp.jew;
      if(tx<0 || tx>=r || ty<0 || ty>=c) continue;
      if(G[tx][ty]>='0' && G[tx][ty]<='4') tjew|=(1<<(G[tx][ty]-'0'));
      if(G[tx][ty]!='#' && !vis[tx][ty][tjew]){
        if(G[tx][ty]!='$'){
          q.push(Node(tx,ty,temp.step+1,tjew));
          vis[tx][ty][tjew]=1;
        }else{
          for(int j=0;j<doors;j++){
            q.push(Node(tp[j].x,tp[j].y,temp.step+1,tjew)); //<b>应为temp.step+1，因为从temp走了一步后才到门</b>
#ifdef DEBUG
            printf("  push doors: (%d,%d)\n",tp[j].x,tp[j].y);
#endif
            vis[tp[j].x][tp[j].y][tjew]=1;
          }
        }
      }
    }
  }
  return -1;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int VISITED=1<<5;
char G[220][220];
int vis[220][220],r,c,k;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node{
  int x,y;
  int step,jew;

  Node(): x(0), y(0), step(0), jew(0) { }
  Node(int x_, int y_, int step_, int jew_=VISITED): x(x_), y(y_), step(step_), jew(jew_|VISITED) { }
  int countJew(){
    int cnt=0;
    for(int i=0;i<5;i++) if(jew & (1<<i)) cnt++;
    return cnt;
  }
}tp[20];
int doors;
queue<Node> q;

int bfs(int startx, int starty);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    memset(G,0,sizeof(G)); memset(vis,0,sizeof(vis)); memset(tp,0,sizeof(tp)); doors=0; while(!q.empty()) q.pop();
    scanf("%d%d%d",&r,&c,&k);
    int ch,startx,starty;
    for(int i=0;i<r;i++){
      getchar();
      for(int j=0;j<c;j++){
        G[i][j]=ch=getchar();
        if(ch=='$'){
          tp[doors++]=Node(i,j,0,0);
        }else if(ch=='S'){
          startx=i; starty=j;
        }
      }
    }
#ifdef DEBUG
    printf("get:\n");
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++) putchar(G[i][j]); putchar('\n');
    }
#endif
    int ans=bfs(startx,starty);
    if(ans==-1) printf("oop!\n");
    else printf("%d\n",ans);
  }

  return 0;
}

int bfs(int startx, int starty){
  q.push(Node(startx,starty,0,VISITED));
  vis[startx][starty]=VISITED;
  while(!q.empty()){
    Node temp=q.front(); q.pop();
    int x=temp.x, y=temp.y;
#ifdef DEBUG
    printf("  (%d,%d), step: %d, jew: %d\n",x,y,temp.step,temp.countJew());
#endif
    if(G[x][y]=='E' && temp.countJew()>=k) return temp.step;
    for(int i=0;i<4;i++){
      int tx=x+to[i][0];
      int ty=y+to[i][1];
      if(tx<0 || tx>r-1 || ty<0 || ty>c-1) continue;
      Node t(tx,ty,temp.step+1,temp.jew);
      if(G[tx][ty]>='0' && G[tx][ty]<='4'){
        t.jew|=(1<<(G[tx][ty]-'0'));
      }
      if(G[tx][ty]=='#' || vis[tx][ty]==t.jew) continue;
      vis[tx][ty]=temp.jew;
      q.push(t);
      if(G[tx][ty]=='$'){
        for(int i=0;i<doors;i++){
          int tx_=tp[i].x,ty_=tp[i].y;
          if(tx_==tx && ty_==ty) continue;
          if(vis[tx_][ty_]==t.jew) continue;
          vis[tx_][ty_]=t.jew;
          q.push(Node(tx_,ty_,t.step,t.jew));
        }
      }
    }
  }
  return -1;
}
*/
