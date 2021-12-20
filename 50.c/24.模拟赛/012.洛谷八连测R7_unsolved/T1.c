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
  int ans=0,ch;
  do ch=getchar(); while(!isdigit(ch));
  do {ans=ans*10+ch-'0'; ch=getchar();} while(isdigit(ch));
  return ans;
}

const int MAX=5020;
const int INF=0x3f3f3f3f;
int n,m,qq;
bool G[MAX][MAX];
int d[MAX][MAX],vis[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
struct Node{
  int u,d;
  bool operator < (const Node & b) const {return d>b.d;}
};
PQ<Node> q;

void addEdge(int u, int v){
  int t=tailE++;
  edge[t]=(Edge){v,se[u]}; se[u]=t;
}

/*
void Dij(int s){
  int *dis=&d[s][0];
  dis[s]=0; q.push((Node){s,0});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u,v,udis=dis[u];
    if(udis!=t.d) continue;
    for(int i=se[u];i;i=edge[i].next){
      v=edge[i].v;
      if(dis[v]>udis+1){
        dis[v]=udis+1;
        q.push((Node){v,dis[v]});
      }
    }
  }
}
*/

void Dij(int s){
  int *dis=&d[s][0];
  FOR(i,1,s) dis[i]=d[i][s];
  dis[s]=0; q.push((Node){s,0});
  FOR(i,1,s) if(dis[i]<INF) q.push((Node){i,dis[i]});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u,v,udis=dis[u];
    if(udis!=t.d) continue;
    for(int i=se[u];i;i=edge[i].next) if((v=edge[i].v)>s){
      if(dis[v]>udis+1){
        dis[v]=udis+1;
        q.push((Node){v,dis[v]});
      }
    }
  }
}


int main(void){
  //freopen("in1.txt","r",stdin);
  MST(d,0x3f);
  n=read(); m=read(); qq=read();
  int u,v;
  FOR(i,0,m) {u=read(); v=read(); G[u][v]=G[v][u]=1;}
  FORR(i,1,n){
    bool *pG=&G[i][0];
    FORR(j,i+1,n) if(*(pG+j))
      addEdge(i,j),addEdge(j,i);
  }

  FOR(i,1,n) Dij(i);  //最后一个点无需Dij
  for(int i=1,*dis=&d[n][0];i<=n;i++) *(dis+i)=d[i][n];
  d[n][n]=0;  //<b></b>

#ifdef DEBUG
  FORR(i,1,n){
    FORR(j,1,n) printf(" %2d",d[i][j]>=100 ? -1 : d[i][j]);
    printf("\n");
  }
#endif

  int a,k;
  FORR(i,1,qq){
    a=read(); k=read();
    FOR(j,0,a){
      u=read(); int *dis=&d[u][0];
      FORR(v,1,n) if(*(dis+v)<=k) vis[v]=i;
    }
    int cnt=0;
    FORR(j,1,n) if(vis[j]==i) cnt++;
    printf("%d\n",cnt);
  }

  return 0;
}
