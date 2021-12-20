/*
题目描述
回到家中的猫猫把三桶鱼全部转移到了她那长方形大池子中，然后开始思考：到底要以何种方法吃鱼呢（猫猫就是这么可爱，吃鱼也要想好吃法 ^_*）。她发现，把大池子视为01矩阵（0表示对应位置无鱼，1表示对应位置有鱼）有助于决定吃鱼策略。
在代表池子的01矩阵中，有很多的正方形子矩阵，如果某个正方形子矩阵的某条对角线上都有鱼，且此正方形子矩阵的其他地方无鱼，猫猫就可以从这个正方形子矩阵“对角线的一端”下口，只一吸，就能把对角线上的那一队鲜鱼吸入口中。
猫猫是个贪婪的家伙，所以她想一口吃掉尽量多的鱼。请你帮猫猫计算一下，她一口下去，最多可以吃掉多少条鱼？

输入输出格式
输入格式：
有多组输入数据，每组数据：
第一行有两个整数n和m（n,m≥1），描述池塘规模。接下来的n行，每行有m个数字（非“0”即“1”）。每两个数字之间用空格隔开。

输出格式：
只有一个整数——猫猫一口下去可以吃掉的鱼的数量，占一行，行末有回车。

输入输出样例
输入样例#1： 复制
4 6
0 1 0 1 0 0
0 0 1 0 1 0
1 1 0 0 0 1
0 1 1 0 1 0

输出样例#1： 复制
3

样例说明
右上角的
  1 0 0
  0 1 0
  0 0 1

数据范围
对于30%的数据，有n,m≤100
对于60%的数据，有n,m≤1000
对于100%的数据，有n,m≤2500
*/

/*
  解题报告：
    用f[i][j]表示以(i,j)为正方形右下角的最大的可以吃的鱼的数量，则
      f[i][j] = 0, G[i][j]=0
                f[i-1][j-1]+1, 从f[i-1][j-1]更新到f[i][j]可行
                1, G[i][j]=1
    可以利用两个前缀和数组判断更新是否可行，只需判断 G[i][j-l-1:j-1] 和 G[i-l-1:i-1][j] 是否都为0，其中l=f[i-1][j-1]。
    但因为对角线可能是从左往右，也可能是从右往左，因此一共要将矩阵旋转转4次（其实是3次）并计算。
    不过为什么要转四次而非转两次，我暂时还不清楚。。。
  正解：
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

const int MAX=2520;
int n,m,G[MAX][MAX],tmp[MAX][MAX];
int f[MAX][MAX],row[MAX][MAX],col[MAX][MAX];
char t1[MAX<<2];

void turn(){
  FORR(i,1,n) FORR(j,1,m)
    tmp[j][n-i+1]=G[i][j];
  swap(n,m); memcpy(G,tmp,SIZ(tmp));
}

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    FORR(i,1,n){  //读入优化
      do FGETS(t1); while(t1[0]!='0' && t1[0]!='1');
      register int p=0; int *pG=&G[i][0];
      FORR(j,1,m){
        *(pG+j)=(t1[p]=='1'); p+=2;
      }
    }
    int ansMax=0;
    FOR(T,0,4){ //计算四次
      //FORR(i,1,n) FORR(j,1,m){
      //  row[i][j]=row[i][j-1]+G[i][j];
      //  col[j][i]=col[j][i-1]+G[i][j];
      //}

      //常数优化
      FORR(i,1,n){
        int *p=&row[i][0];
        FORR(j,1,m) *(p+j)=*(p+j-1)+G[i][j];
      }

      FORR(j,1,m){
        int *p=&col[j][0];
        FORR(i,1,n) *(p+i)=*(p+i-1)+G[i][j];
      }

      FORR(i,1,n) FORR(j,1,m){
        if(!G[i][j]) {f[i][j]=0; continue;}
        f[i][j]=1;
        int l=f[i-1][j-1];
        if(row[i][j-1]-row[i][j-l-1]) continue;
        if(col[j][i-1]-col[j][i-l-1]) continue;
        f[i][j]=l+1;
        ansMax=max(ansMax,f[i][j]);
      }
      if(T==3) break;
      turn();
    }

    printf("%d\n",ansMax);
  }

  return 0;
}
