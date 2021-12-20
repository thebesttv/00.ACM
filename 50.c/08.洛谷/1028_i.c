/*
题目描述
我们要求找出具有下列性质数的个数(包含输入的自然数n):
先输入一个自然数n(n<=1000),然后对此自然数按照如下方法进行处理:
  1.不作任何处理;
  2.在它的左边加上一个自然数,但该自然数不能超过原数的一半;
  3.加上数后,继续按此规则进行处理,直到不能再加自然数为止.

输入格式：
一个自然数n(n<=1000)

输出格式：
一个整数，表示具有该性质数的个数。

输入输出样例
输入样例#1：
6

输出样例#1：
6

说明
输入6,满足条件的数为
6,16,26,126,36,136
*/

/*
  解题报告：
    具体怎么想到DP的就不说了（毕竟我没想到 XD）
    就说说那个脑洞大开的题解吧 :D
    首先，可以看到f函数中可以改为前缀和，也就是把
      FORR(i,1,t) a+=f(i);
    改为
      a = sum{f(1:t)} +1;
    然后，让我们脑洞放开一点，可以看出
      sum{ f(1:t) } = sum{ f(1:n/2) }
                    = f(n/2) + f(n/2-1) + f(n/2-2) + ... + f(1)
                    = f(n/2) + sum{ f(i) | 1<=i<=(n-2)/2 }  //这一步的确需要大开脑洞
                    = f(n/2) + f(n-2)
    那么我们就得到
      f(n) = f(n/2) + f(n-2) + 1
    于是大功告成 yeah~
*/

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

const int MAX=1020;
int check[MAX];
//令 f[i] 表示对于i，满足性质的数的个数，则
// f[i] = sum{ f[1 : i/2] } +1  //对于 i 共有三种决策

int f(int n){
  int & a=check[n];
  if(a!=-1) return a;
  a=1;  //<b> </b>
  int t=n/2;
  FORR(i,1,t) a+=f(i);
  return a;
}

int main(void){
  MST(check,-1); check[1]=1;
  int n; scanf("%d",&n);
  printf("%d\n",f(n));

  return 0;
}

/*
//对n>400，时间过长
void Solve(register double n, register int ori);  //当前数为n，n的最高位为ori
long long cou;

int main(void){
  int n, ori;
  scanf("%d",&n); ori=n;
  Solve(n,ori);
  printf("%lld\n",cou);

  return 0;
}

void Solve(register double n, register int ori){
  ori/=2; ++cou;
  if(ori<1) return; //注意边界条件位置
  for(register int i=1;i<=ori;++i){ //在n左边放数
    register double temp=i;
    while(temp<n) temp*=10; //扩大temp使得其比n量级大1
    Solve(temp+n,i);
  }
}
*/
