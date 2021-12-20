/*
描述
无向图最短路径问题，是图论中最经典也是最基础的问题之一。本题我们考虑一个有 n 个结点的无向图 G。
G 是简单完全图，也就是说 G 中没有自环，也没有重边，但任意两个不同的结点之间都有一条带权的双向边。
每一条边的边权是非负实数，但我们并不知道每一条边的具体边权。
好消息是我们知道 G 中任意两点最短路径的长度d(i,j)。且保证至少有一种边权的分配方案满足得到的带权图中i与j的最短路长度恰好是d(i,j)。
下面是留给你的任务：对于任意一对点(i,j)，希望你能找出来所有合法的边权分配方案中i和j之间边权的最大值。

格式
输入格式
本题中，每一组数据都有多次询问，每一次询问分别给出了一个无向图G。
输入的第一行是一个整数 t，表示总共的询问个数。之后依次给出每一次询问。
对于每一次询问来说，第一行给出了 G 中结点总数 n。之后n行每行有n个整数，给出了一个 n*n 的矩阵 d，其中第i行第j列的整数对应 d(i,j) 表示i到j的最短路径长度。
因为图G是简单无向图，对角线元素d(i,i)总是0，且矩形是对称的（也就是说d(i,j)=d(j,i)）。

输出格式
对于每一次询问，若给定的图G有n个结点，则输出n行，每行有n个整数，描述了一个矩阵 a。矩阵的第i行第j列表示连接i和j的边的最大可能边权。如果(i,j)的边权可以任意大，则输出字符串infty表示无限。
矩阵的对角线没有实质性意义，请全输出0。因为G是无向图，所以输出的矩阵a应该也是对称的（即a(i,j)=a(j,i)）。
不难发现，因为给定的矩阵 d 中每一个数字都是整数，所以最大可能边权总会是整数。

样例1
样例输入1
2
3
0 2 8
2 0 10
8 10 0
3
0 1 1
1 0 1
1 1 0

样例输出1
0 2 8
2 0 infty
8 infty 0
0 1 1
1 0 1
1 1 0

限制
对于 20% 的数据，有 n = 3。
对于 50% 的数据，有 1≤n≤10。
对于 100% 的数据，有 1≤n≤100，且所有询问中n的和不超过 800，对于所有的d满足1≤d≤256。
每一组数据的时限为 0.5 秒。
*/

/*
  得分：100
  解题报告：
    一开始看到这道题有点懵，不过仔细想想，发现求的是每一个点对(i,j)之间可能的最大距离，而不要求每个答案(i,j)合起来要构成一个图。
    也就是说对任意(i,j)是单独求解的。
    可以先依据输入直接构造一张“最短路图”，其中每一条边e(i,j)都是(i,j)的最短路。
    想到Floyd算法中的 G[i][j] = min( G[i][j], G[i][k]+G[k][j] )，如果有点k，能使 G[i][j]==G[i][k]+G[k][j]，那么就可以将边e(i,j)变得无限大，因为无论这条边怎样，都有 (i,k) - (k,j) 的两条边组成不变的最短路。
    那么就可以对每个点对(i,j)枚举k，如果有则边e(i,j)为INF。
    复杂度即为Floyd的O(n^3)。
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

const int MAX=120;
const int INF=0x3f3f3f3f;
int n,G[MAX][MAX],res[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n) FOR(j,0,n) scanf("%d",&G[i][j]);
    memcpy(res,G,SIZ(G));

    FOR(i,0,n) FOR(j,i+1,n){
      bool flag=0;
      FOR(k,0,n) if(k!=i && k!=j && G[i][j]>=G[i][k]+G[k][j]) {flag=1; break;}
      if(flag) res[i][j]=res[j][i]=INF;
    }
    FOR(i,0,n){
      if(res[i][0]<INF) printf("%d",res[i][0]);
      else printf("infty");
      FOR(j,1,n)
        if(res[i][j]<INF) printf(" %d",res[i][j]);
        else printf(" infty");
      printf("\n");
    }
  }

  return 0;
}
