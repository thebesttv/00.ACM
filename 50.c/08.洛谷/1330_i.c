/*
题目描述
曹是一只爱刷街的老曹，暑假期间，他每天都欢快地在阳光大学的校园里刷街。河蟹看到欢快的曹，感到不爽。河蟹决定封锁阳光大学，不让曹刷街。
阳光大学的校园是一张由N个点构成的无向图，N个点之间由M条道路连接。每只河蟹可以对一个点进行封锁，当某个点被封锁后，与这个点相连的道路就被封锁了，曹就无法在与这些道路上刷街了。非常悲剧的一点是，河蟹是一种不和谐的生物，当两只河蟹封锁了相邻的两个点时，他们会发生冲突。
询问：最少需要多少只河蟹，可以封锁所有道路并且不发生冲突。

输入输出格式
输入格式：
第一行：两个整数N，M
接下来M行：每行两个整数A，B，表示点A到点B之间有道路相连。

输出格式：
仅一行：如果河蟹无法封锁所有道路，则输出“Impossible”，否则输出一个整数，表示最少需要多少只河蟹。

输入输出样例
输入样例#1：
3 3
1 2
1 3
2 3

输出样例#1：
Impossible

输入样例#2：
3 2
1 2
2 3
输出样例#2：
1

说明
数据规模
1<=N<=10000，1<=M<=100000，任意两点之间最多有一条道路。
*/

/*
  解题报告：
    这个其实就是二分图染色再每次记录最小的同色顶点数。
    因为每个螃蟹周围不能有其他螃蟹，也就是说一个1周围不能有1，只能有-1，就是二分图染色。
    而最小的螃蟹数其实就是<b>每一个连通块中</b>的最小同色顶点数。
      因为一个二分图（顶点数>1）中，如果选择一种颜色的顶点放螃蟹，那就要放满所有该颜色的顶点，如果不放满，则不能覆盖所有边。
        在二分图中，颜色为1的顶点的出边数=颜色为-1的顶点的出边数。
    要注意的是，不能将整张图染完色后再取最小值，而是要在主函数每次进入dfs后取最小值再将计数清零为下一次dfs服务。
      例如，对于这张有三个连通块的图：

        1--2--3
        4--5--6
        8--7--9

      颜色为1的节点为 1,3,4,6,7 有5个，颜色为0的节点为 2,5,8,9 有4个，但答案不是4而是3（放在2,5,7上）
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

const int MAXN=10020;
const int MAXM=100020;
int n,m,c[MAXN];
struct Edge{
  int v,next;
}edge[MAXM<<1];
int se[MAXN],tailE=1;
int cnt1,cnt2;

inline void addEdge(int u, int v){
  int t=tailE++;
  edge[t]=(Edge){v,se[u]}; se[u]=t;
}
bool dfs(int u, int col){
  c[u]=col; col==1 ? cnt1++ : cnt2++;
  for(int i=se[u],v;i;i=edge[i].next){
    if(c[v=edge[i].v]==col) return false;
    else if(!c[v] && !dfs(v,3-col)) return false;
  }
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    addEdge(u,v); addEdge(v,u);
  }

  int ans=0;
  FORR(i,1,n) if(!c[i]){
    cnt1=0,cnt2=0;
    if(!dfs(i,1)) {printf("Impossible\n"); return 0;}
    ans+=min(cnt1,cnt2);
  }
  printf("%d\n",ans);

  return 0;
}






























/*
const int MAX=10020;
int n,m;
VR<int> G[MAX];
int col[MAX],cnt1,cnt2;

bool dfs(int u, int c){
  col[u]=c;
  if(c==1) cnt1++; else cnt2++;
  FOR(i,0,G[u].size()){
    int v=G[u][i];
    if(col[v]==c || (!col[v] && !dfs(v,-c))) return false;
  }
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    G[u].push_back(v); G[v].push_back(u);
  }

  bool flag=1;
  int sum=0;
  FORR(i,1,n) if(!col[i] && G[i].size()){ //不染孤点
    cnt1=0; cnt2=0; //<b>对每个连通块重新计数并取其中小的为答案</b>
    if(!dfs(i,1)) {flag=0; break;}
    sum+=min(cnt1,cnt2);
  }
  if(!flag) printf("Impossible\n");
  else printf("%d\n",sum);

  return 0;
}
*/
