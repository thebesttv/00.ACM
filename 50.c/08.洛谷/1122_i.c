/*
题目描述
小明对数学饱有兴趣，并且是个勤奋好学的学生，总是在课后留在教室向老师请教一些问题。一天他早晨骑车去上课，路上见到一个老伯正在修剪花花草草，顿时想到了一个有关修剪花卉的问题。于是当日课后，小明就向老师提出了这个问题：
一株奇怪的花卉，上面共连有N 朵花，共有N-1条枝干将花儿连在一起，并且未修剪时每朵花都不是孤立的。每朵花都有一个“美丽指数”，该数越大说明这朵花越漂亮，也有“美丽指数”为负数的，说明这朵花看着都让人恶心。所谓“修剪”，意为：去掉其中的一条枝条，这样一株花就成了两株，扔掉其中一株。经过一系列“修剪“之后，还剩下最后一株花（也可能是一朵）。老师的任务就是：通过一系列“修剪”（也可以什么“修剪”都不进行），使剩下的那株（那朵）花卉上所有花朵的“美丽指数”之和最大。
老师想了一会儿，给出了正解。小明见问题被轻易攻破，相当不爽，于是又拿来问你。

输入输出格式
输入格式：
输入文件maxsum3.in的第一行一个整数N(1 ≤ N ≤ 16000)。表示原始的那株花卉上共 N 朵花。
第二行有N 个整数，第I个整数表示第I朵花的美丽指数。
接下来N-1行每行两个整数a,b，表示存在一条连接第a 朵花和第b朵花的枝条。

输出格式：
输出文件maxsum3.out仅包括一个数，表示一系列“修剪”之后所能得到的“美丽指数”之和的最大值。
保证绝对值不超过2147483647。

输入输出样例
输入样例#1：
7
-1 -1 -1 1 1 1 0
1 4
2 5
3 6
4 7
5 7
6 7

输出样例#1：
3

数据规模与约定
对于60%的数据，有N≤1000；
对于100%的数据，有N≤16000。
*/

/*
  解题报告：
    树形DP，令 f[i] 表示以节点i为根的子树的权值和，g[i] 表示以i为根的子树（选节点i）的最大权值和，则
      f[i] = sum{ f[j] } + a[i]
      g[i] = sum{ g[j] | g[j]>0 }
    g可以在dfs时顺便表示，不一定要记录。在dfs同时，记录答案。
  注：对于此题，只需任选一个节点建树即可，无论怎样选择，dfs都能计算出最大值。
*/

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

const int MAX=16020;
int n,a[MAX],f[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
bool vis[MAX];
int ansMax=0;

inline void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
int cal_f(int u){
  if(vis[u]) return f[u];
  vis[u]=1;
  int & t=f[u],v; t+=a[u];
  for(int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v])
    t+=cal_f(v);
  return t;
}
int dfs(int u){
  int ans=a[u],v,t;
  vis[u]=1;
  for(int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
    t=dfs(v);
    if(t>0) ans+=t;
  }
  ansMax=max(ansMax,ans);
  return ans;
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    addEdge(u,v); addEdge(v,u);
  }
  cal_f(1);

  MST(vis,0);
  dfs(1);

  printf("%d\n",ansMax);

  return 0;
}
