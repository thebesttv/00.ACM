/*
题目描述
一个含有n项的数列(n<=2000000)，求出每一项前的m个数到它这个区间内的最小值。若前面的数不足m项则从第1个数开始，若前面没有数则输出0。

输入输出格式
输入格式：
第一行两个数n，m。
第二行，n个正整数，为所给定的数列。

输出格式：
n行，第i行的一个数ai，为所求序列中第i个数前m个数的最小值。

输入输出样例
输入样例#1：
6 2
7 8 1 4 3 2

输出样例#1：
0
7
7
1
1
3 

说明
数据规模
m≤n≤2000000
*/

#include<iostream>
#include<cstdio>
using namespace std;

int a[2000020];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  int ansMin=1<<30,u=-1;
  printf("0\n"); scanf("%d",&a[1]);
  for(int i=2;i<=n;i++){
    scanf("%d",&a[i]);
    if(u==i-m-1 || u<=0){
      ansMin=1<<30;
      for(int j=max(i-m,1);j<i;j++) if(a[j]<=ansMin) ansMin=a[u=j];
    }
    printf("%d\n",ansMin);
    if(a[i]<=ansMin) ansMin=a[u=i];
  }

  return 0;
}
