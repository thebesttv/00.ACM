/*
题目描述
如题，给定一棵有根多叉树，请求出指定两个点直接最近的公共祖先。

输入输出格式
输入格式：
第一行包含三个正整数N、M、S，分别表示树的结点个数、询问的个数和树根结点的序号。
接下来N-1行每行包含两个正整数x、y，表示x结点和y结点之间有一条直接连接的边（数据保证可以构成树）。
接下来M行每行包含两个正整数a、b，表示询问a结点和b结点的最近公共祖先。

输出格式：
输出包含M行，每行包含一个正整数，依次为每一个询问的结果。

输入输出样例
输入样例#1：
5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5

输出样例#1：
4
4
1
4
4

数据规模：
对于30%的数据：N<=10，M<=10
对于70%的数据：N<=10000，M<=10000
对于100%的数据：N<=500000，M<=500000
*/

/*
  解题报告：
    深深地感觉已经被STL惯坏了。。。看来将来要忍痛割爱了。
  [1]LCA
    令 f[i][j] 表示节点i向上走j层，所到的节点，则
      f[i][j] = f[ f[i][j-1] ][j-1]
      f[i][0] = p[i]
    对于每次询问 lca(x,y):
      先令x,y在同一层上，如果此时x==y则直接返回x。
      然后在将x,y倍增地向上走（<b>先大走再小走</b>）。
    具体：
      先确保 dep[x]>=dep[y]
      如果x,y在不同的层数，则倍增地使x向上。
      如果此时x和y相等，则一定要输出，否则最后会返回p[x]。
      然后即为倍增向上走。
    因为LCA是在线算法，每次询问的复杂度为O(log(dep))，于是就TLE了三个点（卡常能多对一个）。
  [2]Tarjan
    因为Tarjan是离线的，复杂度仅为O(nm)。
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

inline int read(){
  RE int ans=0,ch;
  do ch=getchar(); while(ch<'0' || ch>'9');
  do {ans=ans*10+ch-'0'; ch=getchar();} while(ch>='0' && ch<='9');
  return ans;
}

const int MAX=500020;
int n,m,s,p[MAX],ans[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
struct Query{
  int v,n,next;
}Q[MAX<<1];
int sq[MAX],tailQ=1;
bool vis[MAX];

inline void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
inline void addQuery(int u, int v, int n){
  int t=tailQ++;
  Q[t] = (Query){v,n,sq[u]}; sq[u]=t;
}
int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
void dfs(int u){
  vis[u]=1; int v;
  for(int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
    dfs(v); p[v]=u;
  }
  for(int i=sq[u];i;i=Q[i].next) if(vis[v=Q[i].v])
    ans[Q[i].n]=find(v);
}

int main(void){
  MST(p,-1);
  scanf("%d%d%d",&n,&m,&s);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    addEdge(u,v); addEdge(v,u);
  }
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    addQuery(u,v,i); addQuery(v,u,i);
  }

  dfs(s);

  FOR(i,0,m) printf("%d\n",ans[i]);

  return 0;
}

/*
const int MAX=500020;
int n,m,s,dep[MAX],f[MAX][20],lg[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
bool vis[MAX];
int q[MAX],head,tail;

inline void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
int lca(int x, int y){
  if(dep[x]<dep[y]) swap(x,y);
  while(dep[x]>dep[y])
    x=f[x][lg[dep[x]-dep[y]]];
  if(x==y) return x;
  ROR(k,lg[dep[x]],0)
    if(f[x][k]!=f[y][k])
      x=f[x][k],y=f[y][k];
  return f[x][0];
}

int main(void){
  for(int i=2;i<MAX;i<<=1) lg[i]=1;
  FOR(i,3,MAX) lg[i]+=lg[i-1];

  scanf("%d%d%d",&n,&m,&s);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    addEdge(u,v); addEdge(v,u);
  }

  int d;
  q[tail++]=s; vis[s]=1; dep[s]=0; f[s][0]=0;
  while(head<tail){
    u=q[head++]; d=dep[u];
    for(int k=1;(1<<k)<=d;k++)  //init f
      f[u][k] = f[ f[u][k-1] ][k-1];
    for(int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
      vis[v]=1; dep[v]=d+1;
      f[v][0]=u; q[tail++]=v;
    }
  }

  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    printf("%d\n",lca(u,v));
  }

  return 0;
}
*/

