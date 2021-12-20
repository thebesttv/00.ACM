/*
描述
给定两个正整数，求它们的最大公约数。

输入
有多组数据，每行为两个正整数，且不超过int可以表示的范围。

输出
行对应输出最大公约数。

样例输入
4 8
8 6
200 300

样例输出
4
2
100
*/

#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

int main(void){
  int a,b;
  while(scanf("%d%d",&a,&b)==2){
    printf("%d\n",gcd(a,b));
  }

  return 0;
}
