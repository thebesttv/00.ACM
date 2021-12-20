/*
题目背景
滚粗了的HansBug在收拾旧语文书，然而他发现了什么奇妙的东西。

题目描述
蒟蒻HansBug在一本语文书里面发现了一本答案，然而他却明明记得这书应该还包含一份练习题。然而出现在他眼前的书多得数不胜数，其中有书，有答案，有练习册。已知一个完整的书册均应该包含且仅包含一本书、一本练习册和一份答案，然而现在全都乱做了一团。许多书上面的字迹都已经模糊了，然而HansBug还是可以大致判断这是一本书还是练习册或答案，并且能够大致知道一本书和答案以及一本书和练习册的对应关系（即仅仅知道某书和某答案、某书和某练习册有可能相对应，除此以外的均不可能对应）。既然如此，HansBug想知道在这样的情况下，最多可能同时组合成多少个完整的书册。

输入输出格式
输入格式：
第一行包含三个正整数N1、N2、N3，分别表示书的个数、练习册的个数和答案的个数。
第二行包含一个正整数M1，表示书和练习册可能的对应关系个数。
接下来M1行每行包含两个正整数x、y，表示第x本书和第y本练习册可能对应。（1<=x<=N1，1<=y<=N2）
第M1+3行包含一个正整数M2，表述书和答案可能的对应关系个数。
接下来M2行每行包含两个正整数x、y，表示第x本书和第y本答案可能对应。（1<=x<=N1，1<=y<=N3）

输出格式：
输出包含一个正整数，表示最多可能组成完整书册的数目。

输入输出样例
输入样例#1：
5 3 4
5
4 3
2 2
5 2
5 1
5 3
5
1 3
3 1
2 2
3 3
4 3
输出样例#1：
2

样例说明：
如题，N1=5，N2=3，N3=4，表示书有5本、练习册有3本、答案有4本。
M1=5，表示书和练习册共有5个可能的对应关系，分别为：书4和练习册3、书2和练习册2、书5和练习册2、书5和练习册1以及书5和练习册3。
M2=5，表示数和答案共有5个可能的对应关系，分别为：书1和答案3、书3和答案1、书2和答案2、书3和答案3以及书4和答案3。
所以，以上情况的话最多可以同时配成两个书册，分别为：书2+练习册2+答案2、书4+练习册3+答案3。

数据规模：
对于数据点1, 2, 3，M1，M2<= 20
对于数据点4~10，M1，M2 <= 20000
*/

