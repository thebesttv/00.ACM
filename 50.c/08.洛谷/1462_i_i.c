/*
题目背景
在艾泽拉斯大陆上有一位名叫歪嘴哦的神奇术士，他是部落的中坚力量
有一天他醒来后发现自己居然到了联盟的主城暴风城
在被众多联盟的士兵攻击后，他决定逃回自己的家乡奥格瑞玛

题目描述
在艾泽拉斯，有n个城市。编号为1,2,3,...,n。
城市之间有m条双向的公路，连接着两个城市，从某个城市到另一个城市，会遭到联盟的攻击，进而损失一定的血量。
每次经过一个城市，都会被收取一定的过路费（包括起点和终点）。路上并没有收费站。
假设1为暴风城，n为奥格瑞玛，而他的血量最多为b，出发时他的血量是满的。
歪嘴哦不希望花很多钱，他想知道，在可以到达奥格瑞玛的情况下，他所经过的所有城市中最多的一次收取的费用的最小值是多少。

输入输出格式
输入格式：
第一行3个正整数，n，m，b。分别表示有n个城市，m条公路，歪嘴哦的血量为b。
接下来有n行，每行1个正整数，fi。表示经过城市i，需要交费fi元。
再接下来有m行，每行3个正整数，ai，bi，ci(1<=ai，bi<=n)。表示城市ai和城市bi之间有一条公路，如果从城市ai到城市bi，或者从城市bi到城市ai，会损失ci的血量。

输出格式：
仅一个整数，表示歪嘴哦交费最多的一次的最小值。
如果他无法到达奥格瑞玛，输出AFK。

输入输出样例
输入样例#1：
4 4 8
8
5
6
10
2 1 2
2 4 1
1 3 4
3 4 3

输出样例#1：
10

说明
对于60%的数据，满足n≤200，m≤10000，b≤200
对于100%的数据，满足n≤10000，m≤50000，b≤1000000000
对于100%的数据，满足ci≤1000000000，fi≤1000000000，可能有两条边连接着相同的城市。
*/

/*
  解题报告：
    一开始以为是Dij加上一个数组就行，然而再一次想错了。
  正解：
    最多的一次收取的费用的最小值！
    最多的一次收取的费用的最小值！
    最多的一次收取的费用的最小值！
    二分 二分 二分！！！
    二分收取费用的最小值，每次用Dij求出最少的血量消耗。
    二分可行性证明：
      血量消耗关于费用具有单调性。当最小费用越来越小时，可行的节点一定也会变少，那么血量消耗一定不可能变得更少。因为血量消耗的减小是靠更多的点来对其松弛造成的。

    ps: 我真的要好好练二分了。。。
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

const int MAX=10020;
const int INF=0x3f3f3f3f;
int n,m,b;
int w[MAX],d[MAX];
struct Edge{
  int v,w;
};
VR<Edge> G[MAX];
struct Node{
  int u,d;
  bool operator < (const Node & b) const{
    return d>b.d;
  }
};

int Dij(int s, int t, int lim){ //最小费用为lim时的最少消耗血量
  if(lim<w[s] || lim<w[t]) return INF;
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push((Node){s,0});
  while(!q.empty()){
    Node tn=q.top(); q.pop();
    int u=tn.u;
    if(d[u]!=tn.d) continue;
    FOR(i,0,G[u].size()){
      Edge & e=G[u][i];
      if(d[e.v]>d[u]+e.w && w[e.v]<=lim){ //只有当e.v的费用不大于lim时才能更新
        d[e.v]=d[u]+e.w;
        q.push((Node){e.v,d[e.v]});
      }
    }
  }
  return d[t];
}

int main(void){
  scanf("%d%d%d",&n,&m,&b);
  int tMax=0,tMin=INF;
  FORR(i,1,n){
    scanf("%d",&w[i]);
    tMax=max(tMax,w[i]); tMin=min(tMin,w[i]);
  }
  for(int i=0,u,v,c;i<m;i++){
    scanf("%d%d%d",&u,&v,&c);
    G[u].push_back((Edge){v,c});
    G[v].push_back((Edge){u,c});
  }

  int t=Dij(1,n,INF);
  if(t>b) printf("AFK\n");
  else{
    int l=max(tMin,max(w[1],w[n])),r=tMax;
    while(l<r){
      int m=l+(r-l)/2;
      int t=Dij(1,n,m);
#ifdef DEBUG
      printf("  l: %d, r: %d, m: %d, Dij: %d\n",l,r,m,t);
#endif
      if(t>b) l=m+1;
      else r=m;
    }
    printf("%d\n",l);
  }

  return 0;
}
