/*
题目背景
SOL君（炉石主播）和SOL菌（完美信息教室讲师）是好朋友。

题目描述
SOL君很喜欢阶乘。而SOL菌很喜欢研究进制。
这一天，SOL君跟SOL菌炫技，随口算出了n的阶乘。
SOL菌表示不服，立刻就要算这个数在k进制表示下末尾0的个数。
但是SOL菌太菜了于是请你帮忙。

输入输出格式
输入格式：
本题包含多组数据。
每组输入仅包含一行：两个整数n，k。

输出格式：
对于每组输入，输出一个整数：n!在k进制下后缀0的个数。

输入输出样例
输入样例#1：
10 40

输出样例#1：
2

说明
对于20%的数据，n <= 1000000， k = 10
对于另外20%的数据，n <= 20， k <= 36
对于60%的数据，n <= 10^15，k <= 10^12
对于100%的数据，n <= 10^18，k <= 10^16
*/

/*
  得分：0
  解题报告：
    没有看到是多组输入，然后就彻底炸了。。。
    想是想到了质因数分解，然而我想的是把1:n都分解掉，然后就直接T了。。。
  正解：
    将k质因数分解成 p1^a1 * p2^a2 * ... * pm^am
    将 n! 写成 c * p1^b1 * p2^b2 * ... * pm^bm 的形式，不用将它全都分解
    答案即为 min{ floor(bi/ai) }
    n! 的分解方法：
      令 n! 分解后其中一项为 p^e，则
        e = [n/(p^1)] + [n/(p^2)] + [n/(p^3)] + ... （[n]表示floor(n)）
      n/p是1:n中所有能被p整除的数的个数，而因为有些数不仅能被p整除，还能被p^2整除，那么它的系数就是2，而n/p只算了1，因此再在n/p的基础上加上n/p^2，以此类推。
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

typedef long long LL;
LL n,k;
struct Node{
  LL n,cnt;
};

int main(void){
  while(scanf("%lld%lld",&n,&k)==2){
    VR<Node> v;
    for(LL i=2;i*i<=k;i++) if(k%i==0){
      LL cnt=0;
      while(k%i==0) k/=i,cnt++;
      v.push_back((Node){i,cnt});
    }
    if(k>1) v.push_back((Node){k,1});

    LL ansMin=~(1LL<<63);
    FOR(i,0,v.size()){
      LL t=v[i].n,sum=0;
      for(LL j=t;j<=n;j*=t) sum+=n/j;
      ansMin=min(ansMin,sum/v[i].cnt);
    }
    printf("%lld\n",ansMin);
  }

  return 0;
}

/*
typedef long long unsigned LLU;
const int MAX=100;
int n,k;
int prime[MAX],sep[MAX],ks[MAX];
int tail=0;

bool is_prime(int n){
  int sq=sqrt(n+0.5);
  FORR(i,2,sq) if(n%i==0) return false;
  return true;
}

int main(void){
  prime[tail++]=2; FORR(i,3,36) if(is_prime(i)) prime[tail++]=i;
  if(n>=2) sep[0]=1;
  scanf("%d%d",&n,&k);
  if(k<=36){
    FORR(i,3,n){
      int t=i;
      FOR(j,0,tail)
        while(t%prime[j]==0) {t/=prime[j]; sep[j]++;}
    }
    int t=k;
    FOR(j,0,tail)
      while(t%prime[j]==0) {t/=prime[j]; ks[j]++;}

    int ansMin=1<<30;
    FOR(i,0,tail) if(ks[i])
      ansMin=min(ansMin,sep[i]/ks[i]);
    printf("%d\n",ansMin);
  }else{
    LLU sum=1;
    int cnt=0;
    FORR(i,2,n){
      sum*=i;
      while(sum%k==0) sum/=k,cnt++;
      sum%=k;
    }
    printf("%d\n",cnt);
  }
  return 0;
}
*/
