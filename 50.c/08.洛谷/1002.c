/*
题目描述
棋盘上A点有一个过河卒，需要走到目标B点。卒行走的规则：可以向下、或者向右。
同时在棋盘上C点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。
棋盘用坐标表示，A点(0, 0)、B点(n, m)(n, m为不超过20的整数)，同样马的位置坐标是需要给出的。
现在要求你计算出卒从A点能够到达B点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

输入输出格式
输入格式：
一行四个数据，分别表示B点坐标和马的坐标。

输出格式：
一个数据，表示所有的路径条数。

输入输出样例
输入样例#1：
6 6 3 3

输出样例#1：
6

说明
结果可能很大！
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

const int MAX=100;
LLU f[MAX][MAX];  //f[i][j]: 从(0,0)到(i,j)共有几种走法
bool G[MAX][MAX];
int to[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

int main(void){
  int x,y,mx,my; scanf("%d%d%d%d",&x,&y,&mx,&my);
  f[0][0]=1; G[mx][my]=1;
  FOR(i,0,8){ //马的攻击范围
    int tx=mx+to[i][0];
    int ty=my+to[i][1];
    if(tx<0 || tx>x || ty<0 || ty>y) continue;
    G[tx][ty]=1;
  }

  FORR(i,1,y)
    if(G[0][i]) f[0][i]=0;
    else f[0][i]=f[0][i-1];
  FORR(i,1,x) FORR(j,0,y)
    if(G[i][j]) f[i][j]=0;
    else if(j) f[i][j]=f[i-1][j]+f[i][j-1];
    else f[i][j]=f[i-1][j];
  printf("%llu\n",f[x][y]);

  return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0

int GetBit(int n,int i);

int main(void){
  int m,n,p,q,bit,x,y,mov;
  int count=0;
  long long total=1;

  scanf("%d %d %d %d",&m,&n,&p,&q);
  mov=m+n;
  for(int i=0;i<m+n;i++){
    total*=2;
  }
  for(long i=0;i<total;i++){
    x=0;y=0;
    for(int j=0;j<mov;j++){
      bit=GetBit(i,j);
      if(bit==0) x++;
      else y++;
      if(x>m || y>n || (x==p && y==q) ||
        (x==p-2 && y==q+1) || (x==p-2 && y==q-1) ||
        (x==p+2 && y==q+1) || (x==p+2 && y==q-1) ||
        (x==p-1 && y==q+2) || (x==p-1 && y==q-2) ||
        (x==p+1 && y==q+2) || (x==p+1 && y==q-2)){
        break;
      }
    }
    if(x==m && y==n) {
      count++;
    }
  }
  printf("%d\n",count);

  return 0;
}

int GetBit(int n,int i){
  return ((n>>i)&1);
}
*/
