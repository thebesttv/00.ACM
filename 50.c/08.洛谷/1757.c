/*
题目背景
直达通天路·小A历险记第二篇

题目描述
自01背包问世之后，小A对此深感兴趣。一天，小A去远游，却发现他的背包不同于01背包，他的物品大致可分为k组，每组中的物品相互冲突，现在，他想知道最大的利用价值是多少。

输入输出格式
输入格式：
两个数m,n，表示一共有n件物品，总重量为m
接下来n行，每行3个数ai,bi,ci，表示物品的重量，利用价值，所属组数

输出格式：
一个数，最大的利用价值

输入输出样例
输入样例#1：
45 3
10 10 1
10 5 1
50 400 2

输出样例#1：
10

说明
1<=m<=1000 1<=n<=1000 组数t<=100
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

const int MAX=1020;
int n,V,f[MAX];  //f[i][j]: 前i组，容量为j时的最大 f[i][j] = max{ f[i-1][j], f[i-1][j-c[k]]+w[k] }
struct Obj{ //奇葩的存储方式
  int c,w,next;
}obj[MAX];
int so[MAX],tailO=1;

inline void addObj(int c, int w, int g){
  int t=tailO++;
  obj[t] = (Obj){c,w,so[g]}; so[g]=t;
}
inline void GroupPack(int k){ //对第k组进行分组背包
  ROR(j,V,0) for(RE int i=so[k];i;i=obj[i].next)
    if(j>=obj[i].c) f[j] = max(f[j],f[j-obj[i].c]+obj[i].w);
}

int main(void){
  scanf("%d%d",&V,&n);
  int c,w,g;
  FORR(i,1,n){
    scanf("%d%d%d",&c,&w,&g);
    addObj(c,w,g);
  }

  FORR(i,1,1000) if(so[i]) GroupPack(i);

  printf("%d\n",f[V]);

  return 0;
}
