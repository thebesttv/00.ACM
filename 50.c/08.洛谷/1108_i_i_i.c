/*
题目描述
“低价购买”这条建议是在奶牛股票市场取得成功的一半规则。要想被认为是伟大的投资者，你必须遵循以下的问题建议:“低价购买；再低价购买”。每次你购买一支股票,你必须用低于你上次购买它的价格购买它。买的次数越多越好!你的目标是在遵循以上建议的前提下，求你最多能购买股票的次数。你将被给出一段时间内一支股票每天的出售价(2^16范围内的正整数)，你可以选择在哪些天购买这支股票。每次购买都必须遵循“低价购买；再低价购买”的原则。写一个程序计算最大购买次数。

这里是某支股票的价格清单：

日期  1  2  3  4  5  6  7  8  9 10 11 12
价格 68 69 54 64 68 64 70 67 78 62 98 87

最优秀的投资者可以购买最多4次股票，可行方案中的一种是：

日期  2  5  6 10
价格 69 68 64 62

输入输出格式
输入格式：
第1行: N (1 <= N <= 5000)，股票发行天数
第2行: N个数，是每天的股票价格。

输出格式：
输出文件仅一行包含两个数:最大购买次数和拥有最大购买次数的方案数(<=2^31)当二种方案“看起来一样”时（就是说它们构成的价格队列一样的时候）,这2种方案被认为是相同的。

输入输出样例
输入样例#1：
12
68 69 54 64 68 64 70 67 78 62 98 87

输出样例#1：
4 2
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
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=5020;
int n,a[MAX];
int f[MAX]; LL g[MAX];
//f[i]: 以a[i]结尾的最大下降子序列长度
//f[i] = max{ f[j]+1 | j<i && a[j]>a[i] }
//g[i]: 以a[i]结尾的最大下降子序列个数（去重）

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  int tMax=0; //最长下降子序列的长度
  FORR(i,1,n){
    int & t=f[i]=1;
    FOR(j,1,i) if(a[j]>a[i])
      t=max(t,f[j]+1);
    tMax=max(tMax,f[i]);
  }

  LL ans=0;
  FORR(i,1,n){  //计算g
    LL & t=g[i];
    if(f[i]==1) t=1;  //<b> </b>
    FOR(j,1,i)
      if(f[j]+1==f[i] && a[j]>a[i]) t+=g[j];
      else if(f[j]==f[i] && a[j]==a[i]) t=0;  //只是到当前变为0，不能break，后面还可能有不重复的
    if(f[i]==tMax) ans+=t;
  }
  printf("%d %lld\n",tMax,ans);

  return 0;
}

/*
const int MAX=5020;
const LL D=(1LL<<60)+7;
int a[MAX],f[MAX],n,ans;
LL g[MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  FOR(i,0,n){
    f[i]=1,g[i]=1;
    FOR(j,0,i) if(a[j]>a[i])
      if(f[j]+1>f[i]) f[i]=f[j]+1,g[i]=g[j];
      else if(f[j]+1==f[i]) g[i]++;
    ans=max(ans,f[i]);
  }
  LL sum=0;
  ROR(i,n-1,0) if(f[i]==ans) sum+=g[i];
  printf("%d %lld\n",ans,sum);

  return 0;
}
*/
