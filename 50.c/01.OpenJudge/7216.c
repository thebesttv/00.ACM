/*
描述
Minecraft是一个几乎无所不能的沙盒游戏，玩家可以利用游戏内的各种资源进行创造，搭建自己的世界。
在Minecraft中，基本的建筑元素是边长为1个单位的立方体，Tony想用N个这种小立方体搭建一个长方体，并用他珍藏已久的贴纸对其进行装饰。如果一张贴纸可以贴满小立方体的一个面。那么，他需要用掉多少张贴纸呢？

输入
一个整数N，表示小明所拥有的小立方体的个数。N不会超过1000。

输出
一个整数，即小明最少用掉的贴纸有多少张。
样例输入
9

样例输出
30
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int check[1020];

int solve(const int n){
  if(check[n]) return check[n];
  int ansMin=(1<<30);
  for(int a=1;a<=n;a++){
    if(n%a) continue;
    for(int b=a;b<=n;b++){
      if(n%(a*b)) continue;
      for(int c=b;c<=n;c++)
        if(a*b*c==n){
          ansMin=min(ansMin,2*(a*b+b*c+a*c));
          //printf("  %d %d %d\n",a,b,c);
        }
    }
  }
  return check[n]=ansMin;
}


int main(void){
  int n;
  while(scanf("%d",&n)==1){
    printf("%d\n",solve(n));
  }

  return 0;
}