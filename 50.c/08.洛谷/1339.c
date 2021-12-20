/*
题目描述
The good folks in Texas are having a heatwave this summer. Their Texas Longhorn cows make for good eating but are not so adept at creating creamy delicious dairy products. Farmer John is leading the charge to deliver plenty of ice cold nutritious milk to Texas so the Texans will not suffer the heat too much.
FJ has studied the routes that can be used to move milk from Wisconsin to Texas. These routes have a total of T (1 <= T <= 2,500) towns conveniently numbered 1..T along the way (including the starting and ending towns). Each town (except the source and destination towns) is connected to at least two other towns by bidirectional roads that have some cost of traversal (owing to gasoline consumption, tolls, etc.). Consider this map of seven towns; town 5 is the
source of the milk and town 4 is its destination (bracketed integers represent costs to traverse the route):

                              [1]----1---[3]-
                             /               \
                      [3]---6---[4]---3--[3]--4
                     /               /       /|
                    5         --[3]--  --[2]- |
                     \       /        /       |
                      [5]---7---[2]--2---[3]---
                            |       /
                           [1]------

Traversing 5-6-3-4 requires spending 3 (5->6) + 4 (6->3) + 3 (3->4) = 10 total expenses.
Given a map of all the C (1 <= C <= 6,200) connections (described as two endpoints R1i and R2i (1 <= R1i <= T; 1 <= R2i <= T) and costs (1 <= Ci <= 1,000), find the smallest total expense to traverse from the starting town Ts (1 <= Ts <= T) to the destination town Te (1 <= Te <= T).

德克萨斯纯朴的民众们这个夏天正在遭受巨大的热浪！！！他们的德克萨斯长角牛吃起来不错，可是他们并不是很擅长生產富含奶油的乳製品。Farmer John此时以先天下之忧而忧，后天下之乐而乐的精神，身先士卒地承担起向德克萨斯运送大量的营养冰凉的牛奶的重任，以减轻德克萨斯人忍受酷暑的痛苦。
FJ已经研究过可以把牛奶从威斯康星运送到德克萨斯州的路线。这些路线包括起始点和终点先一共经过T (1 <= T <= 2,500)个城镇，方便地标号為1到T。除了起点和终点外地每个城镇由两条双向道路连向至少两个其它地城镇。每条道路有一个通过费用（包括油费，过路费等等）。
给定一个地图，包含C (1 <= C <= 6,200)条直接连接2个城镇的道路。每条道路由道路的起点Rs，终点Re (1 <= Rs <= T; 1 <= Re <= T)，和花费(1 <= Ci <= 1,000)组成。求从起始的城镇Ts (1 <= Ts <= T)到终点的城镇Te(1 <= Te <= T)最小的总费用。

输入输出格式
输入格式：
第1行: 4个由空格隔开的整数: T, C, Ts, Te
第2到第C+1行: 第i+1行描述第i条道路。有3个由空格隔开的整数: Rs, Re和Ci

输出格式：
一个单独的整数表示从Ts到Te的最小总费用。数据保证至少存在一条道路。

输入输出样例
输入样例#1：
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1

输出样例#1：
7

样例说明
5->6->1->4 (3 + 1 + 3)
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

//SPFA
const int MAX=2520;
const int MAXM=6220;
int n,m,s,t;
struct Edge{
  int v,w,next;
}edge[MAXM<<1];
int se[MAX],tailE=1;
int d[MAX],cnt[MAX];
bool inq[MAX];

inline void addEdge(int u, int v, int w){
  int t=tailE++;
  edge[t]=(Edge){v,w,se[u]}; se[u]=t;
}
bool SPFA(int s){
  MST(d,0x3f); MST(inq,0); MST(cnt,0);
  queue<int> q; q.push(s);
  inq[s]=1; d[s]=0; cnt[s]=1;
  while(!q.empty()){
    int u=q.front(),v; q.pop();
    inq[u]=0;
    for(int i=se[u];i;i=edge[i].next){
      v=edge[i].v;
      if(d[v]>d[u]+edge[i].w){
        d[v]=d[u]+edge[i].w;
        if(!inq[v]){
          if(++cnt[v]>=n) return false;
          q.push(v); inq[v]=1;
        }
      }
    }
  }
  return true;
}

int main(void){
  scanf("%d%d%d%d",&n,&m,&s,&t);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w); addEdge(v,u,w);
  }

  SPFA(s);

  printf("%d\n",d[t]);

  return 0;
}

/*
//Bellman Ford
const int MAX=2520;
const int MAXM=6220;
int n,m,s,t;
struct Edge{
  int u,v,w;
}edge[MAXM<<1];
int tail=0;
int d[MAX];

void Bellman_Ford(int s){ //O(nm)
  MST(d,0x3f); d[s]=0;
  FOR(i,1,n)  //迭代 n-1 次
    FOR(j,0,tail){
      Edge & e=edge[j];
      if(d[e.v]>d[e.u]+e.w) d[e.v]=d[e.u]+e.w;
    }
}

int main(void){
  scanf("%d%d%d%d",&n,&m,&s,&t);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    edge[tail++]=(Edge){u,v,w};
    edge[tail++]=(Edge){v,u,w};
  }

  Bellman_Ford(s);

  printf("%d\n",d[t]);

  return 0;
}
*/

