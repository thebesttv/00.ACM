/*
题目背景
由于你的帮助，火星只遭受了最小的损失。但gw懒得重建家园了，就造了一艘飞船飞向遥远的earth星。不过飞船飞到一半，gw发现了一个很严重的问题：肚子饿了~
gw还是会做饭的，于是拿出了储藏的食物准备填饱肚子。gw希望能在T时间内做出最美味的食物，但是这些食物美味程度的计算方式比较奇葩，于是绝望的gw只好求助于你了。

题目描述
一共有n件食材，每件食材有三个属性，ai，bi和ci，如果在t时刻完成第i样食材则得到ai-t*bi的美味指数，用第i件食材做饭要花去ci的时间。
众所周知，gw的厨艺不怎么样，所以他需要你设计烹调方案使得美味指数最大

输入输出格式
输入格式：
第一行是两个正整数T和n，表示到达地球所需时间和食材个数。
下面一行n个整数，ai
下面一行n个整数，bi
下面一行n个整数，ci

输出格式：
输出最大美味指数

输入输出样例
输入样例#1：
74 1
502
2
47

输出样例#1：
408

数据范围
对于40%的数据1<=n<=10
对于100%的数据1<=n<=50
所有数字均小于100,000
*/

/*
  解题报告：
  v1.0
    我好弱啊。。。
    这是一道DP题，但因为每件食材在不同的时间有不同的美味指数，因此选择食材的顺序对答案有影响，单纯的01背包不可行。
    考虑将题目转化为01背包，使用贪心。
    设当前在时间为t，对于食材i,j(i<j)
      先i后j的美味指数 d1 = ai - (t+ci)*bi + aj - (t+ci+cj)*bj
      先j后i的美味指数 d2 = aj - (t+cj)*bj + ai - (t+ci+cj)*bi
      若想要使用01背包，则要找出一种食材的序列，使得对每个i,j(i<j)，都有d1>d2（因为01背包中，i一定比j先）
      则令d1>d2，得
        ci*bj < cj*bi
      因此，只要满足该条件，先i后j一定比先j后i更优。
      也就是说，只要一个序列中每个i,j(i<j)都满足此条件，就可以使用01背包。
      那么在01背包之前做一次排序即可。
  v2.0
    不能单纯使用01背包。
      选取物品i所得的收益与i,t都有关
      选择相同的物品，顺序不同，收益不同
    解决方法：贪心
    目的：使得最优解一定可以通过顺序拿取1:n个物品得到，即对n个物品重新排序，使得在新的序列中，对于任意i,j(i<j)都有“先i后j优于先j后i”。
    那么，设当前时间为t，对于食材i,j(i<j)：
      先i后j的美味指数 d1 = ai - (t+ci)*bi + aj - (t+ci+cj)*bj
      先j后i的美味指数 d2 = aj - (t+cj)*bj + ai - (t+ci+cj)*bi
      令d1>d2，得：
        ci*bj < cj*bi
    因此，新序列只需满足该条件，就一定能通过顺序拿取1:n的物品得到最优解，也就可以使用01背包的到了。
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

const int MAX=60;
typedef long long LL;
struct Obj{
  LL a,b,c;
  bool operator < (const Obj & t) const {return c*t.b < t.c*b;}
}obj[MAX];
int n,T;
LL f[100020];

int main(void){
  scanf("%d%d",&T,&n);
  FORR(i,1,n) scanf("%lld",&obj[i].a);
  FORR(i,1,n) scanf("%lld",&obj[i].b);
  FORR(i,1,n) scanf("%lld",&obj[i].c);
  sort(obj+1,obj+1+n);

  FORR(i,1,n){
    Obj & t=obj[i];
    ROR(j,T,t.c) f[j] = max(f[j],f[j-t.c]+t.a-j*t.b);
  }
  LL ansMax=0; FORR(i,1,T) ansMax=max(ansMax,f[i]);
  printf("%lld\n",ansMax);

  return 0;
}
