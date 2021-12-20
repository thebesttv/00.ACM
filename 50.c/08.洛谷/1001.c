/*
题目描述
输入两个整数a,b，输出它们的和(|a|,|b|<=10^9)。
注意
1、pascal使用integer会爆掉哦！
2、有负数哦！
3、c/c++的main函数必须是int类型，而且最后要return 0。这不仅对洛谷其他题目有效，而且也是noip/noi比赛的要求！
好吧，同志们，我们就从这一题开始，向着大牛的路进发。
“任何一个伟大的思想，都有一个微不足道的开始。”

输入输出格式
输入格式：
两个整数a,b以空格分开

输出格式：
一个数a+b
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
  long long a,b;

  scanf("%lld %lld",&a,&b);
  printf("%lld\n",a+b);

  return 0;
}
