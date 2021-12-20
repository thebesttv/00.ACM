/*
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。

输入
标准的输入包含若干组测试数据。每组测试数据是一行输入数据,包括两个整数N 和 K。
(0 < N <= 50, 0 < K <= N)

输出
对于每组测试数据，输出以下三行数据:
第一行: N划分成K个正整数之和的划分数目
第二行: N划分成若干个不同正整数之和的划分数目
第三行: N划分成若干个奇正整数之和的划分数目

样例输入
5 2

样例输出
2
3
3

提示
第一行: 4+1, 3+2,
第二行: 5，4+1, 3+2
第三行: 5，1+1+3, 1+1+1+1+1+1 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=52;
int check1[MAX][MAX][MAX];
int check2[MAX][MAX];
int check3[MAX][MAX];

int f(int n, int m, int k);
int g(int n, int m);
int h(int n, int m);

int main(void){
  int n,k;
  memset(check1,-1,sizeof(check1));
  memset(check2,-1,sizeof(check2));
  memset(check3,-1,sizeof(check3));
  while(scanf("%d%d",&n,&k)==2){
    printf("%d\n",f(n,n,k));
    printf("%d\n",g(n,n));
    printf("%d\n",h(n,n));
  }

  return 0;
}

int f(int n, int m, int k){
  int & a = check1[n][m][k];
  if(a!=-1) return a;
  if(k==1){
    if(m>=n) a = 1;
    else a = 0;
  }else if(k==n){
    if(m>=1) a = 1;
    else a = 0;
  }else if(k>n){
    a = 0;
  }else{  //1<k<n
    if(m==1) a = 0; //m==1 && k<n
    else if(m>n) a = f(n,n,k);
    else if(m==n) a = f(n,n-1,k);  //k!=1
    else a = f(n-m,m,k-1) + f(n,m-1,k);
  }
#ifdef DEBUG_1
  printf("  f(%d,%d,%d)=%d\n",n,m,k,a);
#endif
  return a;
}

int g(int n, int m){
  int & a = check2[n][m];
  if(a!=-1) return a;
  if(m==1){
    if(n==1) a = 1;
    else a = 0;
  }else if(m>n){
    a = g(n,n);
  }else if(m==n){
    a = 1+g(n,n-1);
  }else{
    a = g(n-m,m-1) + g(n,m-1);
  }
#ifdef DEBUG_2
  printf("  g(%d,%d)=%d\n",n,m,a);
#endif
  return a;
}

int h(int n, int m){
  int & a = check3[n][m];
  if(a!=-1) return a;
  if(m==1){
    a = 1;
  }else if(m>n){
    a = h( n, (n&1 ? n : n-1) );
  }else if(m==n){
    if(n&1) a = 1 + h(n,m-2);
    else a = h(n,n-1);
  }else{
    if(m&1) a = h(n-m,m) + h(n,m-2);
    else a = h(n,m-1);
  }
#ifdef DEBUG_3
  printf("  h(%d,%d)=%d\n",n,m,a);
#endif
  return a;
}
