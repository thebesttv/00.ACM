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

const int MAX = 1020;
int n,k; bool done[MAX], vis[MAX];
VR<int> G[MAX];
int cnt[MAX];

int bfs(int s){
  MST(vis,0); vis[s]=1;
  queue<int> q; q.push(s);
  int sum=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    for(int v : G[u]) if(!done[v] && !vis[v]){
      vis[v]=1; q.push(v); sum++;
    }
  }
  return sum;
}

void go(int u){
  done[u]=1;
  for(int v : G[u])
    if(!done[v]) go(v);
}

int main(void){
  int m,x;
  scanf("%d%d",&n,&k);
  FORR(i,1,n){
    scanf("%d",&m);
    while(m--){
      scanf("%d",&x);
      G[x].push_back(i);
    }
  }

  int ans=0;
  while(k--){
    MST(cnt,0);
    int tMax=0, r=-1;
    FORR(i,1,n) if(!done[i]){
      cnt[i] = bfs(i);
      //printf(" %d: %d\n",i,cnt[i]);
      if(cnt[i] > tMax){
        tMax=cnt[i]; r=i;
      }
    }
    if(!tMax) break;
    ans += tMax; go(r);
  }
  printf("%d\n",ans);

  return 0;
}

























/*
const int MAXN=1020, MAXM=MAXN*MAXN;
int n,k; bool vis[MAXN];
int dp[MAXN];

struct Edge{
  int v,w; Edge *next;
};
struct Base{
  Edge edge[MAXM], *head[MAXN];
  int tail=0;
  void addEdge(int u, int v, int w){
    edge[tail]=Edge{v,w,head[u]}; head[u] = edge + tail++;
  }
};

struct Tarjan: public Base{
  int n;
  int dfn[MAXN], dfscnt=0, low[MAXN];
  stack<int> st; bool inst[MAXN];
  int belong[MAXN], sc[MAXN], sccnt=0;

  void init(int _n){
    n = _n;
    MST(dfn,0); dfscnt=0; MST(low,0);
    while(!st.empty()) st.pop();
    MST(inst,0); MST(belong,0); MST(sc,0); sccnt=0;
  }
  void tarjan(){
    FORR(i,1,n) if(!dfn[i] && !vis[i])
      tarjan(i);
  }
  void tarjan(int u){
    int v;
    dfn[u] = low[u] = ++dfscnt;
    st.push(u); inst[u]=1;

    for(Edge *e=head[u];e;e=e->next) if(!vis[e->v]){
      v = e->v;
      if(!dfn[v]){
        tarjan(v);
        if(low[u] > low[v])
          low[u] = low[v];
      }else if(inst[v] && low[u] > dfn[v]){
        low[u] = dfn[v];
      }
    }

    if(dfn[u]!=low[u]) return;
    ++sccnt;
    do{
      v = st.top(); st.pop();
      inst[v]=0; belong[v]=sccnt;
      sc[sccnt]++;
    }while(v!=u);
  }
}tar;

int f(int u){
  int &a=dp[u];
  if(a>-1) return a;
  if(a<-1){
    int t = -a; a = 0;
    for(Edge *e=tar.head[u];e;e=e->next)
      if(tar.belong[e->v] != tar.belong[u])
        a += f(e->v);
    a += t;
  }else{
    a = 1;
    for(Edge *e=tar.head[u];e;e=e->next)
      if(!vis[e->v]) a += f(e->v);
  }
  return a;
}

void go(int u){
  vis[u]=1;
  for(Edge *e=tar.head[u];e;e=e->next)
    if(!vis[e->v]) go(e->v);
}

int main(void){
  int m,x;
  scanf("%d%d",&n,&k);
  FORR(i,1,n){
    scanf("%d",&m);
    while(m--){
      scanf("%d",&x);
      tar.addEdge(x,i,0);
    }
  }

  int ans=0;
  while(k--){
    MST(dp,-1);

    tar.init(n); tar.tarjan();
#ifdef DEBUG
    printf("  sccnt: %d\n",tar.sccnt);
#endif

    FORR(i,1,tar.sccnt) if(tar.sc[i]>1){
#ifdef DEBUG
      printf("    sc[%d]: %d\n",i,tar.sc[i]);
#endif
      FORR(j,1,n) if(tar.belong[j]==i)
        dp[j] = -tar.sc[i];
    }

    int tMax=0, r=-1;
    FORR(i,1,n) if(!vis[i]){
      if(f(i)>tMax){
        tMax=dp[i]; r=i;
      }
    }

    if(!tMax) break;
    ans+=tMax; go(r);
  }
  printf("%d\n",ans);

  return 0;
}
*/
