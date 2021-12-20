/*
描述
小城和小华都是热爱数学的好学生，最近，他们不约而同地迷上了数独游戏，好胜的他们想用数独来一比高低。但普通的数独对他们来说都过于简单了，于是他们向 Z博士请教，Z 博士拿出了他最近发明的“靶形数独” ，作为这两个孩子比试的题目。 
靶形数独的方格同普通数独一样，在 9 格宽×9 格高的大九宫格中有 9 个 3 格宽 × 3 格高的小九宫格（用粗黑色线隔开的） 。在这个大九宫格中，有一些数字是已知的，根据这些数字，利用逻辑推理，在其他的空格上填入 1到 9 的数字。每个数字在每个小九宫格内不能重复出现，每个数字在每行、每列也不能重复出现。但靶形数独有一点和普通数独不同，即每一个方格都有一个分值，而且如同一个靶子一样，离中心越近则分值越高。 （如图） 

6 6 6 6 6 6 6 6 6
6 7 7 7 7 7 7 7 6
6 7 8 8 8 8 8 7 6
6 7 8 9 9 9 8 7 6
6 7 8 9 10 9 8 7 6
6 7 8 9 9 9 8 7 6
6 7 8 8 8 8 8 7 6
6 7 7 7 7 7 7 7 6
6 6 6 6 6 6 6 6 6

上图具体的分值分布是：最里面一格（黄色区域）为 10 分，黄色区域外面的一圈（红色区域）每个格子为 9 分，再外面一圈（蓝色区域）每个格子为 8分，蓝色区域外面一圈（棕色区域）每个格子为 7分，最外面一圈（白色区域）每个格子为 6 分，如上图所示。比赛的要求是：每个人必须完成一个给定的数独（每个给定数独可能有不同的填法） ，而且要争取更高的总分数。而这个总分数即每个方格上的分值和完成这个数独时填在相应格上的数字的乘积的总和。如图，在以下的这个已经填完数字的靶形数独游戏中，总分数为 2829。游戏规定，将以总分数的高低决出胜负。 

7 5 4 9 3 8 2 6 1
1 2 8 6 4 5 9 3 7
6 3 9 2 1 7 4 8 5
8 6 5 4 2 9 1 7 3
9 7 2 3 5 1 6 4 8
4 1 3 8 7 6 5 2 9
5 4 7 1 8 2 3 9 6
2 9 1 7 6 3 8 5 4
3 8 6 5 9 4 7 1 2

由于求胜心切，小城找到了善于编程的你，让你帮他求出，对于给定的靶形数独，能够得到的最高分数。

格式
输入格式
一共 9 行。每行 9 个整数（每个数都在 0—9 的范围内） ，表示一个尚未填满的数独方格，未填的空格用“0”表示。每两个数字之间用一个空格隔开。

输出格式
输出可以得到的靶形数独的最高分数。如果这个数独无解，则输出整数-1。

样例1
样例输入1
7 0 0 9 0 0 0 0 1 
1 0 0 0 0 5 9 0 0 
0 0 0 2 0 0 0 8 0 
0 0 5 0 2 0 0 0 3 
0 0 0 0 0 0 6 4 8 
4 1 3 0 0 0 0 0 0 
0 0 7 0 0 2 0 9 0 
2 0 1 0 6 0 8 0 4 
0 8 0 5 0 4 0 1 2 

样例输出1
2829 

样例2
样例输入2
0 0 0 7 0 2 4 5 3 
9 0 0 0 0 8 0 0 0 
7 4 0 0 0 5 0 1 0 
1 9 5 0 8 0 0 0 0 
0 7 0 0 0 0 0 2 5 
0 3 0 5 7 9 1 0 8 
0 0 0 6 0 1 0 0 0 
0 6 0 9 0 0 0 0 1 
0 0 0 0 0 0 0 0 6 

样例输出2
2852

限制
每个测试点2s

提示
40%的数据，数独中非 0数的个数不少于 30。 
80%的数据，数独中非 0数的个数不少于 26。 
100%的数据，数独中非 0 数的个数不少于 24。

来源
NOIP 2009
*/

