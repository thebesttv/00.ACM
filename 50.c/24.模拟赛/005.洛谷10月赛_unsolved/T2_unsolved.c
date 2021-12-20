/*
题目背景
小强和阿米巴是好朋友。

题目描述
小强喜欢数列。有一天，他心血来潮，写下了三个长度均为n的数列。
阿米巴也很喜欢数列。但是他只喜欢其中一种，波动数列。
阿米巴把他的喜好告诉了小强。小强便打算找出这三个数列内的最长波动数列。
也就是说，如果我们将三个数列记做a[n][3]，他必须要构造一个二元组序列：<p[i], q[i]>，使得对于任何 i>1 有：
  p[i] > p[i-1]
  若q[i] = 0，a[p[i]][q[i]] >= a[p[i-1]][q[i-1]]
  若q[i] = 1，a[p[i]][q[i]] <= a[p[i-1]][q[i-1]]
  若q[i] = 2，只要保持段内同向即可（就是对于连续的一段q[i]=2，要么都有a[p[i]][q[i]] >= a[p[i-1]][q[i-1]]，要么都有a[p[i]][q[i]] <= a[p[i-1]][q[i-1]]）。
小强希望这个二元组序列尽可能长。
提示：当q[i] != q[i-1]时，数列的增减性由q[i]而非q[i-1]决定。

清晰版题目描述
小强拿到一个3*n的数组，要在每一列选一个数（或者不选），满足以下条件：
1.如果在第一行选，那它必须大于等于上一个数
2.如果在第二行选，那么必须小于等于上一个数
3.如果在第三行选，对于连续的一段在第三行选的数，必须满足方向相同（都小于等于上一个数或者都大于等于上一个数）

输入输出格式
输入格式：
输入包含4行。
第一行一个数n，表示数列长度。
第2、3、4行，每行n个整数，分别表示三个数列。

输出格式：
输出仅包含一个整数，即最长波动数列的长度。

输入输出样例
输入样例#1：
6
1 2 3 6 5 4
5 4 3 7 8 9
1 2 3 6 5 4

输出样例#1：
6

说明
对于20%的数据，n <= 10， m <= 1000
对于60%的数据，n <= 1000, m <= 1000
对于100%的数据， n <= 100000， m <= 1000000000
其中m = max|a[i]|

样例解释：
取第三行1 2 3（增），然后取第1行6（增），然后取第三行5 4（减），长度为6。
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

/*
f[i][j]: 第i个选第j列的数，所能得到的最长序列长度
  f[i][2]: 选第3列，且上升
  f[i][3]: 选第3列，且下降

  f[i][0] = max{ f[j][k] | j<i && a[j][k']<=a[i][0] } +1
  f[i][1] = max{ f[j][k] | j<i && a[j][k']>=a[i][1] } +1
  f[i][2] = max{ f[j][k] | j<i && a[j][k']<=a[i][2] && k!=3} +1
  f[i][3] = max{ f[j][k] | j<i && a[j][k']>=a[i][2] && k!=2} +1
*/

const int MAX=100020;
int n,a[MAX][4],f[MAX][4];

int main(void){
  scanf("%d",&n);
  FOR(j,0,3) FOR(i,0,n) scanf("%d",&a[i][j]);

  int ansMax=0;
  f[0][0]=f[0][1]=f[0][2]=f[0][3]=1;
  FOR(i,1,n){
    FOR(j,0,i) FOR(k,0,2) if(a[j][k]<=a[i][0])
      f[i][0]=max(f[i][0],f[j][k]+1);
    FOR(j,0,i) FOR(k,2,4) if(a[j][2]<=a[i][0])
      f[i][0]=max(f[i][0],f[j][k]+1);

    FOR(j,0,i) FOR(k,0,2) if(a[j][k]>=a[i][1])
      f[i][1]=max(f[i][1],f[j][k]+1);
    FOR(j,0,i) FOR(k,2,4) if(a[j][2]>=a[i][1])
      f[i][1]=max(f[i][1],f[j][k]+1);

    FOR(j,0,i) FOR(k,0,3) if(a[j][k]<=a[i][2])
      f[i][2]=max(f[i][2],f[j][k]+1);

    FOR(j,0,i) FOR(k,0,2) if(a[j][k]>=a[i][2])
      f[i][3]=max(f[i][3],f[j][k]+1);
    FOR(j,0,i) if(a[j][2]>=a[i][2])
      f[i][3]=max(f[i][3],f[j][3]+1);

    ansMax=max(ansMax,max(f[i][0],max(f[i][1],max(f[i][2],f[i][3]))));
  }
  printf("%d\n",ansMax);

  return 0;
}
