/*
描述
两只青蛙在网上相识了，它们聊得很开心，于是觉得很有必要见一面。它们很高兴地发现它们住在同一条纬度线上，于是它们约定各自朝西跳，直到碰面为止。可是它们出发之前忘记了一件很重要的事情，既没有问清楚对方的特征，也没有约定见面的具体位置。不过青蛙们都是很乐观的，它们觉得只要一直朝着某个方向跳下去，总能碰到对方的。但是除非这两只青蛙在同一时间跳到同一点上，不然是永远都不可能碰面的。为了帮助这两只乐观的青蛙，你被要求写一个程序来判断这两只青蛙是否能够碰面，会在什么时候碰面。
我们把这两只青蛙分别叫做青蛙A和青蛙B，并且规定纬度线上东经0度处为原点，由东往西为正方向，单位长度1米，这样我们就得到了一条首尾相接的数轴。设青蛙A的出发点坐标是x，青蛙B的出发点坐标是y。青蛙A一次能跳m米，青蛙B一次能跳n米，两只青蛙跳一次所花费的时间相同。纬度线总长L米。现在要你求出它们跳了几次以后才会碰面。

输入
输入只包括一行5个整数x，y，m，n，L，其中x≠y < 2000000000，0 < m、n < 2000000000，0 < L < 2100000000。

输出
输出碰面所需要的跳跃次数，如果永远不可能碰面则输出一行"Impossible"

样例输入
1 2 3 4 5

样例输出
4
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

typedef long long int LL;
void gcd(LL a, LL b, LL & d, LL & x, LL & y){
  if(!b) {d=a; x=1; y=0;}
  else {gcd(b,a%b,d,y,x); y-=x*(a/b);}
}

int main(void){
  LL x,y,m,n,l; scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
  // (x+km)%l == (y+kn)%l
  // x-y + k(m-n) = k'l
  // k'l + k(n-m) = x-y
  //-> k'l + kb = a
  //若 gcd(a,b)=d, 则方程 ax+by=c 在 x 属于 [0,b/d-1] 上有唯一解
  LL a=x-y,b=n-m,d,k,k_;
  gcd(l,b,d,k_,k);
  if(a%d) {printf("Impossible\n"); return 0;}
  n=a/d;
  k*=n; l/=d;
  k=(k%l+l)%l;  //将解控制在[0,l)之内

  printf("%lld\n",k);

  return 0;
}

/*
#include<stdio.h>
long long k,t,d;
long long extended_gcd(long long a,long long b) {
  if (b==0) { k=1; t=0; d=a; return a; }
  else {
    long long tp_gcd;
    tp_gcd=extended_gcd(b,a%b);
    long long temp;
    temp=k;
    k=t;
    t=temp-(a/b)*t;
    return tp_gcd;
  }
}

int main()
{
  long long x,y,m,n,a,b,aa,ll,l;
  while(scanf("%I64d %I64d %I64d %I64d %I64d",&x,&y,&m,&n,&l)!=EOF)
  {
    a=m-n;b=y-x;
    if (a<0) {a=-a;b=-b;}
    extended_gcd(a,l);
    if (b%d!=0) printf("Impossible/n"); 
    else
    {
      k=k*b/d;
      t=t*b/d;
      l=l/d;
      if (k>=0) k=k%l;
      else k=k%l+l;
      printf("%I64d/n",k);
    }

  }
  return 0;
}
*/
