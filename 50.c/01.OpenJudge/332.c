/*
描述
Write a program that finds the nearest common ancestor of two distinct nodes in a tree. 

输入
The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case starts with a line containing an integer N , the number of nodes in a tree, 2<=N<=10,000. The nodes are labeled with integers 1, 2,..., N. Each of the next N -1 lines contains a pair of integers that represent an edge --the first integer is the parent node of the second integer. Note that a tree with N nodes has exactly N - 1 edges. The last line of each test case contains two distinct integers whose nearest common ancestor is to be computed.

输出
Print exactly one line for each test case. The line should contain the integer that is the nearest common ancestor.

样例输入
2
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
5
2 3
3 4
3 1
1 5
3 5

样例输出
4
3
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

const int MAX=10020;
int n,p[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
int qx,qy,ans;
bool vis[MAX];

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
void dfs(int u){
  vis[u]=1; int v;
  for(int i=se[u];i;i=edge[i].next){
    dfs(v=edge[i].v); p[v]=u;
  }
  if(qx==u && vis[qy]) ans=find(qy);
  else if (qy==u && vis[qx]) ans=find(qx);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    tailE=1; MST(se,0); MST(vis,0); MST(p,-1);
    scanf("%d",&n);
    int u,v;
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      addEdge(u,v); vis[v]=1;
    }
    scanf("%d%d",&qx,&qy);

    int root=0;
    FORR(i,1,n) if(!vis[i]) {root=i; break;}
    MST(vis,0);
    dfs(root);
    printf("%d\n",ans);
  }
  return 0;
}

/*
const int MAX=10020;
int n,f[MAX][15],lg[MAX],dep[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
bool vis[MAX];
int q[MAX],head,tail;

void addEdge(int u, int v){
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
  int *p=&lg[3];
  FOR(i,3,MAX) {*p+=*(p-1); p++;}

  int T; scanf("%d",&T);
  while(T--){
    tailE=1; MST(se,0); MST(vis,0); MST(f,0);
    scanf("%d",&n);
    int u,v;
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      addEdge(u,v); vis[v]=1;
    }

    int root=0,d;
    FORR(i,1,n) if(!vis[i]) {root=i; break;}

    head=tail=0; q[tail++]=root;
    while(head<tail){
      u=q[head++]; d=dep[u]+1;
      FOR(k,1,15) if((1<<k)<d)  //XXX
        f[u][k] = f[ f[u][k-1]][k-1];
      for(int i=se[u];i;i=edge[i].next){
        v=edge[i].v; dep[v]=d;
        f[v][0]=u; q[tail++]=v;
      }
    }
    scanf("%d%d",&u,&v);
    printf("%d\n",lca(u,v));
  }

  return 0;
}
*/
