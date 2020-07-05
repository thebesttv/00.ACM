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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 2e5 + 20;
int n,m; bool isTeam[MAX];
VR<int> G[MAX];
int vis[MAX]; bool vis2[MAX];
map<int, VR<int>> dis;

void dfs(int u, int d){
  vis[u] = 1;
  if(isTeam[u])
    dis[d].push_back(u);

  for(int v : G[u]) if(!vis[v])
    dfs(v, d+1);
}

void mark(int u, int d){
  MST(vis2,0); queue<pii> q;
  q.push({u,0}); vis2[u]=1;
  while(!q.empty()){
    pii t = q.front(); q.pop();
    if(t.SE == d) ++vis[t.FI];
    else for(int v : G[t.FI]) if(!vis2[v]){
      q.push({v, t.SE+1}); vis2[v]=1;
    }
  }
}

bool ok(int u, int d){
  MST(vis2,0); queue<pii> q;
  q.push({u,0}); vis2[u]=1;

  while(!q.empty()){
    pii t = q.front(); q.pop();
    if(isTeam[t.FI]){
      if(t.SE != d) return false;
    }

    for(int v : G[t.FI]) if(!vis2[v]){
      q.push({v, t.SE+1}); vis2[v]=1;
    }
  }
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  if(m==1){
    printf("YES\n%d\n",1);
    return 0;
  }

  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  FOR(i,0,m) scanf("%d",&u), isTeam[u]=1;
  dfs(u, 0);

  for(auto p : dis) if(p.FI&1){
    printf("NO\n"); return 0;
  }

  VR<int> disv;
  for(auto p : dis) disv.push_back(p.FI);
  sort(ALL(disv));
#ifdef DEBUG
  printf("dis: "); for(int v : disv) printf("%d ",v);
  putchar('\n');
#endif

  int d;
  d = disv.back()/2;
  mark(u, d);
  mark(dis[disv.back()][0], d);

  FORR(i,1,n) if(vis[i]==3 && ok(i, d)){
    printf("YES\n%d\n",i); return 0;
  }
  printf("NO\n");
  return 0;
}
