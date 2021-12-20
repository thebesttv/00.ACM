/*
题目描述
策策同学特别喜欢逛公园。公园可以看成一张 N 个点 M 条边构成的有向图，且没有自环和重边。其中 1 号点是公园的入口， N 号点是公园的出口，每条边有一个非负权值，代表策策经过这条边所要花的时间。
策策每天都会去逛公园，他总是从 1 号点进去，从 N 号点出来。
策策喜欢新鲜的事物，它不希望有两天逛公园的路线完全一样，同时策策还是一个 特别热爱学习的好孩子，它不希望每天在逛公园这件事上花费太多的时间。如果 1 号点 到 N 号点的最短路长为 d ，那么策策只会喜欢长度不超过 d+K 的路线。
策策同学想知道总共有多少条满足条件的路线，你能帮帮它吗？
为避免输出过大，答案对 P 取模。
如果有无穷多条合法的路线，请输出 -1 。

输入输出格式
输入格式：
第一行包含一个整数 T, 代表数据组数。
接下来T组数据，对于每组数据：
第一行包含四个整数 N,M,K,P，每两个整数之间用一个空格隔开。
接下来M行，每行三个整数ai,bi,ci，代表编号为 ai,bi 的点之间有一条权值为 ci 的有向边，每两个整数之间用一个空格隔开。

输出格式：
输出文件包含 T 行，每行一个整数代表答案。

输入输出样例
输入样例#1：
2
5 7 2 10
1 2 1
2 4 0
4 5 2
2 3 2
3 4 1
3 5 2
1 5 3
2 2 0 10
1 2 0
2 1 0

输出样例#1：
3
-1

样例解释1
对于第一组数据，最短路为 3。 1 – 5, 1 – 2 – 4 – 5, 1 – 2 – 3 – 5 为 3 条合法路径。

测试数据与约定
对于 100% 的数据，N<=100000, M<=200000, K<=50, 1<=P<=10^9, 1<=ai,bi<=N, 0<=ci<=1000
*/

/*
  得分：10
  解题报告：
    考试的时候直接写了个10分的暴力就结束了……无奈啊
  正解：
    貌似 D1 的确少了点 DP ，那就算作这道题使用 DP 的原因吧 XD
    令 f[u][k] 表示从1到u，距离为dis[u]+k的路径条数，其中dis[u]表示从1到u的最短路长度，则：
      f[u][k] -> f[v][dis[u]+k+w-dis[v]]
    也可得：
      f[u][k] = sum{ f[v][dis[u]+k-w-dis[v]] | 存在v指向u}
    
    虽然方程确定了，而顺序却不容易递推，因为可能存在环。所以采用记忆化搜索。
    如果没有零环，记忆化搜索可以不重不漏遍历所有的状态。（每个当前正在被计算的状态不会被再次访问，最多只会等到它已被算完的时候再次访问）

    但是还需要判断零环。
    可以发现（虽然我不知道是怎么发现的吧），若一个状态 (u,k) **正在被计算的时候**再次被访问到，也就说明一开始从 u **经过了一个环**又来到 u ，而因为 k 不变，那么这个环也就是零环。也就是说，使用类似于拓扑排序的判断方法即可判零环。
      令 c[u][k] ，为 -1 表示正在被计算； 1 表示已被算完； 0 表示没被计算。
    
    复杂度：O(KN)。
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

const int MAXN=100020;
const int MAXM=200020;
const int INF=0x3f3f3f3f;
int n,m,k,p,check_f[MAXN][60];
int dis[MAXN];
int c[MAXN][60];  //-1：正在计算，1：已经计算，0：未计算
struct Edge{
  int u,w,next;
}from[MAXM],to[MAXM]; //from为记忆化搜索服务，to为最短路服务
int se[MAXN],tailS=1;
int ee[MAXN],tailE=1;
struct Node{  //for Dij
  int u,d;
  bool operator < (const Node & b) const { return d>b.d; };
};
bool have0cir;  //是否有零环

inline void addEdge(int u, int v, int w){
  int t=tailS++;
  to[t]=(Edge){v,w,se[u]}; se[u]=t;
  t=tailE++;
  from[t]=(Edge){u,w,ee[v]}; ee[v]=t;
}
void Dij(int s);
int f(int u, int k){
  if(k<0 || have0cir) return 0; //不懂为什么可能碰到 k<0 的情况……
  int & st=c[u][k];
  if(st==-1) {have0cir=1; return -INF;} //有零环
  if(st==1) return check_f[u][k];
  st=-1;  //正在计算
  LL ans=0; int v;
  if(u==1 && k==0) ans=1; //<b> </b>
  for(int i=ee[u];i;i=from[i].next){
    v=from[i].u;
    ans += f(v,k+dis[u]-from[i].w-dis[v]);
  }
  st=1; //计算完
#ifdef DEBUG
  printf("  f(%d,%d): %d\n",u,d,(int)(ans%p));
#endif
  return check_f[u][k]=ans%p;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(check_f,0); have0cir=0; MST(c,0);
    MST(se,0); MST(ee,0); tailS=tailE=1;

    scanf("%d%d%d%d",&n,&m,&k,&p);
    int u,v,w;
    FOR(i,0,m){
      scanf("%d%d%d",&u,&v,&w);
      addEdge(u,v,w);
    }

    Dij(1);

    LL ans=0;
    FORR(i,0,k){
      ans+=f(n,i);
    }
    ans%=p;
    printf("%d\n",have0cir ? -1 : (int)ans);
  }

  return 0;
}

void Dij(int s){
  MST(dis,0x3f); dis[s]=0;
  PQ<Node> q; q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u,v;
    if(dis[u]!=t.d) continue;
    for(int i=se[u];i;i=to[i].next)
      if(dis[v=to[i].u]>t.d+to[i].w){
        dis[v]=t.d+to[i].w;
        q.push((Node){v,dis[v]});
      }
  }
}
