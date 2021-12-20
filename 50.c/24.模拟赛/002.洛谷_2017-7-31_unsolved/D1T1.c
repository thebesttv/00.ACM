/*
题目描述
小芳有一张n*m的长方形纸片。每次小芳将会从这个纸片里面剪去一个最大的正方形纸片，直到全部剪完（剩下一个正方形）为止。
小芳总共能得到多少片正方形纸片？

输入输出格式
输入格式：
一行两个整数n和m

输出格式：
一行一个整数，总共能得到的纸片数量。

输入输出样例
输入样例#1：
6 4

输出样例#1：
3

说明
对于30%的数据满足n=1
对于60%的数据满足n,m≤10^3
对于100%的数据满足n,m≤10^12
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
  long long n,m;
  scanf("%lld%lld",&n,&m);
  register long long cnt=0;
  while(n>=1 && m>=1){
    if(n>m){
      cnt+=n/m;
      n-=(n/m)*m;
    }else{
      cnt+=m/n;
      m-=(m/n)*n;
    }
  }
  printf("%lld\n",cnt);

  return 0;
}
