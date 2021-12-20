/*
题目背景
毒奶色和F91是好朋友。

题目描述
他们经常在一起玩一个游戏，不，不是星际争霸，是国际象棋。
毒奶色觉得F91是一只鸡。他在一个n×n的棋盘上用黑色的城堡（车）、骑士（马）、主教（象）、皇后（副）、国王（帅）、士兵（卒）摆了一个阵。
然而F91觉得毒奶色是一只鸡。他发起了挑战：他要操纵一个白色骑士，不经过任何一个棋子的攻击范围（F91可以连续行动，而毒奶色的棋子不会动，除非白骑士进入了对方的攻击范围），并击杀毒奶色的国王（即进入黑国王所在的位置）。
请告诉F91他最少需要多少步骤来完成这一项壮举。

注意：
1.当F91的白骑士走到毒奶色的棋子所在的格子上的时候，会击杀（吃掉）该棋子。这个棋子也就不再对F91的白骑士有威胁了。
2.如果白骑士开场就在黑子的攻击范围内，则立刻被击杀、F91立刻失败。
3.即使白骑士在攻击王的瞬间进入了其他棋子攻击范围（即其他棋子“看护”着王所在的格子），依然算F91获胜。

攻击范围：
城堡：横、竖方向所有位置，直到被一个其他棋子阻拦。
  ..#..
  ..#..
  ##C##
  ..#..
  ..#..

骑士：横2竖1或者横1竖2的所有位置（最多8个，类似日字）。
  .#.#.
  #...#
  ..K..
  #...#
  .#.#.

主教：斜向（45°）所有位置，直到被一个其他棋子阻拦。
  #...#
  .#.#.
  ..B..
  .#.#.
  #...#

皇后：城堡和主教的结合体（既能横/竖向攻击，也能45°角斜向攻击，直到被其他棋子阻挡）。
  #.#.#
  .###.
  ##Q##
  .###.
  #.#.#

国王：身边8连通位置的8个格子。
  .....
  .###.
  .#X#.
  .###.
  .....

士兵：左下方/右下方（45°）的格子（最多2个）。
  .....
  .....
  ..P..
  .#.#.
  .....

其中字母表示棋子类型，参考输入格式。
‘#’表示可攻击范围。

输入输出格式
输入格式：
输入包含多组数据。
每一组数据中，第一行一个整数n表示棋盘规模。
接下来n行，每行一个长度为n的字符串。描述棋盘的格局。
其中：
  . 表示空
  O 表示白骑士
  C 表示黑城堡
  K 表示黑骑士
  B 表示黑主教
  Q 表示黒皇后
  X 表示黑国王
  P 表示黑士兵
  
输出格式：
对于每一个测试数据，每行输出一个整数，表示F91的最小步数。
如果无论F91如何行动也无法击杀黑国王，输出-1。

输入输出样例
输入样例#1：
8
...X....
........
........
........
........
........
........
......O.

输出样例#1：
4

输入样例#2：
8
......X.
........
.O......
...P.Q.C
.....B..
........
...K....
........

输出样例#2：
7

说明
输入最多包含5组数据。
对于20%的数据，毒奶色只有国王。n <= 8。
对于30%的数据，毒奶色只有国王、骑士。n <= 8。
对于60%的数据，毒奶色只有国王、骑士、王后。n <= 50。
对于100%的数据，毒奶色可以有全套16颗棋子（2城堡，2骑士，2主教，1后，1王，8兵）。n <= 50。

温馨提示：
时间限制可能比想象之中还要更紧一点，请注意实现细节以保证性能。

样例2解释：
一种可行的做法是：
......X.
.3..6...
.O5.....
4.2P.Q.C
1....B..
........
...K....
........
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=62;
int n,ori[MAX][MAX],tmp[MAX][MAX];
bool G[1<<16][MAX][MAX];  //每种状态的地图
bool vis[1<<16][MAX][MAX],visG[1<<16];
struct Node{
  int x,y;
  int step,st;
};
char t1[MAX];
int to[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
struct Ind{
  int x,y;
}ind[20];
//ori[i][j]==-1表示空地，其余与st同步

//st: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
//    K  K  Q  C  C  B  B  P  P  P  P  P  P  P  P 空  X
void setG(int st);  //生成地图
void setK(int st, int x, int y);  //生成骑士攻击范围
void setC(int st, int x, int y);  //生成城堡攻击范围
void setB(int st, int x, int y);  //生成主教攻击范围
void DEBUG_PRINT(int n){
  FOR(i,0,15) printf("%d",(n>>i)&1);
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(ori,0); MST(vis,0); MST(visG,0); MST(ind,0);
    int sx,sy,ex,ey,ost=0,cntP=0;
    FOR(i,0,n){
      scanf("%s",t1);
      FOR(j,0,n){
        int ch=t1[j],t=-1;
        switch(ch){
          case '.': t=-1; break;
          case 'O': t=-1; sx=i,sy=j; break;
          case 'C': t=(ost>>3)&1 ? 4 : 3;  break;
          case 'K': t=(ost>>0)&1 ? 1 : 0; break;
          case 'B': t=(ost>>5)&1 ? 6 : 5; break;
          case 'Q': t=2; break;
          case 'X': t=16; ex=i,ey=j; break;
          case 'P': t=7+cntP; cntP++; break;
        }
        ori[i][j]=t;
        if(t!=-1) {ind[t].x=i,ind[t].y=j; ost|=1<<t;}
      }
    }
    ost^=1<<16; //去掉黑国王的状态
#ifdef DEBUG
    printf("  s(%d,%d), e(%d,%d)\n",sx,sy,ex,ey);
    printf("ori: ost: "); DEBUG_PRINT(ost); printf("\n");
    FOR(i,0,n){
      FOR(j,0,n)
        if(ori[i][j]==-1) printf("--");
        else printf("%2d",ori[i][j]);
      printf("\n");
    }
    FOR(i,0,15) if((ost>>i)&1)
      printf("ind[%d]: (%d,%d)\n",i,ind[i].x,ind[i].y);
#endif

    setG(ost);
    int ans=-1;
    if(G[ost][sx][sy]) {printf("-1\n"); continue;}
    queue<Node> q;
    q.push((Node){sx,sy,0,ost}); vis[ost][sx][sy]=1;
    while(!q.empty()){
      Node t=q.front(); q.pop();
      int x=t.x,y=t.y;
      FOR(dir,0,8){
        int tx=x+to[dir][0],ty=y+to[dir][1];
        int st=t.st;
        if(tx<0 || tx>=n || ty<0 || ty>=n || vis[st][tx][ty]) continue;
        if(G[st][tx][ty]) continue; //如果进入攻击范围
        if(ori[tx][ty]!=-1 && (st>>ori[tx][ty])&1){
          st^=1<<ori[tx][ty]; setG(st);
          if(G[st][tx][ty]) continue; //XXX
        }
        vis[st][tx][ty]=1;
        if(tx==ex && ty==ey) {ans=t.step+1; goto PRINT;}
        q.push((Node){tx,ty,t.step+1,st});
#ifdef DEBUG
        printf("node (%d,%d), step: %d, st:",tx,ty,t.step+1); DEBUG_PRINT(st); printf("\n");
        FOR(i,0,n){
          FOR(j,0,n)
            if(i==tx && j==ty) printf("**");
            else if(G[st][i][j]) printf("!!");
            else if(ori[i][j]!=-1 && (st>>ori[i][j])&1) printf("%2d",ori[i][j]);
            else printf("--");
          printf("\n");
        }
#endif
      }
    }
PRINT:
    printf("%d\n",ans);
  }

  return 0;
}

//st: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14   16
//    K  K  Q  C  C  B  B  P  P  P  P  P  P  P  P    X
void setG(int st){
  if(visG[st]) return;
  visG[st]=1; MST(tmp,-1);
  FOR(i,0,15) if((st>>i)&1) //在tmp中放子
    tmp[ind[i].x][ind[i].y]=i;

  //K
  FOR(i,0,2) if((st>>i)&1){
    int x=ind[i].x,y=ind[i].y;
    setK(st,x,y);
  }
  //Q
  if((st>>2)&1){
    int x=ind[2].x,y=ind[2].y;
    setC(st,x,y); setB(st,x,y);
  }
  //C
  FOR(i,3,5) if((st>>i)&1){
    int x=ind[i].x,y=ind[i].y;
    setC(st,x,y);
  }
  //B
  FOR(i,5,7) if((st>>i)&1){
    int x=ind[i].x,y=ind[i].y;
    setB(st,x,y);
  }
  //P
  FOR(i,7,15) if((st>>i)&1){
    int x=ind[i].x,y=ind[i].y;
    if(x+1>=n) continue;
    if(y) G[st][x+1][y-1]=1;
    if(y+1<n) G[st][x+1][y+1]=1;
  }
  //X
  int x=ind[16].x,y=ind[16].y;
  FORR(i,-1,1) FORR(j,-1,1)
    if(x+i>=0 && x+i<n && y+j>=0 && y+j<n) G[st][x+i][y+j]=1;
  G[st][x][y]=0;

#ifdef DEBUG
  printf("setG("); DEBUG_PRINT(st); printf(")\n");
  FOR(i,0,n){
    FOR(j,0,n) printf("%d",G[st][i][j]);
    printf("\n");
  }
#endif
}
void setK(int st, int x, int y){
  FOR(dir,0,8){
    int tx=x+to[dir][0],ty=y+to[dir][1];
    if(tx<0 || tx>=n || ty<0 || ty>=n) continue;
    G[st][tx][ty]=1;
  }
}
void setC(int st, int x, int y){
  for(int tx=x,ty=y-1;ty>=0 && tmp[tx][ty]==-1;ty--)
    G[st][tx][ty]=1;
  for(int tx=x,ty=y+1;ty<n  && tmp[tx][ty]==-1;ty++)
    G[st][tx][ty]=1;
  for(int tx=x-1,ty=y;tx>=0 && tmp[tx][ty]==-1;tx--)
    G[st][tx][ty]=1;
  for(int tx=x+1,ty=y;tx<n  && tmp[tx][ty]==-1;tx++)
    G[st][tx][ty]=1;
}
void setB(int st, int x, int y){
  int tx,ty;
  for(int tx=x-1,ty=y-1;tx>=0 && ty>=0 && tmp[tx][ty]==-1;tx--,ty--)
    G[st][tx][ty]=1;
  for(int tx=x-1,ty=y+1;tx>=0 && ty<n  && tmp[tx][ty]==-1;tx--,ty++)
    G[st][tx][ty]=1;
  for(int tx=x+1,ty=y-1;tx<n  && ty>=0 && tmp[tx][ty]==-1;tx++,ty--)
    G[st][tx][ty]=1;
  for(int tx=x+1,ty=y+1;tx<n  && ty<n  && tmp[tx][ty]==-1;tx++,ty++)
    G[st][tx][ty]=1;
}
