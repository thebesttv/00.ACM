// Tag: notag
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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 30;
const int INF = 0x3f3f3f3f;
int n,k,g[MAX][MAX],cnt; VR<int> G[MAX];
bool vis[MAX]; deque<int> r;

void dfs(int u){
  if(u == k){
    bool first = true;
    for(int x : r){
      if(first) first = false;
      else putchar(' ');
      printf("%d",x);
    }putchar('\n');
    ++cnt; return;
  }

  for(int v : G[u]) if(!vis[v] && g[v][k] < INF){
    vis[v] = 1; r.pb(v);
    dfs(v);
    vis[v] = 0; r.pop_back();
  }
}

int main(void){
  int kase = 0;
  while(scanf("%d",&k)==1){
    n = cnt = 0; MST(g,0x3f); FORR(i,1,20) G[i].clear();
    int u,v;
    while(scanf("%d%d",&u,&v)==2 && u && v){
      g[u][v] = g[v][u] = 1;
      G[u].pb(v), G[v].pb(u);
      n = max(n, max(u,v));
    }

    FORR(i,1,n) sort(ALL(G[i]));

    FORR(k,1,n) FORR(i,1,n) FORR(j,1,n)
      g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    printf("CASE %d:\n",++kase);
    r.clear(); r.pb(1);
    vis[1] = 1;
    dfs(1);
    vis[1] = 0;
    printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,k);
  }

  return 0;
}
