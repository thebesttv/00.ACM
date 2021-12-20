/*
题目背景
众所周知，衡量一个编译器是否优秀的标准，除了它的编译速度和正确性以外，编译出的代码的质量也很重要。最近，作为XCC系列编译器作者的Dr. X发明了一种跨时代的优化算法：“NanGe不等式优化”。一个程序可以看成是由若干个连续的函数构成的，NanGe不等式算法能针对某一个函数进行优化，得到一个优化效果值, 不同的函数的效果值可能是不同的。但这个算法还有一个很大的Bug：该算法不能同时优化相邻的两个函数，否则就会直接Compile Error，值得注意的是，一个程序的第一个函数和最后一个函数也算是相邻的。

题目描述
现在给你一个程序从头到尾每个函数的优化效果值，Dr. X想用NanGe不等式对该程序的M个函数进行优化，他该怎么选择才能使总的优化效果值最大（前提是不能出现错误）？如果错误不能避免，请输出“Error!”

输入输出格式
输入格式：
输入的第一行包含两个正整数n、m。
第二行为 n 个整数 ai。

输出格式：
输出仅一个整数，表示最后对该程序进行优化后的最大效果值。如果无解输出“Error!”，不包含引号。

输入输出样例
输入样例#1：
7 3
1 2 3 4 5 6 7 

输出样例#1：
15

输入样例#2：
7 4
1 2 3 4 5 6 7

输出样例#2：
Error!

说明
对于 60% 的数据，n<=5000
对于 100% 的数据，m<=n<=200000, -1000<=ai<=1000
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

const int MAX=200020;
const int INF=0x3f3f3f3f;
int n,m,a[MAX];
int f0[MAX],f1[MAX];
int g0[MAX],g1[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);

  if(m > n/2) {printf("Error!\n"); return 0;}

  int ansMax=-INF;
  //从 [1:n-1] 中选择
  FORR(j,1,m) f0[j]=-INF;
  memcpy(f1,f0,SIZ(f0)); memcpy(g0,f0,SIZ(f0)); memcpy(g1,f0,SIZ(f0));
  //f1[0]=f0[0]=0;
  //f1[1]=a[1];
  g1[0]=g0[0]=0;
  g1[1]=a[1];
  FOR(i,2,n){
    int to=min(i/2,m);
    ROR(j,to,1){
      f1[j] = g0[j-1] + a[i];
      f0[j] = max(g1[j],g0[j]);
    }
    memcpy(g0,f0,SIZ(f0)); memcpy(g1,f1,SIZ(f1));
    if(to==m) ansMax=max(ansMax,max(f1[m],f0[m]));
  }

  //从 [2:n] 中选择
  FORR(j,1,m) f0[j]=-INF;
  memcpy(f1,f0,SIZ(f0)); memcpy(g0,f0,SIZ(f0)); memcpy(g1,f0,SIZ(f0));
  //f1[0]=f0[0]=0;
  //f1[1]=a[2];
  g1[0]=g0[0]=0;
  g1[1]=a[2];
  FORR(i,3,n){
    int to=min(i/2,m);
    ROR(j,to,1){
      f1[j] = g0[j-1] + a[i];
      f0[j] = max(g1[j],g0[j]);
    }
    memcpy(g0,f0,SIZ(f0)); memcpy(g1,f1,SIZ(f1));
    if(to==m) ansMax=max(ansMax,max(f1[m],f0[m]));
  }

  printf("%d\n",ansMax);

  return 0;
}

/*
const int MAX=2020;
const int INF=0x3f3f3f3f;
int n,m,a[MAX];
int f0[MAX][MAX],f1[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);

  if(m > n/2) {printf("Error!\n"); return 0;}

  int ansMax=-INF;
  //从 [1:n-1] 中选择
  f1[1][1]=a[1];
  FOR(i,2,n){
    int to=min(i/2,m);
    ROR(j,to,1){
      f1[i][j] = f0[i-1][j-1] + a[i];
      f0[i][j] = max(f1[i-1][j],f0[i-1][j]);
    }
    if(to==m) ansMax=max(ansMax,max(f1[i][m],f0[i][m]));
  }
#ifdef DEBUG
  FOR(i,2,n) FOR(j,1,min(i/2,m)){
    if(f0[i][j]) printf("  f0[%d][%d]: %d\n",i,j,f0[i][j]);
    if(f1[i][j]) printf("  f1[%d][%d]: %d\n",i,j,f1[i][j]);
  }
#endif

  //从 [2:n] 中选择
  MST(f0,0); MST(f1,0);
  FORR(i,2,n){
    int to=min(i/2,m);
    ROR(j,to,1){
      f1[i][j] = f0[i-1][j-1] + a[i];
      f0[i][j] = max(f1[i-1][j],f0[i-1][j]);
    }
    if(to==m) ansMax=max(ansMax,max(f1[i][m],f0[i][m]));
  }

  printf("%d\n",ansMax);

  return 0;
}
*/

