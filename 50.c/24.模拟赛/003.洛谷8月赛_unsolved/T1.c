/*
题目描述
给定一个整数 n，求将 n 分解为互不相同的不小于 2 的数的乘积的方案数。答案模998244353。

输入输出格式
输入格式：
第一行一个整数 T，表示数据组数。
接下来 T 行，每行一个整数 n，意义如描述所述。

输出格式：
一共 T 行，每行一个整数，表示答案。

输入输出样例
输入样例#1：
1
688

输出样例#1：
6

说明
样例中，因为
688=2×4×86=2×8×43=2×344=4×172=8×86=16×43
所以答案为 6

对于 10% 的数据，保证 n 为质数
对于 20% 的数据，保证 2≤n≤10^4
对于 50% 的数据，保证 2≤n≤10^7
对于 100% 的数据， 保证 2≤n≤10^12
所有数据满足 1≤T≤5
*/

/*
  得分：60
  解题报告：
  一开始想到用动规做，但写出的转移方程怎么也不对，可能是边界条件没有判好。后来发现自己基本不会整数分解，只能重新想，写了一个搜索，最后再加上素数特判，两个点的时间擦线过，剩下四个点光荣地TLE了。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef unsigned long long LLU;
const int MOD=998244353;
int cnt;

inline void dfs(LLU n, LLU last){
  if(n==1) {cnt = cnt==MOD-1 ? 0 : cnt+1; return;}
  for(LLU i=last-1;i>=2;i--) if(n%i==0)
    dfs(n/i,i);
}

bool isprime(LLU n){
  int sq=sqrt(n)+1;
  if(!(n&1)) return false;
  for(int i=3;i<=sq;i+=2) if(n%i==0) return false;
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    LLU n; scanf("%llu",&n);
    cnt=0;
    if(!isprime(n)) dfs(n,n);
    printf("%d\n",cnt);
  }

  return 0;
}
