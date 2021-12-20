/*
描述
求关于x的同余方程ax ≡ 1 (mod b)的最小正整数解。

格式
输入格式
输入只有一行，包含两个正整数a, b，用一个空格隔开。

输出格式
输出只有一行，包含一个正整数x0，即最小正整数解。输入数据保证一定有解。

样例1
样例输入1
3 10

样例输出1
7

限制
每个测试点1s

提示
对于40%的数据，2 ≤b≤ 1,000； 
对于60%的数据，2 ≤b≤ 50,000,000； 
对于100%的数据，2 ≤a, b≤ 2,000,000,000。

来源
Noip2012提高组复赛Day2T1
*/

/*
  得分：100
  解题报告：
    可使用扩展欧几里得求解逆元。（还是前一天特地看了一下书才做出来的。。。）
*/

#include<iostream>
#include<cstdio>
using namespace std;

void gcd(int a, int b, int & d, int & x, int & y){
  if(!b) {d=a; x=1; y=0;}
  else {gcd(b,a%b,d,y,x); y-=x*(a/b);}
}

int main(void){
  int a,b; scanf("%d%d",&a,&b);
  int d,x,y;
  gcd(a,b,d,x,y);
  int ans = (1LL*x+b)%b;
  printf("%d\n",ans);

  return 0;
}
