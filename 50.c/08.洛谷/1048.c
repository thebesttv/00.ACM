/*
题目描述
辰辰是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
如果你是辰辰，你能完成这个任务吗？

输入输出格式
输入格式：
输入文件medic.in的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），用一个空格隔开，T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到100之间（包括1和100）的整数，分别表示采摘某株草药的时间和这株草药的价值。

输出格式：
输出文件medic.out包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。

输入输出样例
输入样例#1：
70 3
71 100
69 1
1 2

输出样例#1：
3

说明
对于全部的数据，M <= 100。
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

const int MAX=1020;
int T,M,c[MAX],w[MAX],f[MAX];

inline void ZeroOnePack(int cost, int weight){
  ROR(i,T,cost) f[i]=max(f[i],f[i-cost]+weight);
}

int main(void){
  scanf("%d%d",&T,&M);
  FORR(i,1,M) scanf("%d%d",&c[i],&w[i]);

  FORR(i,1,M) ZeroOnePack(c[i],w[i]);

  printf("%d\n",f[T]);

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int f[1004];

int main(void){
  int m,n; scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int t,v; scanf("%d%d",&t,&v);
    for(int j=n;j>=0;j--){
      if(j>=t) f[j]=max(f[j],f[j-t]+v);
    }
  }
  printf("%d\n",f[n]);

  return 0;
}
*/