/*
//Tarjan LCA, 邻接表, rewrite
const int MAX=500020;
int n,m,s;
int p[MAX],ans[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
bool vis[MAX];
struct Query{
  int v,n,next;
}query[MAX<<1];
int sq[MAX],tailQ=1;

inline void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
inline void addQuery(int u, int v, int n){
  int t=tailQ++;
  query[t] = (Query){v,n,sq[u]}; sq[u]=t;
}
inline int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
void dfs(int u){
  int v; vis[u]=1;  //先设置vis并无大碍，即使一开始ans中存放了错误答案，最后还是会被正确答案覆盖
  for(int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
    dfs(v); p[v]=u;
  }
  for(int i=sq[u];i;i=query[i].next) if(vis[v=query[i].v]){
    ans[query[i].n]=find(v);
  }
}

int main(void){
  MST(p,-1);
  n=read(); m=read(); s=read();
  int u,v;
  FOR(i,1,n){
    u=read(); v=read();
    addEdge(u,v); addEdge(v,u);
  }
  FOR(i,0,m){
    u=read(); v=read();
    addQuery(u,v,i); addQuery(v,u,i);
  }
  dfs(s);
  FOR(i,0,m) printf("%d\n",ans[i]);

  return 0;
}
*/

/*
//倍增 LCA ,邻接表, rewrite
const int MAX=500020;
int n,m,s;
int f[MAX][20],dep[MAX],lg[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
bool vis[MAX];
int q[MAX],head,tail;

inline void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
int lca(int x, int y){
  if(dep[x]<dep[y]) swap(x,y);
  //while(dep[x]>dep[y])
  //  x=f[x][lg[dep[x]-dep[y]]];
  for(int t=dep[x]-dep[y],cnt=0;t;t>>=1,cnt++) if(t&1)  //好像要快一点点
    x=f[x][cnt];
  if(x==y) return x;
  ROR(k,lg[dep[x]],0)
    if(f[x][k]!=f[y][k])
      x=f[x][k],y=f[y][k];
  return f[x][0];
}

int main(void){
  n=read(); m=read(); s=read();
  //init lg
  for(int i=2;i<=n;i<<=1) lg[i]=1;  //<b> log2(1)=0，i从2开始 </b>
  int *p=lg+1;
  FORR(i,1,n) {*p += *(p-1); p++;}

  //read edge
  int u,v;
  FOR(i,1,n){
    u=read(); v=read();
    addEdge(u,v); addEdge(v,u);
  }

  //bfs
  RE int d;
  q[tail++]=s; vis[s]=1;
  while(head<tail){
    u=q[head++]; d=dep[u];
    for(RE int k=1;(1<<k)<=d;k++)
      f[u][k] = f[f[u][k-1]][k-1];
    for(RE int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
      dep[v]=d+1; f[v][0]=u;
      vis[v]=1; q[tail++]=v;
    }
  }

  FOR(i,0,m){
    u=read(); v=read();
    printf("%d\n",lca(u,v));
  }

  return 0;
}
*/

/*
//Tarjan, 邻接表版
const int MAX=500020;
int n,m,s;
int p[MAX],ans[MAX];
bool vis[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];  //<b>开双倍</b>
int se[MAX],tailE=1;
struct Query{
  int v,next,n;
}Q[MAX<<1]; //<b>开双倍</b>
int sq[MAX],tailQ=1;

int find(int x){
  //return p[x]==x ? x : find(p[x]);
  return p[x]==x ? x : p[x]=find(p[x]); //<b></b>
}
void dfs(int u){
  p[u]=u; vis[u]=1;
  int v;
  for(int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
    dfs(v); p[v]=u;
  }
  for(int i=sq[u];i;i=Q[i].next) if(vis[v=Q[i].v])
    ans[Q[i].n]=find(v);
}
void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
void addQ(int u, int v, int n){
  int t=tailQ++;
  Q[t] = (Query){v,sq[u],n}; sq[u]=t;
}

int main(void){
  n=read(); m=read(); s=read();
  int u,v;
  FOR(i,1,n){
    u=read(); v=read();
    addEdge(u,v); addEdge(v,u);
  }
  FOR(i,0,m){
    u=read(); v=read();
    addQ(u,v,i); addQ(v,u,i);
  }
  dfs(s);
  FOR(i,0,m) printf("%d\n",ans[i]);

  return 0;
}
*/

