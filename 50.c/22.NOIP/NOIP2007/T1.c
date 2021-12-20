/*
描述
某次科研调查时得到了n个自然数，每个数均不超过1500000000（1.5*10^9）。已知不相同的数不超过10000个，现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统计结果。

格式
输入格式
第1行是整数n(1<=n<=200000)，表示自然数的个数。
第2~n+1行每行一个自然数。

输出格式
输出包含m行（m为n个自然数中不相同数的个数），按照自然数从小到大的顺序输出。每行输出两个整数，分别是自然数和该数出现的次数，其间用一个空格隔开。

样例1
样例输入1
8 
2 
4 
2 
4 
5 
100 
2 
100

样例输出1
2 3 
4 2 
5 1 
100 2 

限制
每个测试点1s。

来源
NOIP2007提高组
*/

/*
  得分：100
  解题报告：
    排序，再统计即可。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=200020;
int a[MAX];

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  sort(a,a+n);
  /*
  int pos=0;
  while(pos<n){
    int cnt=0;
    do pos++,cnt++; while(a[pos]==a[pos-1] && pos<n);
    printf("%d %d\n",a[pos-1],cnt);
  }
  */
  int pos=0,last=0;
  while(pos<n){
    last=pos;
    while(pos<n && a[pos]==a[last]) pos++;
    printf("%d %d\n",a[last],pos-last);
  }

  return 0;
}
