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
const int MAX=2020;
const int INF=0x3f3f3f3f;
int n; char s[MAX][8];
int d[MAX]; bool vis[MAX];

int dis(int i, int j){
  int cnt=0;
  FOR(k,0,7) cnt += s[i][k]!=s[j][k];
  return cnt;
}

struct Node{
  int d,u;
  Node(int d, int u): d(d), u(u) { }
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(d,0x3f); MST(vis,0);
    FORR(i,1,n) scanf("%s",s[i]);
    d[1]=0;
    int ans=0;
    FOR(cnt,0,n){
      int u=-1,tMin=INF;
      FORR(i,1,n) if(!vis[i] && d[i]<tMin){
        tMin=d[i], u=i;
      }
      vis[u]=1; ans+=tMin;
      FORR(v,1,n) if(!vis[v]){
        d[v]=min(d[v],dis(u,v));
      }
    }

    printf("The highest possible quality is 1/%d.\n",ans);
  }

  return 0;
}

/*
// Kruskal
const int MAX=2020;
const int INF=0x3f3f3f3f;
int n; char s[MAX][8];

int cal(int i, int j){
  int cnt=0;
  FOR(k,0,7) cnt += s[i][k]!=s[j][k];
  return cnt;
}

struct Edge{
  int u,v,w;
  Edge() { }
  Edge(int u, int v, int w): u(u), v(v), w(w) { }
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAX*MAX];
int tail=0;

void addEdge(int u, int v, int w){
  edge[tail++]=Edge(u,v,w);
}

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    tail=0; MST(p,-1);
    FORR(i,1,n){
      scanf("%s",s[i]);
      FOR(j,1,i) addEdge(i,j,cal(i,j));
    }
    sort(edge,edge+tail);
    int ans=0,cnt=0;
    FOR(i,0,tail){
      Edge &e=edge[i];
      int x1=fa(e.u),x2=fa(e.v);
      if(x1!=x2){
        p[x1]=x2; ans+=e.w;
        if(++cnt==n-1) break;
      }
    }
    printf("The highest possible quality is 1/%d.\n",ans);
  }

  return 0;
}
*/

/*
const int MAX=2020;
const int INF=0x3f3f3f3f;
int n,G[MAX][MAX]; char s[MAX][8];
int d[MAX];

int cal(int i, int j){
  int cnt=0;
  FOR(k,0,7) cnt += s[i][k]!=s[j][k];
  return cnt;
}

struct Node{
  int d,u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
void Dij(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u = t.u;
    if(d[u]!=t.d) continue;
    FORR(v,1,n) if(v!=u){
      if(d[v]>d[u]+G[u][v]){
        d[v] = d[u]+G[u][v];
        q.push(Node{d[v],v});
      }
    }
  }
}
int main(void){
  while(scanf("%d",&n)==1 && n){
    FORR(i,1,n){
      scanf("%s",s[i]);
      FOR(j,1,i) G[i][j]=G[j][i]=cal(i,j);
    }
    int ansMin=INF;
    FORR(i,1,n){
      Dij(i);
      int sum=0;
      FORR(j,1,n) sum+=d[j];
      ansMin=min(ansMin,sum);
    }
    printf("The highest possible quality is 1/%d.\n",ansMin);
  }

  return 0;
}
*/
