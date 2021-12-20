/*
背景
Flappy Bird 是一款风靡一时的休闲手机游戏。玩家需要不断控制点击手机屏幕的频率来调节小鸟的飞行高度，让小鸟顺利通过画面右方的管道缝隙。如果小鸟一不小心撞到了水管或者掉在地上的话，便宣告失败。

描述
为了简化问题，我们对游戏规则进行了简化和改编：
游戏界面是一个长为 n，高为 m 的二维平面，其中有k 个管道（忽略管道的宽度）。
小鸟始终在游戏界面内移动。小鸟从游戏界面最左边 任意整数高度位置出发，到达游戏界面最右边时，游戏完成。
小鸟每个单位时间沿横坐标方向右移的距离为 1，竖直移动的距离由玩家控制。如果点击屏幕，小鸟就会上升一定高度 X，每个单位时间可以点击多次，效果叠加； 如果不点击屏幕，小鸟就会下降一定高度 Y。小鸟位于横坐标方向不同位置时，上 升的高度 X 和下降的高度 Y 可能互不相同。
小鸟高度等于 0 或者小鸟碰到管道时，游戏失败。小鸟高度为 m 时，无法再上升。
现在，请你判断是否可以完成游戏。如果可以，输出最少点击屏幕数；否则，输出小鸟最多可以通过多少个管道缝隙。

格式
输入格式
第 1 行有 3 个整数 n，m，k，分别表示游戏界面的长度，高度和水管的数量，每两个 整数之间用一个空格隔开；
接下来的 n 行，每行 2 个用一个空格隔开的整数 X 和 Y，依次表示在横坐标位置 0~n-1 上玩家点击屏幕后，小鸟在下一位置上升的高度 X，以及在这个位置上玩家不点击屏幕时， 小鸟在下一位置下降的高度 Y。
接下来 k 行，每行 3 个整数 P，L，H，每两个整数之间用一个空格隔开。每行表示一个管道，其中 P 表示管道的横坐标，L 表示此管道缝隙的下边沿高度为 L，H 表示管道缝隙上边沿的高度（输入数据保证 P 各不相同，但不保证按照大小顺序给出）。

输出格式
共两行。
第一行，包含一个整数，如果可以成功完成游戏，则输出 1，否则输出 0。 第二行，包含一个整数，如果第一行为 1，则输出成功完成游戏需要最少点击屏幕数，否则，输出小鸟最多可以通过多少个管道缝隙。

样例1
样例输入1
10 10 6
3 9
9 9
1 2
1 3
1 2
1 1
2 1
2 1
1 6
2 2
1 2 7
5 1 5
6 3 5
7 5 8
8 7 9
9 1 3

样例输出1
1
6

样例2
样例输入2
10 10 4
1 2
3 1
2 2
1 8
1 8
3 2
2 1
2 1
2 2
1 2
1 0 2
6 7 9
9 1 4
3 8 10

样例输出2
0
3

限制
对于30%的数据:  5≤n≤10, 5≤m≤10, k=0，保证存在一组最优解使得同一单位时间最多点击屏幕 3 次；
对于50%的数据:  5≤n≤20, 5≤m≤10, 保证存在一组最优解使得同一单位时间最多点击屏幕 3 次；
对于70%的数据:  5≤n≤1000, 5≤m≤100；
对于100%的数据: 5≤n≤10000, 5≤m≤1000，0≤k<n，0<X<m，0<Y<m，0<P<n，0≤L<H ≤m，L+1<H。

提示
如下图（图在目录下）所示，蓝色直线表示小鸟的飞行轨迹，红色直线表示管道。

来源
NOIP2014 提高组 Day1
*/

