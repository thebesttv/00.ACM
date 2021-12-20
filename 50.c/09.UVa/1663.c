/*
  解题报告：
    将每个串看作一个点，将能被同一模板匹配的两点连接，则求的就是：使用最少的边，使得每个点都能被选到（孤立的点要特殊处理）
    首先，整张图一定是二分图（虽然我不知道为什么。。。），那么就可以使用最大二分图的匹配求得“最少的边数”，而因为有一部分孤立的点，要先计算出点的总数，然后用总数减去匹配数即为答案。
    注：不能只进行一遍染色然后统计颜色为1的点的个数，因为有可能两边都有孤立的点，答案会偏小。
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

const int MAX=1040;
int vis[MAX],G2[MAX][MAX];
int n,m;
char t1[MAX];
struct Edge{
  int u,v,cap,flow;
};
VR<Edge> edge;
VR<int> G[MAX];
int a[MAX],p[MAX];

void init(char * s);
void dfs(int u, int c);
void addEdge(int u, int v, int cap);
int maxflow(int s, int t);

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    MST(vis,-1); MST(G,0);
    int tot=1<<n;
    FOR(i,0,m){ scanf("%s",t1); init(t1); }
    FOR(i,0,tot) if(vis[i]==0) FOR(j,0,n){
      int t=i^(1<<j);
      if(vis[t]==0) G2[i][t]=G2[t][i]=1;
    }
    //染色
    FOR(i,0,tot) if(vis[i]==0) dfs(i,1);
#ifdef DEBUG
    FOR(i,0,tot) printf("  vis[%d]: %d\n",i,vis[i]);
#endif
    //匹配
    FOR(i,0,tot)
      if(vis[i]==1) addEdge(MAX-2,i,1);
      else if(vis[i]==2) addEdge(i,MAX-1,1);
    FOR(i,0,tot) if(vis[i]==1)
      FOR(j,0,tot) if(vis[j]==2 && G2[i][j]) addEdge(i,j,1);
    int match=maxflow(MAX-2,MAX-1);
    int cnt=0;
    FOR(i,0,tot) if(vis[i]!=-1) cnt++;
#ifdef DEBUG
    printf("  tot: %d, match: %d\n",cnt,match);
#endif
    printf("%d\n",cnt-match);
  }

  return 0;
}

void init(char * s){
  int pos=-1,ans=0;
  FOR(i,0,n){
    if(s[i]=='*') pos=i;
    else if(s[i]=='1') ans|=1<<i;
  }
  vis[ans]=0;
  if(pos!=-1) {ans|=1<<pos; vis[ans]=0;}
}
void dfs(int u, int c){
  vis[u]=c;
  FOR(i,0,1<<n) if(G2[u][i] && vis[i]==0) dfs(i,3-c);
}
void addEdge(int u, int v, int cap){
  edge.push_back((Edge){u,v,cap,0});
  edge.push_back((Edge){v,u,0,0});
  int m=edge.size();
  G[u].push_back(m-2); G[v].push_back(m-1);
}
int maxflow(int s, int t){
  int flow=0; MST(p,0);
  while(1){
    MST(a,0); a[s]=0x3f3f3f3f;
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
