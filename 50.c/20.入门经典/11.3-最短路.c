#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int MAX=1000;
const int INF=0x3f3f3f3f;
int w[MAX][MAX],d1[MAX],d2[MAX][MAX],save[MAX][MAX];
int n;  //图的节点数
bool vis[MAX];

void Dijkstra(int u){
  memset(d1,0x3f,sizeof(d1)); //设置INF
  memset(vis,0,sizeof(vis));
  d1[u]=0;
  for(int i=0;i<n;i++){
    int x,m=INF;
    for(int y=0;y<n;y++) if(!vis[y] && d1[y]<=m)
      m = d1[x=y];
    vis[x]=1;
    for(int y=0;y<n;y++) if(w[x][y]<INF)
      d1[y]=min(d1[y],d1[x]+w[x][y]);
  }
}

void Floyd(){
  memset(d2,0x3f,sizeof(d2)); for(int i=0;i<MAX;i++) d2[i][i]=0;
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(d2[i][j]<INF && d2[k][j]<INF)
          d2[i][j]=min(d2[i][j],d2[i][k]+d2[k][j]);
}

int main(void){

  return 0;
}


void Dijkstra(int s){
  MST(d,0x3f); d[s]=0; vis[s]=1;
  FOR(k,0,n){
    int tMin=INF,u=-1;
    FORR(i,1,n) if(!vis[i] && d[i]<tMin) tMin=d[u=i];
    vis[u]=1;
    FORR(i,1,n) if(w[u][i]<INF)
      d[i]=min(d[i],d[u]+w[u][i]);
  }
}

struct Node{
  int u,d;
  bool operator < (const Node & b) const{
    return d>b.d;
  }
};
void Dijkstra(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push((Node){s,0});
  MST(vis,0);
  while(!q.empty()){
    Node & t=q.top(); q.pop();
    int u=t.u;
    //if(t.d!=d[u]) continue;
    if(vis[u]) continue;
    vis[u]=true;
    FOR(i,0,G[u].size()){
      Edge & e=G[u][i];
      if(d[e.v]>d[u]+e.w){
        d[e.v]=d[u]+e.w;
        q.push((Node){e.v,d[e.v]});
      }
    }
  }
}
void BellmanFord(int s){
  MST(d,0x3f); d[s]=0;
  FOR(i,1,n) FOR(j,0,edge.size()){
    Edge & e=edge[j];
    if(d[e.u]<INF) d[e.v]=min(d[e.v],d[e.u]+e.w);
  }
}
bool SPFA(int s){
  MST(d,0x3f); d[s]=0;
  MST(cnt,0); MST(inq,0);
  queue<int> q; q.push(s); inq[s]=true;

  while(!q.empty()){
    int u=q.front(); q.pop();
    inq[u]=false;
    if(d[u]<INF) FOR(i,0,G[u].size()){
      Edge & e=G[u][i];
      if(d[u]<INF && d[e.v]>d[u]+e.w){
        d[e.v]=d[u]+e.w;
        if(!inq[e.v]){
          q.push(e.v); inq[e.v]=true;
          if(++cnt[e.v]>n) return false;
        }
      }
    }
  }
  return true;
}
