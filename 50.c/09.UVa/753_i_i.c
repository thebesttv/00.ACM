/*
  解题报告：
    费用流。
    [1]
    先对所有种类的插头、插座建图，将所有转换器作为边，使用FLoyd求出传递闭包，也就是计算对于任意一个插头，能不能经过转换后插到某个插座上。
    然后建立费用流，将源点与插头连接，插座与汇点连接，对于所有插头i，如果它能够插到插座j上，则建立一条i->j的路径。所有路径容量都为1。最后跑一次费用流即可。
    [2]
    将所有种类的插头、插座作为节点，s连接所有电器插头，可行的插座连接t，两个容量都为1，再将所有能通过转换器连接的(i,j)连接，<b>容量为INF </b>跑一次费用流即可。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
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

const int MAX=430;
const int INF=0x3f3f3f3f;
struct Node{
  char name[30];
  int n;
  bool operator < (const Node & b) const {
    return strcmp(name,b.name)<0;
  }
};
set<Node> st;
struct Edge{
  int u,v,cap,flow;
  Edge() { }
  Edge(int u_, int v_, int cap_, int flow_): u(u_), v(v_), cap(cap_), flow(flow_) { }
};
vector<Edge> edge;
vector<int> G[MAX];
char t1[30],t2[30];
int a[MAX],p[MAX];
int n,m,k,tail;

int get(char * str);
void addEdge(int u, int v, int cap);
int maxflow(int s, int t);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    tail=1; st.CE(); edge.CE(); FOR(i,0,MAX) G[i].CE();
    scanf("%d",&n);
    FOR(i,0,n) {scanf("%s",t1); addEdge(get(t1),MAX-1,1);}
    scanf("%d",&m);
    FOR(i,0,m) {scanf("%s%s",t2,t1); addEdge(0,get(t1),1);}
    scanf("%d",&k);
    FOR(i,0,k) {scanf("%s%s",t1,t2); addEdge(get(t1),get(t2),INF);}

    int ans=maxflow(0,MAX-1);
    printf("%d\n",m-ans);
    if(T) printf("\n");
  }

  return 0;
}

int get(char * str){
  Node t; strcpy(t.name,str);
  set<Node>::iterator it=st.find(t);
  if(it!=st.end()) return it->n;
  t.n=tail++; st.insert(t);
  return t.n;
}
void addEdge(int u, int v, int cap){
  edge.push_back(Edge(u,v,cap,0));
  edge.push_back(Edge(v,u,0,0));
  int m=edge.size();
  G[u].push_back(m-2); G[v].push_back(m-1);
}
int maxflow(int s, int t){
  int flow=0; MST(p,0);
  while(1){
    MST(a,0); a[s]=INF;
    queue<int> q; q.push(s);
    while(!q.empty()){
      int u=q.front(); q.pop();
      FOR(i,0,G[u].size()){
        Edge & e=edge[G[u][i]];
        if(!a[e.v] && e.cap>e.flow){
          a[e.v]=min(a[u],e.cap-e.flow);
          p[e.v]=G[u][i];
          q.push(e.v);
        }
      }
      if(a[t]) break;
    }
    if(!a[t]) break;
    for(int i=t;i!=s;i=edge[p[i]].u){
      edge[p[i]].flow+=a[t];
      edge[p[i]^1].flow-=a[t];
    }
    flow+=a[t];
  }
  return flow;
}

/*
const int MAX=420;
const int INF=0x3f3f3f3f;
struct Node{
  char name[30];
  int num;
  bool operator < (const Node & b) const {
    return strcmp(name,b.name)<0;
  }
};
set<Node> st;
struct Edge{
  int u,v,cap,flow;
  Edge() { }
  Edge(int u_, int v_, int cap_, int flow_): u(u_), v(v_), cap(cap_), flow(flow_) { }
};
vector<Edge> edge;
vector<int> G[MAX];
bool G2[MAX][MAX];
char t1[30],t2[30];
int p[MAX],a[MAX];
int n,m,k,tail;

int get(char * str);
int maxflow(int s, int t);
void addEdge(int u, int v, int cap);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    tail=1; MST(G2,0); edge.clear(); FOR(i,0,MAX) G[i].clear(); st.clear();
    scanf("%d",&n);
    FOR(i,0,n){ scanf("%s",t1); addEdge(get(t1),MAX-1,1); }
    scanf("%d",&m);
    FOR(i,0,m){ scanf("%s%s",t2,t1); addEdge(0,get(t1),1); }
    scanf("%d",&k);
    FOR(i,0,k){ scanf("%s%s",t1,t2); int u=get(t1),v=get(t2); G2[u][v]=1; }

    //FOR(i,1,tail) G2[i][i]=1; //???
    FOR(k,1,tail) FOR(i,1,tail) if(G2[i][k]) FOR(j,1,tail)
      G2[i][j] = G2[i][j] || (G2[i][k] && G2[k][j]);
    FOR(i,1,tail) FOR(j,1,tail) if(G2[i][j] && i!=j){
#ifdef DEBUG
      printf("  %d -> %d\n",i,j);
#endif
      addEdge(i,j,1);
    }

    int ans=maxflow(0,MAX-1);
    printf("%d\n",m-ans);
    if(T) printf("\n");
  }

  return 0;
}

int get(char * str){
  Node t; strcpy(t.name,str);
  set<Node>::iterator it=st.find(t);
  if(it!=st.end()) return it->num;
  t.num=tail++; st.insert(t);
  return t.num;
}
void addEdge(int u, int v, int cap){
  edge.push_back(Edge(u,v,cap,0));
  //edge.push_back(Edge(v,u,-cap,0));
  edge.push_back(Edge(v,u,0,0));  //<b></b>
  int siz=edge.size();
  G[u].push_back(siz-2); G[v].push_back(siz-1);
}
int maxflow(int s, int t){
  MST(p,0);
  int flow=0;
  while(1){
    MST(a,0); a[s]=INF;
    queue<int> q; q.push(s);
    while(!q.empty()){
      int u=q.front(); q.pop();
      FOR(i,0,G[u].size()){
        Edge & e=edge[G[u][i]];
        if(!a[e.v] && e.cap>e.flow){
          a[e.v]=min(a[u],e.cap-e.flow);
          p[e.v]=G[u][i];
          q.push(e.v);
        }
      }
      if(a[t]) break;
    }
    if(!a[t]) break;
    //for(int i=t;i!=s;i=p[i]){
    for(int i=t;i!=s;i=edge[p[i]].u){
      edge[p[i]].flow+=a[t];
      edge[p[i]^1].flow-=a[t];
    }
    flow+=a[t];
  }
  return flow;
}
*/