/*
//Tarjan, STL版
const int MAX=500020;
int n,m,s;
int p[MAX],ans[MAX];
bool vis[MAX];
VR<int> G[MAX];
struct Query{
  int v,n;
};
VR<Query> Q[MAX];

int find(int x){
  //return p[x]==x ? x : find(p[x]);
  return p[x]==x ? x : p[x]=find(p[x]); //<b></b>
}
void dfs(int u){
  p[u]=u; vis[u]=1;
  int v;
  FOR(i,0,G[u].size()) if(!vis[v=G[u][i]]){
    dfs(v); p[v]=u;
  }

  FOR(i,0,Q[u].size()) if(vis[v=Q[u][i].v])
    ans[Q[u][i].n]=find(v);
}

int main(void){
  n=read(); m=read(); s=read();
  int u,v;
  FOR(i,1,n){
    u=read(); v=read();
    G[u].push_back(v); G[v].push_back(u);
  }
  FOR(i,0,m){
    u=read(); v=read();
    Q[u].push_back((Query){v,i});
    Q[v].push_back((Query){u,i});  //<b></b>, dfs时只会用到二者之一？
  }
  dfs(s);
  FOR(i,0,m) printf("%d\n",ans[i]);

  return 0;
}
*/

/*
//常数优化LCA（效果不好）
//TLE
const int MAX=500020;
const double cLOG2=log(2);
int n,m,s;
int dep[MAX],f[MAX][20];
VR<int> G[MAX];
bool vis[MAX];
int q[MAX],head=0,tail=0;

inline int log2(int n){
  return (int)(log(n)/cLOG2);
}
int lca(int x, int y){
  if(dep[x]<dep[y]) swap(x,y); //保持dep[x]>=dep[y]
  RE int t;
  while((t=dep[x]-dep[y])>0)
    x=f[x][log2(t)];
  if(x==y) return x;  //<b></b>
  ROR(k,log2(dep[x]),0)
    if(f[x][k]!=f[y][k])
      x=f[x][k],y=f[y][k];
  return f[x][0];
}

int main(void){
  n=read(); m=read(); s=read();
  int u,v;
  FOR(i,1,n){
    u=read(); v=read();
    G[u].push_back(v); G[v].push_back(u);
  }

  //bfs
  q[tail++]=s; dep[s]=0; vis[s]=1;
  while(head<tail){
    u=q[head++]; int *p=&f[u][0],td=dep[u];
    for(int k=1;(1<<k)<=td;k++)
      *(p+k) = f[*(p+k-1)][k-1];
    ROR(i,G[u].size()-1,0) if(!vis[v=G[u][i]]){
      dep[v]=dep[u]+1; f[v][0]=u; //<b> </b>
      vis[v]=1; q[tail++]=v;
    }
  }

  FOR(i,0,m){
    u=read(); v=read();
    printf("%d\n",lca(u,v));
  }

  return 0;
}
*/

/*
//LCA
//TLE
const int MAX=500020;
const double cLOG2=log(2);
int n,m,s;
int dep[MAX],f[MAX][20];
VR<int> G[MAX];
bool vis[MAX];
queue<int> q;

inline int log2(int n){
  return (int)(log(n)/cLOG2);
}
int lca(int x, int y){
  if(dep[x]<dep[y]) swap(x,y); //保持dep[x]>=dep[y]
  while(dep[x]>dep[y])
    x=f[x][log2(dep[x]-dep[y])];
  if(x==y) return x;  //<b></b>
  ROR(k,log2(dep[x]),0)
    if(f[x][k]!=f[y][k])
      x=f[x][k],y=f[y][k];
  return f[x][0];
}

int main(void){
  scanf("%d%d%d",&n,&m,&s);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v); G[v].push_back(u);
  }

  //bfs
  q.push(s); vis[s]=1; dep[s]=0;
  while(!q.empty()){
    u=q.front(); q.pop();
    for(int k=1;(1<<k)<=dep[u];k++)
      f[u][k] = f[f[u][k-1]][k-1];
    FOR(i,0,G[u].size()) if(!vis[v=G[u][i]]){
      dep[v]=dep[u]+1; f[v][0]=u; //<b> </b>
      vis[v]=1; q.push(v);
    }
  }

  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    printf("%d\n",lca(u,v));
  }

  return 0;
}
*/