/*
  解题报告：
    令书为集合{A}，练习册为集合{B}，答案为集合{C}。
    如果单看 A->B 或 A->C，则显然是二分图的最大匹配。
    但看 A->B->C 就不那么显然了，因为 A->B 还有 A->C 都有边，而又不能将 B和C 合并。
    但是，如果将 ABC 换一个顺序，变成 B->A->C 那么就好办很多了。
    可以直接按照 s->B->A->C->t 的顺序建模。如果 Ai 与 Bj 可能对应，则建一条 Bj->Ai 的容量为 1 的有向边；而如果 Ai 与 Cj 可能对应，则建一条 Ai->Cj 的容量为 1 的有向边。还要建立 s->Bi, Ci->t 的边，容量都为 1 。
    但这样还有一个严重的问题：
      若有边 B1->A1, B2->A1, A1->C1, A1->C2 ，则可能出现 B1->A1 和 B2->A1 都满载的情况，即路径 s->B1->A1->C1->t 和 s->B2->A1->C2->t 都成立，那么 A1 就对应了两本练习册和两本答案。
      所以要防止 Ai 通过大于 1 的流量。
      解决方法依然是经典的拆点法，将 Ai 拆成 A1i 和 A2i ，并建一条 A1i->A2i 的容量为 1 的边，对应的 Bj 指向 A1i ， A2i 指向 Cj 。这样就可以解决 Ai 通过流量大于 1 的问题了。
    最后，因为传统的 Edmonds-Karp 的复杂度为 O(n*m^2) ，所以要改用复杂度为 O(n^(1/2) *m) 的 Dinic 算法。
    嗯，我是抄的模板 XD
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

const int MAXN=10020;
const int MAXM=20020;
const int INF=0x3f3f3f3f;
int n1,n2,n3,m1,m2;
struct Edge{
  int u,v,cap,flow;
}edge[(MAXM*2+MAXN*3)<<1];
VR<int> G[MAXN<<2];
int tailE=0;
int d[MAXN<<2],cur[MAXN<<2];
bool vis[MAXN<<2];
int s,t;

void addEdge(int u, int v, int cap){
  edge[tailE++] = (Edge){u,v,cap,0};
  edge[tailE++] = (Edge){v,u,0,0};
  G[u].push_back(tailE-2);
  G[v].push_back(tailE-1);
}
bool bfs(){
  MST(vis,0);
  queue<int> q; q.push(s);
  d[s]=0; vis[s]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    FOR(i,0,G[u].size()){
      Edge & e = edge[G[u][i]];
      if(!vis[e.v] && e.cap>e.flow){
        vis[e.v]=1;
        d[e.v]=d[u]+1;
        q.push(e.v);
      }
    }
  }
  return vis[t];
}
int dfs(int u, int a){
  if(u==t || !a) return a;
  int flow=0,f;
  for(int & i = cur[u];i<G[u].size();i++){
    Edge & e = edge[G[u][i]];
    if(d[u]+1==d[e.v] && (f=dfs(e.v,min(a,e.cap-e.flow)))>0){
      e.flow+=f;
      edge[G[u][i]^1].flow-=f;
      flow+=f;
      a-=f;
      if(!a) break;
    }
  }
  return flow;
}
int Dinic(){
  int flow=0;
  while(bfs()){
    MST(cur,0); flow+=dfs(s,INF);
  }
  return flow;
}

//Bi = i, A1i = i+MAXN, A2i = i+MAXN*2, Ci = i+MAXN*3

int main(void){
  scanf("%d%d%d",&n1,&n2,&n3);

  int u,v;
  scanf("%d",&m1);
  FOR(i,0,m1){
    scanf("%d%d",&u,&v);  //Bv -> A1u
    addEdge(v,u+MAXN,1);
  }
  scanf("%d",&m2);
  FOR(i,0,m2){
    scanf("%d%d",&u,&v);  //A2u -> Cv
    addEdge(u+(MAXN<<1),v+MAXN*3,1);
  }
  s=0,t=MAXN*4-2;
  FORR(i,1,n1) addEdge(i+MAXN,i+(MAXN<<1),1);
  FORR(i,1,n2) addEdge(s,i,1);  //s -> Bi
  FORR(i,1,n3) addEdge(i+MAXN*3,t,1);  //Ci -> t

  int ans=Dinic();
  printf("%d\n",ans);

  return 0;
}

/*
const int MAXN=10020;
const int MAXM=20020;
const int INF=0x3f3f3f3f;
int n1,n2,n3,m1,m2;
struct Edge{
  int u,v,cap,flow;
}edge[(MAXM*2+MAXN*3)<<1];
VR<int> G[MAXN<<2];
int tailE=0;
int p[MAXN<<2],a[MAXN<<2];
int q[MAXN<<2],head,tail;

void addEdge(int u, int v, int cap){
  edge[tailE++] = (Edge){u,v,cap,0};
  edge[tailE++] = (Edge){v,u,0,0};
  G[u].push_back(tailE-2);
  G[v].push_back(tailE-1);
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

//Bi = i, A1i = i+MAXN, A2i = i+MAXN*2, Ci = i+MAXN*3

int main(void){
  scanf("%d%d%d",&n1,&n2,&n3);

  int u,v;
  scanf("%d",&m1);
  FOR(i,0,m1){
    scanf("%d%d",&u,&v);  //Bv -> A1u
    addEdge(v,u+MAXN,1);
  }
  scanf("%d",&m2);
  FOR(i,0,m2){
    scanf("%d%d",&u,&v);  //A2u -> Cv
    addEdge(u+(MAXN<<1),v+MAXN*3,1);
  }
  int s=0,t=MAXN*4-2;
  FORR(i,1,n1) addEdge(i+MAXN,i+(MAXN<<1),1);
  FORR(i,1,n2) addEdge(s,i,1);  //s -> Bi
  FORR(i,1,n3) addEdge(i+MAXN*3,t,1);  //Ci -> t

  int ans=MF(s,t);
  printf("%d\n",ans);

  return 0;
}
*/
