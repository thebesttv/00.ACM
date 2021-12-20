/*
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数。

输入
标准的输入包含若干组测试数据。每组测试数据是一个整数N(0 < N <= 50)。

输出
对于每组测试数据，输出N的划分数。
样例输入
5

样例输出
7

提示
5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int check[100][100];

int f(int n, int m){  //求解：使用小于等于m的数组成n的种类
                      //f(n,m) = 1, n=1 || m=1
                      //         f(n,n), m>n
                      //         1 + f(n,n-1), m=n
                      //         f(n-m,m) + f(n,m-1), m<n
  if(check[n][m]!=-1) return check[n][m];
  int & a = check[n][m];
  if(n==1 || m==1) return a = 1;
  else if(n<m)     return a = f(n,n);
  else if(n==m)    return a = 1+f(n,n-1);
  else             return a = f(n-m,m) + f(n,m-1);
}

int main(void){
  int n;
  memset(check,-1,sizeof(check));
  while(scanf("%d",&n)==1){
    printf("%d\n",f(n,n));
  }

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int cnt=0;
int check[60];

void dfs(int n,int cur){
  if(n==0) {cnt++; return;}
  for(int i=cur;i<=n;i++) dfs(n-i,i);
}

int main(void){
  for(int i=1;i<=50;i++){
    cnt=0;
    dfs(i,1);
    check[i]=cnt;
  }
  int n;
  while(scanf("%d",&n)==1){
    printf("%d\n",check[n]);
  }

  return 0;
}
*/