/*
const int MAX=1020;
const int INF=0x3f3f3f3f;
int n,m,a[MAX];
int f0[MAX],f1[MAX];
int g01[MAX],g02[MAX],g11[MAX],g12[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);

  if(m > n/2) {printf("Error!\n"); return 0;}

  int ansMax=-INF;
  //从 [1:n-1] 中选择
  //f1[1][1]=a[1];
  f1[1]=a[1]; g11[1]=a[1];
  FOR(i,2,n){
    int to=min(i/2,m);
    ROR(j,to,1){
      //f1[i][j] = max(f0[i-2][j-1],f1[i-2][j-1]) + a[i];
      //f0[i][j] = max(f1[i-1][j-1],f0[i-1][j-1]);
      f1[j] = max(g02[j-1],g12[j-1]) + a[i];
      f0[j] = max(g11[j-1],g01[j-1]);
    }
    memcpy(g02,g01,SIZ(g01)); memcpy(g01,f0,SIZ(f0));
    memcpy(g12,g11,SIZ(g11)); memcpy(g11,f1,SIZ(f1));
    if(to==m) ansMax=max(ansMax,max(f1[m],f0[m]));
  }

  //从 [2:n] 中选择
  MST(f0,0); MST(f1,0); MST(g01,0); MST(g02,0); MST(g11,0); MST(g12,0);
  FORR(i,2,n){
    int to=min(i/2,m);
    ROR(j,to,1){
      f1[j] = max(g02[j-1],g12[j-1]) + a[i];
      f0[j] = max(g11[j-1],g01[j-1]);
    }
    memcpy(g02,g01,SIZ(g01)); memcpy(g01,f0,SIZ(f0));
    memcpy(g12,g11,SIZ(g11)); memcpy(g11,f1,SIZ(f1));
    if(to==m) ansMax=max(ansMax,max(f1[m],f0[m]));
  }

  printf("%d\n",ansMax);

  return 0;
}
*/

/*
const int MAX=1020;
const int INF=0x3f3f3f3f;
int n,m,a[MAX];
int f[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);

  if(m > n/2) {printf("Error!\n"); return 0;}

  int ansMax=-INF;
  //从 [1:n-1] 中选择
  FOR(i,1,n){
    f[i][1]=a[i];
    int to=min(i/2,m);
    FORR(j,2,to){
      int tMax=-INF;
      FOR(ii,1,i-1) tMax = max(tMax, f[ii][j-1]);
      f[i][j]=tMax+a[i];
    }
    if(to==m) ansMax=max(ansMax,f[i][m]);
  }

  //从 [2:n] 中选择
  MST(f,0);
  FORR(i,2,n){
    f[i][1]=a[i];
    int to=min(i/2,m);
    FORR(j,2,to){
      int tMax=-INF;
      FOR(ii,2,i-1) tMax = max(tMax, f[ii][j-1]);
      f[i][j]=tMax+a[i];
    }
    if(to==m) ansMax=max(ansMax,f[i][m]);
  }
  printf("%d\n",ansMax);

  return 0;
}
*/
