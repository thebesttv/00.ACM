/*
题目背景
此题为NOIP2005普及组第三题的疯狂版。
此题为纪念LiYuxiang而生。

题目描述
LiYuxiang是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同种类的草药，采每一种都需要一些时间，每一种也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
如果你是LiYuxiang，你能完成这个任务吗？
此题和原题的不同点：
  1.每种采药可以无限制地疯狂采摘。
  2.药的种类眼花缭乱，采药时间好长好长啊！师傅等得菊花都谢了！

输入输出格式
输入格式：
输入第一行有两个整数T（1 <= T <= 100000）和M（1 <= M <= 10000），用一个空格隔开，T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到10000之间（包括1和10000）的整数，分别表示采摘某种草药的时间和这种草药的价值。

输出格式：
输出一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。

输入输出样例
输入样例#1：
70 3
71 100
69 1
1 2

输出样例#1：
140

说明
对于30%的数据，M <= 1000；
对于全部的数据，M <= 10000，且M*T<10000000(别数了，7个0)。
加油LiYuxiang，第一个AC留给你！
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

const int MAXN=10020;
const int MAXT=100020;

int T,n,c,w,f[MAXT];

inline void CompletePack(int cost, int weight){
  FORR(i,cost,T) f[i]=max(f[i],f[i-cost]+weight);
}

int main(void){
  scanf("%d%d",&T,&n);
  FORR(i,1,n){
    scanf("%d%d",&c,&w);
    CompletePack(c,w);
  }
  printf("%d\n",f[T]);

  return 0;
}






























/*
const int MAXT=100000+20;
const int MAXM=10000+20;
int f[MAXT];
int t[MAXM],v[MAXM];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++) scanf("%d%d",&t[i],&v[i]);
  //for(int i=1;i<=m;i++){
  //  for(int j=0;j<=n;j++){  //<b>正序枚举j</b>
  //    if(j>=t[i]) f[j]=max(f[j],f[j-t[i]]+v[i]);
  //  }
  //}
  for(int i=1;i<=m;i++){
    for(int j=t[i];j<=n;j++){ //j可以从t[i]开始枚举
      f[j]=max(f[j],f[j-t[i]]+v[i]);
    }
  }
  printf("%d\n",f[n]);

  return 0;
}
*/