/*
  得分：85
  解题报告：
    称不能碰到的点（包括底部和管子所在点）为非法点。
    动规，令 f(x,y) 表示从起点到达(x,y)的最小点击次数，则可以用每个f(x,y)对其他状态更新：
      f(x,y)+k -> f(x+1,y+k*X[x])
      f(x,y) -> f(x+1,y-Y[x])
    但还需优化才能AC。
  正解：
    仔细分析，可以发现：往上走实质上是完全背包，往下走是01背包，那么就可以在O(n*m)的时间内完成。
    但要注意，背包时要先完全背包（不考虑(x,y)是否非法），再01背包（同样），最后判断非法解。
    为什么要先完全再01最后删除非法点？
      因为在完全背包的时候，如果先判断了不合法的点(x,y)并且不对其更新，那么在(x,y)之后的点（即(x,y)上方的点）无法通过(x,y)被更新，那么就可能导致之后点的f变大。
      而如果先进行01背包，再进行完全背包，那么在完全背包时的点(x,y)可能由之前已被01背包更新过的点再次更新，就会导致(x-1,y+Y[x-1])向下的效果和(x-1,y-k*X[x-1])向上的效果叠加，当前点即之后点的f可能会变小。
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

const int MAXN=10020;
const int MAXM=1020;
const int MAXK=10020;
const int INF=0x3f3f3f3f;

bool ill[MAXN][MAXM]; //(i,j) which has pipe or at the bottom
int f[MAXN][MAXM],n,m,k;
  //f[i][j]: the min k to reach (i,j)
  //f[i][j] = min{ f[i-1][j-k*x[i]]+k, f[i-1][j+Y[i]] }
int X[MAXN],Y[MAXN];
int sum[MAXN];  //sum[i]: sum of pipe from x[0:i]

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  //FOR(i,0,n) scanf("%d%d",&X[i],&Y[i]);
  FORR(i,1,n) scanf("%d%d",&X[i],&Y[i]);
  for(int i=0,p,l,h;i<k;i++){ //input pipe
    scanf("%d%d%d",&p,&l,&h);
    FORR(j,0,l) ill[p][j]=1;
    FORR(j,h,m) ill[p][j]=1;
    sum[p]++;
  }
  FORR(i,1,n) sum[i]+=sum[i-1]; //calculate sum
  FORR(i,0,n) ill[i][0]=1;  //set bottom as illegal

  int cur=0;
  MST(f,0x3f); FORR(i,0,m) f[0][i]=0; //init start point
  FORR(i,1,n){
    /*
    ROR(j,m-Y[i],1) if(!ill[i][j]){
      f[i][j] = min(f[i][j], f[i-1][j+Y[i]]);
      //printf(" f[%d][%d] updated by f[%d][%d]: %d\n",i,j,i-1,j+Y[i],f[i-1][j+Y[i]]);
    }

    FORR(j,X[i]+1,m) if(!ill[i][j]){ //press
      f[i][j] = min(f[i][j], min(f[i-1][j-X[i]],f[i][j-X[i]])+1);
      //printf(" f[%d][%d] updated by f[%d][%d]: %d, f[%d][%d]: %d\n",i,j,i-1,j-X[i],f[i-1][j-X[i]],i,j-X[i],f[i][j-X[i]]);
    }
    if(!ill[i][m]) FORR(j,m-X[i]+1,m){ //高处点击特判
      f[i][m] = min(f[i][m], min(f[i-1][j],f[i][j])+1);
      //printf(" f[%d][%d] updated by f[%d][%d]: %d, f[%d][%d]: %d\n",i,j,i-1,j,f[i-1][j],i,j,f[i][j]);
    }
    */

    //完全背包
    FORR(j,X[i]+1,m){ //press
      f[i][j] = min(f[i][j], min(f[i-1][j-X[i]],f[i][j-X[i]])+1);
    }
    FORR(j,m-X[i]+1,m){ //高处点击特判
      f[i][m] = min(f[i][m], min(f[i-1][j],f[i][j])+1);
    }

    //01背包
    ROR(j,m-Y[i],1){
      f[i][j] = min(f[i][j], f[i-1][j+Y[i]]);
    }

    //判断非法点
    FORR(j,0,m) if(ill[i][j]) f[i][j]=INF;

    bool ok=0;
    FORR(j,1,m) if(f[i][j]<INF) {ok=1; break;}
    if(!ok) break;
    cur++;
  }
#ifdef DEBUG
  FORR(i,0,n) FORR(j,0,m) if(f[i][j]<INF)
    printf("  f[%d][%d]: %d\n",i,j,f[i][j]);
#endif
  if(cur<n){
    printf("%d\n%d\n",0,sum[cur]);
  }else{
    int ansMin=INF;
    FORR(i,1,m) ansMin=min(ansMin,f[n][i]);
    printf("%d\n%d\n",1,ansMin);
  }

  return 0;
}

/*
const int MAXN=10020;
const int MAXM=1020;
const int MAXK=10020;
const int INF=0x3f3f3f3f;

bool ill[MAXN][MAXM]; //(i,j) which has pipe or at the bottom
int f[MAXN][MAXM],n,m,k;
  //f[i][j]: the min k to reach (i,j)
  //f[i][j]+k -> f[i+1][j+k*[i]], if (i+1,j+k*[i]) is available
int X[MAXN],Y[MAXN];
int sum[MAXN];  //sum[i]: sum of pipe from x[0:i]

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  FOR(i,0,n) scanf("%d%d",&X[i],&Y[i]);
  for(int i=0,p,l,h;i<k;i++){ //input pipe
    scanf("%d%d%d",&p,&l,&h);
    FORR(j,0,l) ill[p][j]=1;
    FORR(j,h,m) ill[p][j]=1;
    sum[p]++;
  }
  FORR(i,1,n) sum[i]+=sum[i-1]; //calculate sum
  FORR(i,0,n) ill[i][0]=1;  //set bottom as illegal

#ifdef DEBUG
  printf("ill:\n");
  ROR(j,m,0){
    printf("  ");
    FORR(i,0,n) printf("%d",ill[i][j]);
    printf("\n");
  }
  printf("\n");
#endif

  MST(f,0x3f); FORR(i,0,m) f[0][i]=0; //init start point
  int curMax=0; //the max x that's updated
  FOR(i,0,n) FORR(j,1,m) if(!ill[i][j] && f[i][j]<INF){
    //not press
    int h=j-Y[i];
    if(h>0 && !ill[i+1][h]) f[i+1][h]=min(f[i+1][h],f[i][j]),curMax=i+1;

    //press
    //if(!X[i]) continue;
    h=j; int cnt=0;
    for(int k=1;;k++){
      h+=X[i];
      if(h>=m){  //XXX
        cnt++;
        if(cnt>1) break;
      }
      h=min(h,m);
      if(!ill[i+1][h]) f[i+1][h]=min(f[i+1][h],f[i][j]+k),curMax=i+1;
    }
  }
#ifdef DEBUG
  FORR(i,0,n) FORR(j,0,m) if(f[i][j]!=INF) printf("  f[%d][%d]: %d\n",i,j,f[i][j]);
  printf("  curMax: %d\n",curMax);
#endif

  int ansMin=INF;
  if(curMax==n){  //can make it
    FORR(i,1,m) ansMin=min(ansMin,f[n][i]);
    printf("%d\n%d\n",1,ansMin);
  }else{  //can't make it
    int u=-1;
    ROR(i,curMax,0){
      FORR(j,1,m) if(f[i][j]<INF) {u=i; break;}
      if(u!=-1) break;
    }
    printf("%d\n%d\n",0,sum[u]);
  }

  return 0;
}
*/