/*
//Dij
const int MAX=2520;
const int MAXM=6220;
int n,m,s,t;
struct Edge{
  int v,w,next;
}edge[MAXM<<1];
int se[MAX],tailE=1;
int d[MAX]; bool vis[MAX];

inline void addEdge(int u, int v, int w){
  int t=tailE++;
  edge[t]=(Edge){v,w,se[u]}; se[u]=t;
}
void Dij(int s){
  MST(d,0x3f); d[s]=0;
  FOR(i,0,n){
    int tMin=0x3f3f3f3f,u=-1;
    FORR(j,1,n) if(d[j]<tMin && !vis[j]) tMin=d[u=j];
    vis[u]=1;
    for(int i=se[u];i;i=edge[i].next){
      Edge & e=edge[i];
      if(d[e.v]>d[u]+e.w) d[e.v]=d[u]+e.w;
    }
  }
}

int main(void){
  scanf("%d%d%d%d",&n,&m,&s,&t);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w); addEdge(v,u,w);
  }

  Dij(s);

  printf("%d\n",d[t]);

  return 0;
}
*/

/*
//Dij + heap
const int MAX=2520;
const int MAXM=6220;
int n,m,s,t;
struct Edge{
  int v,w,next;
}edge[MAXM<<1];
int se[MAX],tailE=1;
struct Node{
  int u,d;
  bool operator < (const Node & b) const {return d>b.d;}
};
PQ<Node> q;
int d[MAX];

inline void addEdge(int u, int v, int w){
  int t=tailE++;
  edge[t]=(Edge){v,w,se[u]}; se[u]=t;
}
void Dij(int s){
  MST(d,0x3f); d[s]=0;
  q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(d[u]!=t.d) continue;
    for(int i=se[u];i;i=edge[i].next){
      Edge & e=edge[i];
      if(d[e.v]>t.d+e.w){
        d[e.v]=t.d+e.w;
        q.push((Node){e.v,d[e.v]});
      }
    }
  }
}

int main(void){
  scanf("%d%d%d%d",&n,&m,&s,&t);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w); addEdge(v,u,w);
  }

  Dij(s);

  printf("%d\n",d[t]);

  return 0;
}
*/

/*
const int MAX=2520;
int n,m,s,t;
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
PQ<Node> q;
int d[MAX];

int main(void){
  scanf("%d%d%d%d",&n,&m,&s,&t);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    G[u].push_back((Edge){v,w});
    G[v].push_back((Edge){u,w});
  }

  MST(d,0x3f); d[s]=0;
  q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(t.d!=d[u]) continue;
    FOR(i,0,G[u].size()){
      Edge & e=G[u][i];
      if(d[e.v]>d[u]+e.w){
        d[e.v]=d[u]+e.w;
        q.push((Node){e.v,d[e.v]});
      }
    }
  }
  printf("%d\n",d[t]);

  return 0;
}
*/
