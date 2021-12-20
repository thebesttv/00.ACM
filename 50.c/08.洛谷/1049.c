/*
题目描述
有一个箱子容量为V（正整数，0<=V<=20000），同时有n个物品，0<n<=30，每个物品有一个体积（正整数）。
要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

输入输出格式
输入格式：
一个整数，表示箱子容量
一个整数，表示有n个物品
接下来n行，分别表示这n个物品的各自体积

输出格式：
一个整数，表示箱子剩余空间。

输入输出样例
输入样例#1：
24
6
8
3
12
7
9
7

输出样例#1：
0

说明
NOIp2001普及组 第4题
*/

//01背包，体积为 v 的物品价值也为 v ，求最大价值 vmax ，解为 总体积-vmax
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int f[20020];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int v; scanf("%d",&v);
    for(int j=n;j>=0;j--){  //<b>要倒推</b>
      if(j>=v) f[j]=max(f[j],f[j-v]+v);
    }
  }
  printf("%d\n",n-f[n]);

  return 0;
}
