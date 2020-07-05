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

const int MAXN=5020, MAXM=40020*2;
int n,m,k,s,t,c[MAXN];
int ansMin=0x3f3f3f3f;

struct Edge{
  int v,w,c; Edge *next;
}edge[MAXM], *head[MAXN];
int tail=0;
void addEdge(int u, int v, int w, int c){
  edge[tail] = Edge{v,w,c,head[u]}; head[u] = edge + (tail++);
  edge[tail] = Edge{u,w,c,head[v]}; head[v] = edge + (tail++);
}

struct Node{
  int c,u;
  bool operator < (const Node &b) const {
    return c > b.c;
  }
};

void Dij(int s){
  MST(c,0x3f); c[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u = t.u;
    if(c[u]!=t.c) continue;
    for(Edge *e=head[u];e;e=e->next){
      if(e->c + t.c < c[e->v]){
        c[e->v] = e->c + t.c;
        q.push(Node{c[e->v],e->v});
      }
    }
  }
}

bool vis[MAXN];
void dfs(int u, int d, int c){
  if(u==t){
    ansMin=d; return;
  }
  for(Edge *e=head[u];e;e=e->next){
    if(vis[e->v]) continue;
    if((c + e->c > k) || (d + e->w >= ansMin)) continue;
    vis[e->v]=1;
    dfs(e->v, d + e->w, c + e->c);
    vis[e->v]=0;
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=0,u,v,w,c;i<m;++i){
    scanf("%d%d%d%d",&u,&v,&c,&w);
    addEdge(u,v,w,c);
  }
  scanf("%d%d%d",&s,&t,&k);

  Dij(s);
  if(c[t]>k) printf("-1\n");
  else{
    dfs(s,0,0);
    printf("%d\n",ansMin);
  }

  return 0;
}
