/*
  解题报告：
    ans = 第1个盒子的总期望 + 第2个盒子的总期望
    第i个盒子的总期望 = sum{ 第i天该盒子空，另一个盒子的期望 }
    1. 第一个盒子空
      假设当该盒子空的时候，另一个盒子还剩下 i 颗糖。
      那么一共拿了 2n-i+1 次（加上这次），拿走了 2n-i 颗糖果，其中第一个盒子拿了 n 颗，第二个盒子拿了 n-i 颗。
      那么一共的可能性 pos1(i) = C(2n-i,n) * p^(n+1) * (1-p)^(n-i) 。
        如果已知拿的顺序，则不需要乘组合数，但这里求的是所有顺序的可能之和
        因为最后一次有开了第一个盒子，所以 p 的幂是 n+1 而非 n 。
      那么期望即为 sum{ i*pos(i) | 0<=i<=n }
      但如果直接这么做，组合数会很大，而 p 和 1-p 的乘积会很小，会丧失很多精度。
      要改进，可以取对数。
      令 v1(i) = ln(pos1(i)) = ln(C(2n-i,n)) + (n+1)ln(p) + (n-i)ln(1-p)
      答案即为 sum{ i*e^v1(i) | 0<=i<=n } 。
    2. 第二个盒子空
      同理，得 v2(i) = ln(C(2n-i,n)) + (n+1)ln(1-p) + (n-i)ln(p)
      答案即为 sum{ i*e^v2(i) | 0<=i<=n } 。
    所以，答案为 sum{ i*(e^v1(i) + e^v2(i)) | 0<=i<=n }
    但是，n 高达 2*10^5，只能用 O(n) 的方法递推 C ，而 C 有可能很大，那么也只能取对数求解。
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
typedef long long LL;
typedef long long unsigned LLU;

int n;
double p;

double lnC(int n, int m);

int main(void){
  int kase=0;
  while(scanf("%d%lf",&n,&p)==2){ //O(n)
    double lnC=0; // C(n,m) = (n+1-m)/(n+1) * C(n+1,m)，求和同时递推
    double v1,v2;
    const double lnp1=log(p),lnp2=log(1-p);
    //v1(i) = ln(pos1(i)) = ln(C(2n-i,n)) + (n+1)ln(p) + (n-i)ln(1-p)
    //v2(i) = ln(C(2n-i,n)) + (n+1)ln(1-p) + (n-i)ln(p)
    //ans = sum{ i*(e^v1(i) + e^v2(i)) | 0<=i<=n }
  }

  return 0;
}
