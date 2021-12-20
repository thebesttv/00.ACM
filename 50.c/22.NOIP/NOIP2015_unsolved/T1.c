/*
描述
幻方是一种很神奇的 N ∗ N 矩阵：它由数字 1,2,3, … … , N ∗ N 构成，且每行、每列及两条对角线上的数字之和都相同。
当 N 为奇数时，我们可以通过以下方法构建一个幻方： 首先将 1 写在第一行的中间。
之后，按如下方式从小到大依次填写每个数 K(K = 2,3, … , N ∗ N) ：
1. 若 (K − 1) 在第一行但不在最后一列，则将 K 填在最后一行， (K − 1) 所在列的右一列；
2. 若 (K − 1) 在最后一列但不在第一行，则将 K 填在第一列，(K − 1) 所在行的上一行；
3. 若 (K − 1) 在第一行最后一列，则将 K 填在 (K − 1) 的正下方；
4. 若 (K − 1) 既不在第一行，也不在最后一列，如果 (K − 1) 的右上方还未填数， 则将 K 填在(K − 1)的右上方，否则将 K 填在 (K − 1) 的正下方。
现给定 N，请按上述方法构造 N ∗ N 的幻方。

格式
输入格式
一个整数 N，即幻方的大小。

输出格式
输出文件包含 N 行，每行 N 个整数，即按上述方法构造出的 N ∗ N 的幻方。相邻两个整数之间用单个空格隔开。

样例1
样例输入1
3

样例输出1
8 1 6
3 5 7
4 9 2

限制
对于 100% 的数据，1 ≤ N ≤ 39 且 N 为奇数。

来源
NOIP 2015 提高组 Day 1 第一题
*/

/*
  得分：100
  解题报告：
    直接模拟即可。
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

const int MAX=40;
int a[MAX][MAX],n;
struct Node{
  int x,y;
}node[MAX*MAX];

int main(void){
  scanf("%d",&n);
  a[1][(n+1)/2]=1;
  node[1].x=1; node[1].y=(n+1)/2;

  int tot=n*n;
  FORR(i,2,tot){
    int t=i-1;
    int x=node[t].x,y=node[t].y;
    if(x==1 && y!=n){
      a[n][y+1]=i;
      node[i].x=n; node[i].y=y+1;
    }else if(x!=1 && y==n){
      a[x-1][1]=i;
      node[i].x=x-1; node[i].y=1;
    }else if(x==1 && y==n){
      a[x+1][y]=i;
      node[i].x=x+1; node[i].y=y;
    }else if(!a[x-1][y+1]){
      a[x-1][y+1]=i;
      node[i].x=x-1; node[i].y=y+1;
    }else{
      a[x+1][y]=i;
      node[i].x=x+1; node[i].y=y;
    }
  }
  FORR(i,1,n){
    printf("%d",a[i][1]);
    FORR(j,2,n) printf(" %d",a[i][j]);
    printf("\n");
  }

  return 0;
}
