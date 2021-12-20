/*
题目描述
已知：Sn= 1 + 1/2 + 1/3 + ... + 1/n 。显然对于任意一个整数K，当n足够大的时候，Sn大于K。
现给出一个整数K（1<=k<=15），要求计算出一个最小的n；使得Sn>K。

输入输出格式
输入格式：
一个正整数K。

输出格式：
一个正整数N。

输入输出样例
输入样例#1：
1

输出样例#1：
2
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
  double sum=0;
  int k;

  scanf("%d",&k);
  for(long long i=1;;i++){
    sum+=(double)1/i;
    if(sum>k){
      printf("%lld\n",i);
      break;
    }
  }

  return 0;
}
