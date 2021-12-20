/*
题目描述
给出一个N个顶点M条边的无向无权图，顶点编号为1～N。问从顶点1开始，到其他每个点的最短路有几条。

输入输出格式
输入格式：
输入第一行包含2个正整数N，M，为图的顶点数与边数。
接下来M行，每行两个正整数x, y，表示有一条顶点x连向顶点y的边，请注意可能有自环与重边。

输出格式：
输出包括N行，每行一个非负整数，第i行输出从顶点1到顶点i有多少条不同的最短路，由于答案有可能会很大，你只需要输出mod 100003后的结果即可。如果无法到达顶点i则输出0。

输入输出样例
输入样例#1：
5 7
1 2
1 3
2 4
3 4
2 3
4 5
4 5

输出样例#1：
1
1
1
2
4

说明
1到5的最短路有4条，分别为2条1-2-4-5和2条1-3-4-5（由于4-5的边有2条）。
对于20%的数据，N ≤ 100；
对于60%的数据，N ≤ 1000；
对于100%的数据，N<=1000000，M<=2000000。
*/

/*
  解题报告：
    最短路加上一个f数组计数即可。
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

const int MAX=1000020;
const int MOD=100003;
const int INF=0x3f3f3f3f;
int n,m;
VR<int> G[MAX];
struct Node{
  int u,d;
  bool operator < (const Node & b) const {return d>b.d;}
};
PQ<Node> q;
int d[MAX],f[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    G[u].push_back(v); G[v].push_back(u);
  }

  MST(d,0x3f); d[1]=0; f[1]=1;
  q.push((Node){1,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(t.d!=d[u]) continue;
    FOR(i,0,G[u].size()){
      int v=G[u][i];
      if(d[v]>d[u]+1){
        d[v]=d[u]+1;
        f[v]=f[u];
        q.push((Node){v,d[v]});
      }else if(d[v]==d[u]+1) (f[v]+=f[u])%=MOD;
    }
  }
  FORR(i,1,n) printf("%d\n",f[i]);

  return 0;
}
