/*
描述
在有向图 G 中，每条边的长度均为 1，现给定起点和终点，请你在图中找一条从起点到 终点的路径，该路径满足以下条件：
路径上的所有点的出边所指向的点都直接或间接与终点连通。
在满足条件 1 的情况下使路径最短。
注意：图 G 中可能存在重边和自环，题目保证终点没有出边。 请你输出符合条件的路径的长度。

格式
输入格式
第一行有两个用一个空格隔开的整数 n 和 m，表示图有 n 个点和 m 条边。
接下来的 m 行每行 2 个整数 x、y，之间用一个空格隔开，表示有一条边从点 x 指向点y。
最后一行有两个用一个空格隔开的整数 s、t，表示起点为 s，终点为 t。

输出格式
输出只有一行，包含一个整数，表示满足题目描述的最短路径的长度。
如果这样的路径不存在，输出-1。

样例1
样例输入1
3 2
1 2
2 1
1 3

样例输出1
-1

样例2
样例输入2
6 6
1 2
1 3
2 6
2 5
4 5
3 4
1 5

样例输出2
3

数据范围
对于30%的数据，0 < n ≤ 10，0 < m ≤ 20；
对于60%的数据，0 < n ≤ 100，0 < m ≤ 2000；
对于100%的数据，0 < n ≤ 10,000，0 < m ≤ 200,000，0 < x，y，s，t ≤ n，x ≠ t。

提示
输入输出样例1说明

      3
   1<--->2

如上图所示，箭头表示有向道路，圆点表示城市。起点 1 与终点 3 不连通，所以满足题目描述的路径不存在，故输出-1。
输入输出样例2说明

   1--->3-->4----+->5
    \           /
     \         /
      +-->2---+---->6

如上图所示，满足条件的路径为 1->3->4->5。注意点 2 不能在答案路径中，因为点 2 连了一条边到点 6，而点 6 不与终点 5 连通。

来源
NOIP2014 提高组 Day2
*/

/*
  得分：90
  解题报告：
    首先，从终点开始倒序进行一遍dfs，得到所有不能连接到终点的点设为非法，称为不可行点。又因为如果最优线路中有一点u，那么u的出边所连接到的v一定要能连接到终点，那么就可以将所有出边连接到不可行点的点也设为非法。
    然后，可以通过动规，令 f(i) 表示从起点到i的最短合法路径的长度，则
      f(i) = min{ f(j)+1 | j->i }
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
VR<int> to[MAX],from[MAX];
bool vis[MAX],ill[MAX]; //ill[i]=1: i can't connect to t
int s,t,n,m;
int check[MAX];

int f(int u){
  int & a=check[u];
  if(a!=-1) return a;
  a=INF;
  if(!ill[u]) ROR(i,from[u].size()-1,0){
    int v=from[u][i];
    a=min(a,f(v)+1);
  }
  return a;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    if(u==v) continue;
    to[u].push_back(v); from[v].push_back(u);
  }
  scanf("%d%d",&s,&t);

  //backward bfs
  queue<int> q;
  q.push(t); vis[t]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    ROR(i,from[u].size()-1,0){
      int v=from[u][i]; if(vis[v]) continue;
      q.push(v); vis[v]=1;
    }
  }
  FORR(i,1,n) if(!vis[i]){  //set illegal
    ill[i]=1;
    ROR(j,from[i].size()-1,0) ill[from[i][j]]=1;
  }

  MST(check,-1); check[s]=0;
  int ans=f(t);
  if(ans>=INF) ans=-1;
  printf("%d\n",ans);

  return 0;
}
