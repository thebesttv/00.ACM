/*
描述
蒜头君最近迷上了打地鼠，但他发现同时出现在面板上的地鼠太多，于是他想改进一下他的锤子，于是他拿出了一款 k*k 大小的正方形锤子，但是遗憾的是，这个锤子只能斜着砸。如下图所示：
当 k=2 时，锤子的图案如下所示：

  -*-
  *X*
  -*-

当 k=3 时，锤子的图案如下所示：

  - - * - -
  - * * * -
  * * x * *
  - * * * -
  - - * - -

k 取其他值时以此类推。
注意：蒜头君只能敲击面板上的格子，但锤子不一定要全部落在面板内。
现在给定一个 n*n 的面板，每个格子可能有地鼠也可能没有地鼠，请编程计算用 k*k 大小锤子敲击时最多能打中多少地鼠。

输入格式
第一行 2 个整数 n,k，表示面板大小和锤子大小。
接下来 n 行，每行 n 个整数，若为 1 代表该格子有地鼠，若为 0 代表该格子无地鼠。不会出现其他的数字。

输出格式
输出一个整数，代表最多能砸到的地鼠数。

样例输入
3 2
0 1 1
1 0 1
0 1 0

样例输出
4

数据规模
对于 50% 的测试数据，满足 1≤n≤300,1≤k≤10
对于 80% 的测试数据，满足 1≤n≤2000,1≤k≤10
对于 100% 的测试数据，满足 1≤n≤2000,1≤k≤100

样例说明
敲击第 2 行的 0，可以敲到周围的 4 个地鼠。
*/

/*
  得分：80分
  解题报告：
  较难的模拟题，难度在数据范围和锤子的模拟上。
  一开始考虑直接模拟，对每个点(i,j)计算能打到的地鼠。在j移动时可以减去锤子左边，加上锤子右边，减少运算量，但考虑到数据范围，放弃。也考虑过使用S[i][j]记录每一列的前j个的地鼠数，但没有采用。
  后来，想到通过每一个地鼠来更新地图，而非对每个地图上的点计算地鼠数。读入时，只关注有地鼠的点，记录其座标。然后，对每个座标，对能打到它的范围都加1，并同时维护最大值，最后答案即为最大值。
  可以在地图外再增加100层0，避免锤子范围的边界判断。
  第一次提交，可能因为Node开小了，只有50分，改进后得80分。
 */
#include<iostream>
#include<cstdio>
using namespace std;

#define MAX(x,y) (x)>(y) ? (x) : (y)

int G[2220][2220];
struct Node{
  int x,y;
}mouse[10000000];
int n,k,tail=0;

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&k);
  unsigned int a;
  n+=100;
  for(register int i=100;i<n;++i) for(register int j=100;j<n;++j){
    scanf("%u",&a);
    if(a) {mouse[tail].x=i,mouse[tail].y=j; ++tail;}
  }
  register int ansMax=0;
  register int x,y;
  for(register int m=0;m<tail;++m){
    for(register int i=1-k;i<=0;++i) for(register int j=1-k-i;j<=k+i-1;++j){
      x=mouse[m].x+i,y=mouse[m].y+j;
      ++G[x][y]; G[x][y]>ansMax ? ansMax=G[x][y] : 0;
      //ansMax=MAX(G[x][y],ansMax);
    }
    for(register int i=1;i<=k-1;++i) for(register int j=i+1-k;j<=k-i-1;++j){
      x=mouse[m].x+i,y=mouse[m].y+j;
      ++G[x][y]; G[x][y]>ansMax ? ansMax=G[x][y] : 0;
      //ansMax=MAX(G[x][y],ansMax);
    }
  }
#ifdef DEBUG
  n-=100;
  for(int i=100;i<n+100;++i){
    for(int j=100;j<n+100;++j) printf("%d ",G[i][j]);
    printf("\n");
  }
  n+=100;
#endif
  printf("%d\n",ansMax);

  return 0;
}
