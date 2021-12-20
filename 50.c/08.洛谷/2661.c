/*
描述
有 n 个同学（编号为 1 到 n）正在玩一个信息传递的游戏。在游戏里每人都有一个固定的信息传递对象，其中，编号为 i 的同学的信息传递对象是编号为 Ti 的同学。
游戏开始时，每人都只知道自己的生日。之后每一轮中，所有人会同时将自己当前所知的生日信息告诉各自的信息传递对象（注意：可能有人可以从若干人那里获取信息， 但是每人只会把信息告诉一个人，即自己的信息传递对象）。当有人从别人口中得知自己的生日时，游戏结束。请问该游戏一共可以进行几轮？

格式
输入格式
输入共 2 行。
第 1 行包含 1 个正整数 n，表示 n 个人。
第 2 行包含 n 个用空格隔开的正整数 T1, T2, ..., Tn，其中第 i 个整数Ti
表示编号为 i 的同学的信息传递对象是编号为 Ti 的同学，Ti≤n 且 Ti≠i。
数据保证游戏一定会结束。

输出格式
输出共 1 行，包含 1 个整数，表示游戏一共可以进行多少轮。

样例1
样例输入1
5
2 4 2 3 1

样例输出1
3

限制
对于30%的数据， n ≤ 200；
对于60%的数据，n ≤ 2500；
对于100%的数据，n ≤ 200000。

样例说明：

     1            1,5              1,5       
  1 ---> 2    1 ------> 2    1 -----------> 2
     2           1,2,3          1,2,3,4,5    
  2 ---> 4    2 ------> 4    2 -----------> 4
     3            3,4             2,3,4      
  3 ---> 2    3 ------> 2    3 -----------> 2
     4            2,4            1,2,3,4     
  4 ---> 3    4 ------> 3    4 -----------> 3
     5             5                5        
  5 ---> 1    5 ------> 1    5 -----------> 1
   第一轮        第二轮           第三轮

游戏的流程如图所示。当进行完第 3 轮游戏后，4 号玩家会听到 2 号玩家告诉他自己的生日，所以答案为 3。当然，第 3 轮游戏后，2 号玩家、3 号玩家都能从自己的消息来源得知自己的生日，同样符合游戏结束的条件。

来源
NOIP 2015 提高组 Day 1 第二题
*/

/*
  解题报告：
    原来可以这么简单。。。并查集什么的完全不需要。。。
    题目要求的就是一个特殊有向图的最小环，说它特殊，就是因为每个点有且只有一条出边。
    因为任意点都只有一条出边，那么任何时刻在任意点的路径都是确定且唯一的。
    那么就告诉我们，想要的到答案，每个点只要访问一次即可。
    于是就可以遍历出答案了。
      对每个点，设置一个dep和mark，mark为mark[i]的搜索记录的深度为dep[i]，搜索到一个点时，如果它已被搜索过且是被当前这一遍搜过的（即mark[u]==cnt）那么就更新ans，如果不是被当前这一遍搜过的就停止搜索；如果该点没被搜索过，那么就记录该点并且向前搜索。
    注：不用担心漏解，因为图的特殊性，可以保证每一个环不会邻接任何环，也就是说没有任意两个环会连在一起。
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

const int MAX=200020;
int n,to[MAX],dep[MAX];
int ansMin=1<<30;
int mark[MAX],cnt;
bool vis[MAX];

void euler(int u, int step){
  if(dep[u]) {if(mark[u]==cnt) ansMin=min(ansMin,step-dep[u]);}
  else {mark[u]=cnt; dep[u]=step; euler(to[u],step+1);}
}

int main(void){
  scanf("%d",&n);
  int v;
  FORR(u,1,n) {scanf("%d",&v); to[u]=v; vis[v]=1;}

  FORR(i,1,n) if(!dep[i]) {cnt++; euler(i,1);}

  printf("%d\n",ansMin);

  return 0;
}
