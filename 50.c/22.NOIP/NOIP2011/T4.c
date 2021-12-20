/*
描述
给定一个多项式(ax + by)^k，请求出多项式展开后x^n * y^m项的系数。

格式
输入格式
共一行，包含5个整数，分别为a，b，k，n，m，每两个整数之间用一个空格隔开。

输出格式
输出共1行，包含一个整数，表示所求的系数，这个系数可能很大，**输出对10007取模后的结果**。

样例1
样例输入1
1 1 3 1 2

样例输出1
3

限制
1s

提示
对于30%的数据，有0 ≤ k ≤ 10；
对于50%的数据，有a = 1, b = 1；
对于100%的数据，有0 ≤ k ≤ 1000，0 ≤ n, m ≤ k，且n+m = k，0 ≤ a，b ≤ 1,000,000.

来源
NOIp2011提高组Day2第一题
*/

/*
  得分：100
  解题报告：
    计算组合数即可。
    注：除非使用逆元，否则不可使用带有除法的递推式
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MOD=10007;
const int MAX=1020;
int C[MAX][MAX];

int pow_mod(int a, int n){
  if(n==0) return 1;
  if(n==1) return a%MOD;
  int ans=pow_mod(a,n/2);
  ans=1LL*ans*ans%MOD;
  if(n&1) ans=1LL*ans*a%MOD;
  return ans;
}

int main(void){
  for(int i=0;i<MAX;i++){
    C[i][0]=1;
    for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
  }
  int a,b,k,n,m; scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
  int pa=pow_mod(a,n);
  int pb=pow_mod(b,m);
  int ans=1LL*pa*pb%MOD*C[k][n]%MOD;
  printf("%d\n",ans);

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MOD=10007;
const int MAX=1020;
int check[MAX][MAX];

int C(int n, int k){
  int & a=check[n][k];
  if(a!=-1) return a;
  if(n==k || k==0) a=1;
  else a=(C(n-1,k-1)+C(n-1,k))%MOD;
  return a;
}

int pow_mod(int a, int n){
  if(n==0) return 1;
  if(n==1) return a%MOD;
  int ans=pow_mod(a,n/2);
  ans=1LL*ans*ans%MOD;
  if(n&1) ans=1LL*ans*a%MOD;
  return ans;
}

int main(void){
  memset(check,-1,sizeof(check));
  int a,b,k,n,m; scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
  int pa=pow_mod(a,n);
  int pb=pow_mod(b,m);
  int ans=1LL*pa*pb%MOD*C(k,n)%MOD;
  printf("%d\n",ans);

  return 0;
}
*/
