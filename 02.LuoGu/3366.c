#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

// Prim
// 优先队列
const int MAXN=5020;
const int MAXM=200020;
const int INF=0x3f3f3f3f;
int n,m,d[MAXN];
bool vis[MAXN];

int head[MAXN],tail=1;
struct Edge{
  int v,w,next;
  Edge() { }
  Edge(int v, int w, int next): v(v), w(w), next(next) { }
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAXM*2];

void addEdge(int u, int v, int w){
  edge[tail]=Edge(v,w,head[u]); head[u]=tail++;
  edge[tail]=Edge(u,w,head[v]); head[v]=tail++;
}

struct Node{
  int u,d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
PQ<Node> q;

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
  }

  MST(d,0x3f); d[1]=0;
  q.push(Node{1,0});
  int ans=0, cnt=0;
  while(!q.empty() && cnt<n){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(d[u]!=t.d) continue;
    //或 if(vis[u]) continue;
    ans+=t.d; ++cnt; vis[u]=1;
    for(int i=head[u];i;i=edge[i].next){
      int v=edge[i].v,w=edge[i].w;
      if(!vis[v] && d[v]>w){
        d[v]=w; q.push(Node{v,w});
      }
    }
  }
  if(cnt<n) printf("orz\n");
  else printf("%d\n",ans);

  return 0;
}

/*
// Prim
// 邻接矩阵
const int MAXN=5020;
const int MAXM=200020;
const int INF=0x3f3f3f3f;
int n,m,d[MAXN];
bool vis[MAXN];

int head[MAXN],tail=1;
struct Edge{
  int v,w,next;
  Edge() { }
  Edge(int v, int w, int next): v(v), w(w), next(next) { }
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAXM*2];

void addEdge(int u, int v, int w){
  edge[tail]=Edge(v,w,head[u]); head[u]=tail++;
  edge[tail]=Edge(u,w,head[v]); head[v]=tail++;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
  }

  MST(d,0x3f); d[1]=0;
  int ans=0, cnt=0;
  FOR(k,0,n){
    int tMin=INF,u=-1;
    FORR(i,1,n) if(!vis[i] && d[i]<tMin){
      tMin=d[i], u=i;
    }
    if(tMin==INF) break;
    ans+=d[u]; vis[u]=1; ++cnt;
    for(int i=head[u];i;i=edge[i].next){
      int v=edge[i].v, w=edge[i].w;
      if(!vis[v] && d[v]>w) d[v]=w;
    }
  }
  if(cnt<n) printf("orz\n");
  else printf("%d\n",ans);

  return 0;
}
*/

/*
// Kruskal
const int MAXN=5020;
const int MAXM=200020;
int n,m;

struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAXM];

int p[MAXN];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,m) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
  sort(edge,edge+m);

  MST(p,-1);
  int ans=0, cnt=0;
  FOR(i,0,m){
    Edge &e=edge[i];
    int x1=fa(e.u), x2=fa(e.v);
    if(x1!=x2){
      p[x1]=x2; ans+=e.w;
      if(++cnt==n-1) break;
    }
  }
  if(cnt<n-1) printf("orz\n");
  else printf("%d\n",ans);

  return 0;
}
*/

/*
const int MAXN=5020;
const int INF=0x3f3f3f3f;
int n,m,c[MAXN];
bool vis[MAXN];
struct Edge{
  int v,w;
  Edge(int v, int w): v(v), w(w) { }
};
VR<Edge> G[MAXN];

struct Node{
  int n,c;
  Node(int n, int c): n(n), c(c) { }
  bool operator < (const Node &b) const {
    return c>b.c;
  }
};
priority_queue<Node> q;

void addEdge(int u, int v, int w){
  G[u].push_back(Edge(v,w));
  G[v].push_back(Edge(u,w));
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
  }
  
  int ans=0,cnt=0;
  MST(c,0x3f);
  c[1]=0; q.push(Node(1,0));
  while(!q.empty() && cnt<n){
    Node t=q.top(); q.pop();
    if(vis[t.n]) continue;
    cnt++;
    ans+=t.c; vis[t.n]=1;
    for(Edge e : G[t.n])
      if(!vis[e.v] && c[e.v]>e.w){
        c[e.v]=e.w; q.push(Node(e.v,e.w));
      }
  }
  if(cnt==n) printf("%d\n",ans);
  else printf("orz\n");

  return 0;
}
*/
