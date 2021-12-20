/*
描述
组合数 C(n,m) 表示的是从n个物品中选出m个物品的方案数。举个例子，从(1, 2, 3)三个物品中选择两个物品可以有(1, 2), (1, 3), (2, 3)这三种选择方法。根据组合数的定义，我们可以给出计算组合数的一般公式：
  C(n,m) = n!/(m!*(n-m)!)
小葱想知道如果给定n, m和k，对于所有的 0<=i<=n, 0<=j<=min(i,m) 有多少对 (i,j) 满足 C(i,j) 是k的倍数。

格式
输入格式
第一行有两个整数t, k，其中t代表该测试点总共有多少组测试数据，k的意义见问题描述。
接下来t行每行两个整数n, m，其中n, m的意义见问题描述。

输出格式
t行，每行一个整数代表所有的 0<=i<=n, 0<=j<=min(i,m) 有多少对(i,j)满足 C(i,j) 是k的倍数。

样例1
样例输入1
1 2
3 3

样例输出1
1

样例2
样例输入2
2 5
4 5
6 7

样例输出2
0
7

限制
对50%的数据，t=1;
对100%的数据，0<n,m<=2000, 2<=k<=21, t<=2000

提示
样例1说明
在所有可能的情况中，只有 C(2,1)=2 是2的倍数。

来源
NOIP 2016 提高组 Day 2 第一题
*/

/*
  得分：100
  解题报告：
    首先要计算出所有的C(1:2000,1:2000)，当然计算时要膜一个数。又因为对任意数n，当正整数n为k倍数时n%k=0，因此可以膜k，那么C(i,j)为0的即为k的倍数。
    然后就是计算题目要求的。
    因为如果每次都用O(n^2)查找的话一定会TLE，那么就想到类似前缀数组的递推的方法。
    令题目要求的每组n,m答案为S(n,m)，可知：
      当m>n时，S(n,m)=S(n,n)
    而想要递推还要找 S(n,m) 与 S(n-1,m), S(n,m-1), S(n-1,m-1) 中任意几个的关系。
    想象一个由C(i,j)构成的矩阵，那么S(n,m)即为左上角为(0,0)、右下角为(n,m)的矩形中每个C(i,j)的和，那么显然（XD）：
      S(n,m) = S(n-1,m) + S(n,m-1) - S(n-1,m-1) + (C(n,m)==0)
    然后再加上m>n的情况，就可以了。
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

const int MAX=2000;
int C[MAX+20][MAX+20],n,m,k;
int S[MAX+20][MAX+20];

int main(void){
  int T; scanf("%d%d",&T,&k);
  MST(C,-1); C[0][0]=1;
  FORR(i,1,MAX){
    C[i][0]=C[i][i]=1;
    FOR(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
  }
  FORR(i,1,MAX){
    S[i][0]=0;
    FORR(j,1,i) S[i][j]=S[i][j-1]+S[i-1][j]-S[i-1][j-1]+(C[i][j]==0);
    FORR(j,i+1,MAX) S[i][j]=S[i][i];
  }
  int n,m;
  while(T--){
    scanf("%d%d",&n,&m);
    printf("%d\n",S[n][m]);
  }

  return 0;
}
