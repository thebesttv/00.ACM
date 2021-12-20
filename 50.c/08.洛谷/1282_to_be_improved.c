/*
题目描述
多米诺骨牌由上下2个方块组成，每个方块中有1~6个点。现有排成一行的多米诺骨牌，上方块中点数之和记为S1，下方块中点数之和记为S2，它们的差为|S1-S2|。例如在图中，S1=6+1+1+1=9，S2=1+5+3+2=11，|S1-S2|=2。每个多米诺骨牌可以旋转180°，使得上下两个方块互换位置。 编程用最少的旋转次数使多米诺骨牌上下2行点数之差达到最小。

上： 6  1  1  1
下： 1  5  3  2

对于图中的例子，只要将最后一个多米诺骨牌旋转180°，可使上下2行点数之差为0。

输入输出格式
输入格式：
输入文件的第一行是一个正整数n(1≤n≤1000)，表示多米诺骨牌数。接下来的n行表示n个多米诺骨牌的点数。每行有两个用空格隔开的正整数，表示多米诺骨牌上下方块中的点数a和b，且1≤a，b≤6。

输出格式：
输出文件仅一行，包含一个整数。表示求得的最小旋转次数。

输入输出样例
输入样例#1：
4
6 1
1 5
1 3
1 2

输出样例#1：
1
*/

/*
  解题报告：
    令 f(i,d) 表示考虑前i个，sum上-sum下为d时的最小翻转次数，则可以更新
      f(i,d) -> f(i+1,d+a[i+1][0]-a[i+1][1])
      f(i,d)+1 -> f(i+1,d+a[i+1][1]-a[i+1][0])
    但要注意负数。
    注：不知道为什么好像用模的方法消除负数不行。。。下次再说吧。。。
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

const int MAX=1020;
const int INF=0x3f3f3f3f;
const int TAG=5000;
int n,a[MAX][2];  //a[i][0/1]: up/down
int f[MAX][(TAG<<1)+10];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&a[i][0],&a[i][1]);

  MST(f,0x3f); f[1][a[0][0]-a[0][1]+TAG]=0; f[1][a[0][1]-a[0][0]+TAG]=1;
  FOR(i,1,n){
    int d=a[i][0]-a[i][1];
    FORR(j,0,TAG){  //枚举差
      int t,n1,n2;
      t=f[i][TAG+j];
      if(t<=INF){
        n1=j+d+TAG;
        f[i+1][n1]=min(f[i+1][n1],t);
        n2=j-d+TAG;
        f[i+1][n2]=min(f[i+1][n2],t+1);
      }

      t=f[i][TAG-j];
      if(t<INF){
        n1=-j+d+TAG;
        f[i+1][n1]=min(f[i+1][n1],t);
        n2=-j-d+TAG;
        f[i+1][n2]=min(f[i+1][n2],t+1);
      }
    }
  }
  int ansMin=INF;
  FORR(i,0,TAG) if(f[n][TAG+i]<INF || f[n][TAG-i]<INF) {ansMin=min(f[n][TAG+i],f[n][TAG-i]); break;}
  printf("%d\n",ansMin);

  return 0;
}

/*
const int MAX=1020;
const int INF=0x3f3f3f3f;
const int MOD=6;
int n,a[MAX][2];  //a[i][0/1]: up/down
int f[MAX][10];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&a[i][0],&a[i][1]);

  MST(f,0x3f); f[1][(a[0][0]-a[0][1]+MOD)%MOD]=0; f[1][(a[0][1]-a[0][0]+MOD)%MOD]=1;
  FOR(i,1,n){
    int d=a[i][0]-a[i][1];
    FOR(j,0,MOD){
      int t=f[i][j]; if(t==INF) continue;
      int n1=(j+d+MOD)%MOD;
      f[i+1][n1]=min(f[i+1][n1],t);
      int n2=(j-d+MOD)%MOD;
      f[i+1][n2]=min(f[i+1][n2],t+1);
    }
  }
#ifdef DEBUG
    FORR(i,1,n) FORR(j,0,MOD) if(f[i][j]<INF) printf("  f[%d][%d]: %d\n",i,j,f[i][j]);
#endif
  int ansMin=INF;
  FORR(i,0,MOD) if(f[n][i]<INF) {ansMin=f[n][i]; break;}
  printf("%d\n",ansMin);

  return 0;
}
*/

/*
const int MAX=1020;
const int INF=0x3f3f3f3f;
int n,a[MAX][2];  //a[i][0/1]: up/down
int f[MAX][6*MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&a[i][0],&a[i][1]);

  MST(f,0x3f); f[1][(a[0][0]-a[0][1]+6)%6]=0; f[1][(a[0][1]-a[0][0]+6)%6]=1;
  int MOD=6;
  FOR(i,1,n){
    int tMOD=MOD+6;
    int d=a[i][0]-a[i][1];
    FORR(j,0,MOD){
      int t=f[i][j]; if(t==INF) continue;
      int n1=(j+d+tMOD)%tMOD;
      f[i+1][n1]=min(f[i+1][n1],t);
      int n2=(j-d+tMOD)%tMOD;
      f[i+1][n2]=min(f[i+1][n2],t+1);
#ifdef DEBUG
      printf("  f[%d][%d]: %d, -> f[%d][%d], f[%d][%d]\n",i,j,t,i+1,n1,i+1,n2);
#endif
    }
    MOD+=6;
  }
#ifdef DEBUG
    FORR(i,1,n) FORR(j,0,MOD) if(f[i][j]<INF) printf("  f[%d][%d]: %d\n",i,j,f[i][j]);
#endif
  int ansMin=INF;
  FORR(i,0,MOD) if(f[n][i]<INF) {ansMin=f[n][i]; break;}
  printf("%d\n",ansMin);

  return 0;
}
*/
