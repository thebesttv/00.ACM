/*
题目描述
为了更好的备战NOIP2013，电脑组的几个女孩子LYQ,ZSC,ZHQ认为，我们不光需要机房，我们还需要运动，于是就决定找校长申请一块电脑组的课余运动场地，听说她们都是电脑组的高手，校长没有马上答应他们，而是先给她们出了一道数学题，并且告诉她们：你们能获得的运动场地的面积就是你们能找到的这个最大的数字。
校长先给他们一个N*N矩阵。要求矩阵中最大加权矩形，即矩阵的每一个元素都有一权值，权值定义在整数集上。从中找一矩形，矩形大小无限制，是其中包含的所有元素的和最大 。矩阵的每个元素属于[-127,127],例如

  0 -2 -7  0
  9  2 -6  2
 -4  1 -4  1 
 -1  8  0 -2

  最大为左下角的
    9 2
   -1 1
   -1 8
  共15

几个女孩子有点犯难了，于是就找到了电脑组精打细算的HZH，TZY小朋友帮忙计算，但是遗憾的是他们的答案都不一样，涉及土地的事情我们可不能含糊，你能帮忙计算出校长所给的矩形中加权和最大的矩形吗？

输入输出格式
输入格式：
第一行：n，接下来是n行n列的矩阵。

输出格式：
最大矩形（子矩阵）的和。

输入输出样例
输入样例#1： 
4
0 -2 -7 0
9 2 -6 2
-4 1 -4  1 
-1 8  0 -2

输出样例#1： 
15

说明
n<=120
*/

/*
  解题报告：
    采用类似于“最大连续子段”的DP解法。
    首先处理每一行i的前缀和row[i]。
    令 f[l][r][i] 表示占据列[l:r]、并以第i行结尾的最大连续子矩阵，则
      f[l][r][i] = max{ f[l][r][i-1] + sum{a[i][l:r]}, sum{a[i][l:r]} }
    可以使用前缀和优化，最终可以在排除前缀和的情况下使用O(1)空间，共O(n^3)时间计算出解。
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=140;
int n,row[MAX][MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) FORR(j,1,n){
    scanf("%d",&row[i][j]);
    row[i][j]+=row[i][j-1];
  }

  int ansMax=row[1][1];
  FORR(l,1,n) FORR(r,l,n){
    int tMax=0;
    FORR(i,1,n){
      int rsum=row[i][r]-row[i][l-1];
      tMax=max(tMax+rsum,rsum);
      ansMax=max(ansMax,tMax);
    }
  }
  printf("%d\n",ansMax);

  return 0;
}
