/*
题目背景
这是一道模板题

题目描述
给定n,p求1~n中所有整数在模p意义下的乘法逆元。

输入输出格式
输入格式：
一行n,p

输出格式：
n行,第i行表示i在模p意义下的逆元。

输入输出样例
输入样例#1：
10 13

输出样例#1：
1
7
9
10
8
11
2
5
3
4

说明
1<=n<=3*10^6, n<p<20000528
输入保证 p p 为质数。
*/

#include<iostream>
#include<cstdio>
using namespace std;

void gcd(int a, int b, int & d, int & x, int & y){
  if(!b) {d=a; x=1; y=0;}
  else {gcd(b,a%b,d,y,x); y-=x*(a/b);}
}

int main(void){
  int n,p; scanf("%d%d",&n,&p);
  int d,x,y;
  for(int i=1;i<=n;i++){
    gcd(i,p,d,x,y);
    printf("%d\n",(x+p)%p);
  }

  return 0;
}
