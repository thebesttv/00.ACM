/*
描述
Mayan puzzle是最近流行起来的一个游戏。游戏界面是一个7行5列的棋盘，上面堆放着一些方块，方块不能悬空堆放，即方块必须放在最下面一行，或者放在其他方块之上。**游戏通关是指在规定的步数内消除所有的方块，**消除方块的规则如下：
1、每步移动可以且仅可以沿横向（即向左或向右）拖动某一方块一格：当拖动这一方块时，如果拖动后到达的位置（以下称目标位置）也有方块，那么这两个方块将交换位置（参见图6到图7）；如果目标位置上没有方块，那么被拖动的方块将从原来的竖列中抽出，并从目标位置上掉落（直到不悬空，参见图1和图2)；


      3
      4            3
      3            4
      4 2  ->    3 4 2  ->    3   2
    3 4 2        3 4 2        3 3 2
  1 1 2 1      1 1 2 1      1 1 2 1
    图1          图2          图3

2、任一时刻，如果在一横行或者竖列上有连续三个或者三个以上相同颜色的方块，则它们将立即被消除（参见图1到图3）。
注意：
a) 如果同时有多组方块满足消除条件，几组方块会同时被消除（例如下面图4，三个颜色为1的方块和三个颜色为2的方块会同时被消除，最后剩下一个颜色为2的方块）。
b) 当出现行和列都满足消除条件且行列共享某个方块时，行和列上满足消除条件的所有方块会被同时消除（例如下面图5所示的情形，5个方块会同时被消除）。

  2
  1             1
  1             1
  1 2 2 2     1 1 1
    图4        图5

3、方块消除之后，消除位置之上的方块将掉落，掉落后可能会引起新的方块消除。注意：掉落的过程中将不会有方块的消除。
上面图1到图3给出了在棋盘上移动一块方块之后棋盘的变化。棋盘的左下角方块的坐标为（0, 0），将位于（3, 3）的方块向左移动之后，游戏界面从图1变成图2所示的状态，此时在一竖列上有连续三块颜色为4的方块，满足消除条件，消除连续3块颜色为4的方块后，上方的颜色为3的方块掉落，形成图3所示的局面。

格式
输入格式
第一行为一个正整数n，表示要求游戏关的步数。
接下来的5行，描述7*5的游戏界面。每行若干个整数，每两个整数之间用一个空格隔开，每行以一个0 结束，自下向上表示每竖列方块的颜色编号（颜色不多于10种，从1开始顺序编号，相同数字表示相同颜色）。
输入数据保证初始棋盘中没有可以消除的方块。

输出格式
如果有解决方案，输出n行，每行包含3个整数x，y，g，表示一次移动，每两个整数之间用一个空格隔开，其中（x，y）表示要移动的方块的坐标，g表示移动的方向，1表示向右移动，-1表示向左移动。**注意：多组解时，按照x为第一关键字，y为第二关键字，1优先于-1，给出一组字典序最小的解。游戏界面左下角的坐标为(0, 0)。**
如果没有解决方案，输出一行，包含一个整数-1。

样例1
样例输入1
3
1 0
2 1 0
2 3 4 0
3 1 0
2 4 3 4 0

样例输出1
2 1 1
3 1 1
3 0 1

限制
3s

样例说明

            4              4              4
        4   3          4   3          4   3
      1 3 1 4  ->    1 1 3 4  ->    1 1 4 3
    1 2 2 3 2      1 2 2 3 2      1 2 2 3 2
    ---------      ---------      ---------
       图6            图7            图8
            4
        4   3
->    1 1 4 3  ->      4      ->
    1 2 2 2 4      1 1 1 4 4
    ---------      ---------      ---------
       图9            图10           图11


样例输入的游戏局面如图6到图11所示。依次移动的三步是：（2，1）处的方格向右移动，（3，1）处的方格向右移动，（3，0）处的方格向右移动，最后可以将棋盘上所有方块消除。
数据规模如下：
对于30%的数据，初始棋盘上的方块都在棋盘的最下面一行；
对于100%的数据，0 < n ≤ 5。

来源
NOIp2011提高组Day1第三题
*/

