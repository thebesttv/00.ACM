/*
题目描述
农夫约翰的奶牛们喜欢通过电邮保持联系，于是她们建立了一个奶牛电脑网络，以便互相交流。这些机器用如下的方式发送电邮：如果存在一个由c台电脑组成的序列a1,a2,...,a(c)，且a1与a2相连，a2与a3相连，等等，那么电脑a1和a(c)就可以互发电邮。
很不幸，有时候奶牛会不小心踩到电脑上，农夫约翰的车也可能碾过电脑，这台倒霉的电脑就会坏掉。这意味着这台电脑不能再发送电邮了，于是与这台电脑相关的连接也就不可用了。

有两头奶牛就想：如果我们两个不能互发电邮，至少需要坏掉多少台电脑呢？请编写一个程序为她们计算这个最小值。
以如下网络为例：

 1 - 3 - 2

这张图画的是有2条连接的3台电脑。我们想要在电脑1和2之间传送信息。电脑1与3、2与3直接连通。如果电脑3坏了，电脑1与2便不能互发信息了。

输入输出格式
输入格式：
第一行 四个由空格分隔的整数：N,M,c1,c2.N是电脑总数(1<=N<=100)，电脑由1到N编号。M是电脑之间连接的总数(1<=M<=600)。最后的两个整数c1和c2是上述两头奶牛使用的电脑编号。连接没有重复且均为双向的(即如果c1与c2相连，那么c2与c1也相连)。两台电脑之间至多有一条连接。电脑c1和c2不会直接相连。
第2到M+1行 接下来的M行中，每行包含两台直接相连的电脑的编号。

输出格式：
一个整数表示使电脑c1和c2不能互相通信需要坏掉的电脑数目的最小值。

输入输出样例
输入样例#1：
3 2 1 2
1 3
2 3

输出样例#1：
1
*/

/*
  解题报告：
    题意：删除最少的点，使得 c1(s) 无法到 c2(t) 。
    将每个点 u 拆成 u1,u2 ，并建立 u1->u2 的容量为 1 的边。
    若有 u->v 的边，则建立 u2->v1, u1->v2 的容量为 INF 的两条边。
    然后从 s2 到 t1 跑最大流即可。
    参考洛谷上的题解，然而我并没有弄懂为什么是这样的……
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

const int MAXN=120;
const int MAXM=620;
const int INF=0x3f3f3f3f;
int n,m,s,t;
struct Edge{
  int u,v,cap,flow,next;
}edge[MAXM*10];
int tailE;
VR<int> G[MAXN<<1];
int a[MAXN<<1],p[MAXN<<1];
int q[MAXN<<1],head,tail;

inline void addEdge(int u, int v, int cap){
  edge[tailE++]=(Edge){u,v,cap,0};
  edge[tailE++]=(Edge){v,u,0,0};
  G[u].push_back(tailE-2);
  G[u].push_back(tailE-1);
}
int MF(int s, int t){
  int flow=0;
  while(1){
    MST(a,0); a[s]=INF;
    head=tail=0; q[tail++]=s;
    while(head<tail){
      int u=q[head++];
      FOR(i,0,G[u].size()){
        Edge & e = edge[G[u][i]];
        if(!a[e.v] && e.cap>e.flow){
          a[e.v]=min(a[u],e.cap-e.flow);  //是 min 而非 max
          p[e.v]=G[u][i];
          q[tail++]=e.v;
        }
      }
      if(a[t]) break;
    }
    if(!a[t]) break;
    int tf=a[t];
    for(int u=t,tp;u!=s;u=edge[tp].u){ //<b> </b>
      tp=p[u];
      edge[tp].flow+=tf;
      edge[tp^1].flow-=tf;
    }
    flow+=tf;
  }
  return flow;
}

int main(void){
  scanf("%d%d%d%d",&n,&m,&s,&t);
  FORR(i,1,n) addEdge(i,i+n,1);
  int u,v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    addEdge(u+n,v,INF);
    addEdge(v+n,u,INF);
  }

  int ans=MF(s+n,t);
  printf("%d\n",ans);

  return 0;
}
