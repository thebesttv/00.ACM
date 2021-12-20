/*
题目描述
也许你早就知道阶乘的含义，N阶乘是由1到N相乘而产生，如：
12! = 1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9 x 10 x 11 x 12 = 479,001,600
12的阶乘最右边的非零位为6。
写一个程序，计算N(1<=N<=50,000,000)阶乘的最右边的非零位的值。
注意:10,000,000！有2499999个零。

输入输出格式
输入格式：
仅一行包含一个正整数N。

输出格式：
单独一行包含一个整数表示最右边的非零位的值。

输入输出样例
输入样例#1：
12

输出样例#1：
6
*/

//还是不知道为什么膜大一点就可以。。。
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

typedef long long LL;

int main(void){
  int n; scanf("%d",&n);
  LL ans=1;
  FORR(i,2,n){
    ans*=i;
    while(ans%10==0) ans/=10;
    ans%=1000000;
  }
  printf("%lld\n",ans%10);


  return 0;
}