/*
  得分：55
  解题报告：
    贪心是错误的，但如果改为贪心+限制次数的搜索就好了一点。
      次数  得分
      80    55
      200   60
      500   65
      1000  70
      2000  70
      10000 65
    没有发现每个点有2s，所以只限制了80次。。。早知道就2000次了 XD

  正解：
*/












































/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[9][9],ansMax=-1;
int visR[9][10],visC[9][10],visB[9][10];
int to[81][2],block[9][9],score[9][9];
int maxTry=2000,curTry=0;

void init();
bool dfs(int x, int y, int cur);
inline int count();
bool debug_check();

int main(void){
  init();
  int t;
  for(int i=0;i<9;i++) for(int j=0;j<9;j++){
    scanf("%d",&t); a[i][j]=t;
    if(t) visR[i][t]=visC[j][t]=visB[block[i][j]][t]=1;
  }
#ifdef DEBUG
  printf("get:\n");
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++) printf("%d ",a[i][j]);
    printf("\n");
  }
#endif

  dfs(4,4,0);
  printf("%d\n",ansMax);

  return 0;
}

bool dfs(int x, int y, int cur){
  if(cur==81){
#ifdef DEBUG
    int cou=count();
    printf("try %d\n",curTry);
    if(cou>ansMax) printf("better res with cou: %d\n",cou);
    else printf("res with cout: %d\n",cou);
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) printf("%d ",a[i][j]);
        printf("\n");
      }
    if(!debug_check()) printf("*** WRONG ***\n");
#endif
    curTry++;
    ansMax=max(ansMax,count()); return curTry>=maxTry;
  }
  
  int tx=x+to[cur][0],ty=y+to[cur][1];
  if(a[x][y]) return dfs(tx,ty,cur+1);
  else for(int i=9;i>=1;i--) if(!visR[x][i] && !visC[y][i] && !visB[block[x][y]][i]){
    visR[x][i]=visC[y][i]=visB[block[x][y]][i]=1; a[x][y]=i;
    if(dfs(tx,ty,cur+1)) return true;
    visR[x][i]=visC[y][i]=visB[block[x][y]][i]=0; a[x][y]=0;
  }
  return false;
}
inline int count(){
  int sum=0;
  for(int i=0;i<9;i++) for(int j=0;j<9;j++) sum+=a[i][j]*score[i][j];
  return sum;
}
void init(){
  for(int i=0;i<81;i++){
    if((2<=i && i<=3) || (12<=i && i<=15) || (30<=i && i<=35) || (56<=i && i<=63)) to[i][0]=0,to[i][1]=-1;
    else if(i==0 || (6<=i && i<=8) || (20<=i && i<=24) || (42<=i && i<=48) || (72<=i && i<=80)) to[i][0]=0,to[i][1]=1;
    else if((4<=i && i<=5) || (16<=i && i<=19) || (36<=i && i<=41) || (64<=i && i<=71)) to[i][0]=-1,to[i][1]=0;
    else to[i][0]=1,to[i][1]=0;
  }

  for(int i=0;i<9;i++) for(int j=0;j<9;j++) block[i][j] = (i/3)*3+j/3;

  for(int i=0;i<9;i++) for(int j=0;j<9;j++){
    score[i][j]=6;
    if(i>=1 && i<=7 && j>=1 && j<=7) score[i][j]++;
    if(i>=2 && i<=6 && j>=2 && j<=6) score[i][j]++;
    if(i>=3 && i<=5 && j>=3 && j<=5) score[i][j]++;
    if(i==4 && j==4) score[i][j]++;
  }
}
bool debug_check(){
  memset(visR,0,sizeof(visR)); memset(visC,0,sizeof(visC)); memset(visB,0,sizeof(visB));
  for(int i=0;i<9;i++) for(int j=0;j<9;j++){
    int t=a[i][j];
    visR[i][t]=visC[j][t]=visB[block[i][j]][t]=1;
  }
  for(int i=0;i<9;i++) for(int j=1;j<=9;j++)
    if(!visR[i][j] || !visC[i][j] || !visB[i][j]) return false;
  return true;
}
*/