/*
  得分：60
  解题报告：
    比较复杂的暴力。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int G[5][7];
int save[5][3];
int n;

bool dfs(int step);
bool erase();
void pushDown();
bool isempty();
inline int get(int x, int y, bool type);
void DEBUG_print();

int main(void){
  scanf("%d",&n);
  
  //错误，如果有列正好有七个方块，那么输入中就有8个数（最后一个为0），而该方法会将最后一个0读到下一行去
  //for(int i=0;i<5;i++) for(int j=0;j<7;j++){
  //  scanf("%d",&G[i][j]); if(!G[i][j]) break;
  //}

  for(int i=0;i<5;i++){
    int tail=0,t=0;
    while(scanf("%d",&t)==1 && t) G[i][tail++]=t;
  }

  if(dfs(0)) for(int i=0;i<n;i++)
    if(save[i][2]) printf("%d %d %d\n",save[i][0],save[i][1],save[i][2]);
    else break;
  else printf("-1\n");

  return 0;
}

bool dfs(int step){
#ifdef DEBUG
  printf("def(%d)\n",step);
  DEBUG_print(); printf("\n");
#endif
  if(step==n) return isempty();

  bool flag=0;
  int temp[5][7]; memcpy(temp,G,sizeof(G));
  for(int i=0;i<5;i++) for(int j=0;j<7;j++)
    if(G[i][j]){
      //右
      if(i<4 && G[i][j]!=G[i+1][j]){ !flag ? flag=1 : 0 ;
        save[step][0]=i,save[step][1]=j,save[step][2]=1;
        swap(G[i][j],G[i+1][j]);
        pushDown();
        while(erase());
#ifdef DEBUG
        printf("move (%d,%d) right\n",i,j);
#endif
        if(dfs(step+1)) return true;
        memcpy(G,temp,sizeof(temp));
      }
      //左
      if(i>0 && G[i][j]!=G[i-1][j] && G[i-1][j]==0){ !flag ? flag=1 : 0 ;
        save[step][0]=i,save[step][1]=j,save[step][2]=-1;
        swap(G[i][j],G[i-1][j]);
        pushDown();
        while(erase());
#ifdef DEBUG
        printf("move (%d,%d) left\n",i,j);
#endif
        if(dfs(step+1)) return true;
        memcpy(G,temp,sizeof(temp));
      }
    }else break;
  save[step][0]=save[step][1]=save[step][2]=0;
  if(!flag) return dfs(n);
  return false;
}
bool erase(){
#ifdef DEBUG
  printf("  in erase()\n");
  DEBUG_print();
#endif
  bool flag=0;
  for(int i=0;i<5;i++) for(int j=0;j<7;j++) if(G[i][j] && get(i,j,0)>=3 && get(i,j,1)>=3){
    flag=1;
    int tx,ty;
    tx=i+1,ty=j;
    while(tx<5 && G[tx][ty]==G[i][j]) G[tx++][ty]=0;
    tx=i-1,ty=j;
    while(tx>=0 && G[tx][ty]==G[i][j]) G[tx--][ty]=0;
    tx=i,ty=j+1;
    while(ty<7 && G[tx][ty]==G[i][j]) G[tx][ty++]=0;
    tx=i,ty=j-1;
    while(ty>=0 && G[tx][ty]==G[i][j]) G[tx][ty--]=0;
    G[i][j]=0;
    break;
  }
  if(!flag){
    for(int j=0;j<7;j++) for(int i=0;i<3;i++) if(G[i][j] && G[i][j]==G[i+1][j] && G[i+1][j]==G[i+2][j]){
      flag=1;
      int tx=i+1,ty=j;
      while(tx<5 && G[tx][ty]==G[i][j]) G[tx++][ty]=0;
      G[i][j]=0;
      break;
    }
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(G[i][j] && G[i][j]==G[i][j+1] && G[i][j+1]==G[i][j+2]){
      flag=1;
      int tx=i,ty=j+1;
      while(ty<7 && G[tx][ty]==G[i][j]) G[tx][ty++]=0;
      G[i][j]=0;
    }
  }
#ifdef DEBUG
  if(flag) printf("  successfully erased\n");
#endif
  pushDown();
  return flag;
}
inline void pushDown(){
  int temp[5][7]; memset(temp,0,sizeof(temp));
  for(int i=0;i<5;i++){
    int tail=0;
    for(int j=0;j<7;j++) if(G[i][j]) temp[i][tail++]=G[i][j];
  }
  memcpy(G,temp,sizeof(temp));
}
inline bool isempty(){
  for(int i=0;i<5;i++) for(int j=0;j<7;j++) if(G[i][j]) return false;
  return true;
}
inline int get(int x, int y, bool type){
  if(!G[x][y]) return 0;
  int cnt=1;
  int tx,ty;
  if(type==0){
    tx=x+1,ty=y;
    while(tx<5 && G[tx][ty]==G[x][y]) tx++,cnt++;
    tx=x-1,ty=y;
    while(tx>=0 && G[tx][ty]==G[x][y]) tx--,cnt++;
  }else{
    tx=x,ty=y+1;
    while(ty<7 && G[tx][ty]==G[x][y]) ty++,cnt++;
    tx=x,ty=y-1;
    while(ty>=0 && G[tx][ty]==G[x][y]) ty--,cnt++;
  }
  return cnt;
}
void DEBUG_print(){
  for(int j=6;j>=0;j--){
    for(int i=0;i<5;i++) printf("%d ",G[i][j]);
    printf("\n");
  }
}
