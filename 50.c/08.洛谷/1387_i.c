/*
题目描述
在一个n*m的只包含0和1的矩阵里找出一个不包含0的最大正方形，输出边长。

输入输出格式
输入格式：
输入文件第一行为两个整数n,m（1<=n,m<=100），接下来n行，每行m个数字，用空格隔开，0或1.

输出格式：
一个整数，最大正方形的边长

输入输出样例
输入样例#1：
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1

输出样例#1：
2
*/

/*
  解题报告：
  动规：
    令 f(x,y) 表示右下角为(x,y)的最大正方形边长，则
     f(x,y) = max{ f(x-1,y-1)+1, f(x,y-1)+1, f(x-1,y)+1 | 取任意一个max都要判断是否可行 }, G[x][y]=1
              0, G[x][y]=0
  前缀和：
    当一块正方形的1的和为边长的平方时，它一定是合法的。
    那么可以令 s[i][j] 为(1,1)到(i,j)的和，当 s[i][j]-s[i][j-l]-s[i-l][j]+s[i-l][j-l] == l*l 时，以(i,j)为右下角、边长为l的正方形合法。

    ps: 原来还可以用二维前缀和做，机智！
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

//前缀和
const int MAX=120;
int n,m;
bool G[MAX][MAX];
int s[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=1,t;i<=n;i++) FORR(j,1,m) {scanf("%d",&t); G[i][j]=t;}

  FORR(i,1,n) FORR(j,1,m)
    s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+G[i][j];

  int ansMax=1,t=min(n,m);
  FORR(i,1,n) FORR(j,1,m) if(G[i][j]) RORR(l,min(t,min(i,j)),ansMax)
    if(s[i][j]-s[i-l][j]-s[i][j-l]+s[i-l][j-l]==l*l) {ansMax=l; break;}

  printf("%d\n",ansMax);

  return 0;
}

/*
//动规
const int MAX=120;
int n,m;
bool G[MAX][MAX];
int check[MAX][MAX];

int f(int x, int y){
  int & a=check[x][y];
  if(a!=-1) return a;
  if(!G[x][y]) return a=0;

  a=1;
  if(x && y && G[x-1][y-1]){
    int t; bool flag;
    t=f(x-1,y-1); flag=1;
    FOR(i,x-t,x) if(!G[i][y]) {flag=0; break;}
    if(flag) FOR(i,y-t,y) if(!G[x][i]) {flag=0; break;}
    if(flag) a=max(a,t+1);

    t=f(x,y-1); flag=1;
    if(x-t>=0){
      FOR(i,x-t,x) if(!G[i][y]) {flag=0; break;}
      if(flag) FOR(i,y-t,y) if(!G[x-t][i]) {flag=0; break;}
      if(flag) a=max(a,t+1);
    }

    t=f(x-1,y); flag=1;
    if(y-t>=0){
      FOR(i,y-t,y) if(!G[x][i]) {flag=0; break;}
      if(flag) FOR(i,x-t,x) if(!G[i][y-t]) {flag=0; break;}
      if(flag) a=max(a,t+1);
    }
  }
  return a;
}

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=0,t;i<n;i++) FOR(j,0,m) {scanf("%d",&t); G[i][j]=t;}

  MST(check,-1);
  int ansMax=0;
  FOR(i,0,n) FOR(j,0,m) ansMax=max(ansMax,f(i,j));
  printf("%d\n",ansMax);

  return 0;
}
*/
