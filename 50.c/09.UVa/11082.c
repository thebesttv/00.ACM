/*
  解题报告：
    巧妙建模，使用费用流解题。
    先将前缀数组改为和数组，记录每行每列的和。
    对于任意一行，如果将其中每个元素都减1，那么row[i]变为row[i]-c，每个元素范围为[0:19]，这就为费用流提供了便利：费用流的下界从1变成0。
    因此，将矩阵中的所有元素减1，s->rowi，容量为row[i]-c，coli->t，容量为col[i]-r，再将每个rowi和colj连接，容量为19，跑一次最大流即可。
    当且仅当所有s->rowi和coli->t的边都满载时有解，答案为所有rowi->colj的边的流量加上1。
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

const int MAX=100;
int row[MAX],col[MAX];
int r,c;
struct Edge{
  int u,v,cap,flow;
};
vector<Edge> edge;
vector<int> G[MAX];
int a[MAX],p[MAX];

void addEdge(int u, int v, int cap);
int maxflow(int s, int t);

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    edge.clear(); FOR(i,0,MAX) G[i].clear(); MST(row,0); MST(col,0);
    scanf("%d%d",&r,&c);
    FORR(i,1,r) scanf("%d",&row[i]);
    FORR(i,1,c) scanf("%d",&col[i]);
    ROR(i,r,1) row[i]-=row[i-1];
    ROR(i,c,1) col[i]-=col[i-1];
#ifdef DEBUG
    FORR(i,1,r) printf("row[%d]: %d\n",i,row[i]);
    FORR(i,1,c) printf("col[%d]: %d\n",i,col[i]);
#endif

    FORR(i,1,r) addEdge(0,i,row[i]-c);        //<b>
    FORR(i,1,c) addEdge(i+50,MAX-1,col[i]-r); //</b>
    FORR(i,1,r) FORR(j,1,c) addEdge(i,j+50,19);

    maxflow(0,MAX-1);
    if(kase!=1) printf("\n");
#ifdef DEBUG
    FOR(i,0,edge.size()) printf("  %d -> %d, cap: %d, flow: %d\n",edge[i].u,edge[i].v,edge[i].cap,edge[i].flow);
#endif
    printf("Matrix %d\n",kase);
    FORR(i,1,r){
      FOR(j,0,G[i].size()) if(edge[G[i][j]].v>50) //<b>不能当edge[G[i][j]].flow>=0时输出，因为可能有从i->s的flow为0的反向边</b>
        printf("%d ",edge[G[i][j]].flow+1);
      printf("\n");
    }
  }
  return 0;
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
