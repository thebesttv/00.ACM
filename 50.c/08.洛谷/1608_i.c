/*
题目描述
“RP餐厅”的员工素质就是不一般，在齐刷刷的算出同一个电话号码之后，就准备让HZH,TZY去送快餐了，他们将自己居住的城市画了一张地图，已知在他们的地图上，有N个地方，而且他们目前处在标注为“1”的小镇上，而送餐的地点在标注为“N”的小镇。（有点废话）除此之外还知道这些道路都是单向的，从小镇I到J需要花费D[I,J]的时间，为了更高效快捷的将快餐送到顾客手中，
他们想走一条从小镇1到小镇N花费最少的一条路，但是他们临出发前，撞到因为在路上堵车而生气的FYY，深受启发，不能仅知道一条路线，万一。。。，于是，他们邀请FYY一起来研究起了下一个问题：这个最少花费的路径有多少条？

输入输出格式
输入格式：
输入文件第一行为两个空格隔开的数N，E，表示这张地图里有多少个小镇及有多少边的信息。
下面E行，每行三个数I、J、C，表示从I小镇到J小镇有道路相连且花费为C.（注意，数据提供的边信息可能会重复，不过保证I<>J,1<=I,J<=n）。

输出格式：
输出文件包含两个数，分别是最少花费和花费最少的路径的总数.
两个不同的最短路方案要求：路径长度相同（均为最短路长度）且至少有一条边不重合。
若城市N无法到达则只输出一个("No answer");

输入输出样例
输入样例#1：
5 4
1 5 4
1 2 2
2 5 2
4 1 1

输出样例#1：
4 2

说明
对于30%的数据 N<=20;
对于100%的数据 1<=N<=2000,0<=E<=N*(N-1), 1<=C<=10.
*/

/*
  解题报告：
    没有0边，那么就很方便了。
    在Dij的同时路径计数即可。
    令 f[i] 为1到i的最短路径条数，则
      f[i] = sum{ f[j], j->i && d[j]+w(j,i)==d[i] }
    因为Dij已经遍历了所有的可行路线，直接在Dij的同时计算即可。
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

const int MAX=2020;
const int INF=0x3f3f3f3f;
int n,m,d[MAX],G[MAX][MAX];
struct Node{
  int u,d;
  bool operator < (const Node & b) const { return d>b.d; }
};
PQ<Node> q;
int f[MAX]; bool vis[MAX];

void Dij(int s){
  MST(d,0x3f); d[s]=0; f[s]=1;
  q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u,tw;
    if(d[u]!=t.d) continue;
    FORR(i,1,n) if((tw=G[u][i])<INF && i!=u){ //<b> i!=u </b>
      if(d[i]>t.d+tw){
        d[i]=t.d+tw; q.push((Node){i,d[i]});
        f[i]=f[u];
      }else if(d[i]==t.d+tw){
        f[i]+=f[u];
      }
    }
  }
}

int main(void){
  MST(G,0x3f);
  scanf("%d%d",&n,&m);
  FORR(i,1,n) G[i][i]=0;
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=min(G[u][v],w);
  }

  Dij(1);

  if(d[n]<INF) printf("%d %d\n",d[n],f[n]);
  else printf("No answer\n");

  return 0;
}
