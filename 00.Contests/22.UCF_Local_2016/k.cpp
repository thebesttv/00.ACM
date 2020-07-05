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

typedef pair<int,bool> pii;
const int MAX = 5e5 + 20;
const int INF = 0x3f3f3f3f;
int n,a[MAX],b[MAX],d[MAX];
map<int,VR<int>> ma,mb;
bool vis[MAX];

int bfs(bool ini){
  MST(vis,0); MST(d,0x3f);
  queue<pii> q;
  q.push({1,ini}); d[1]=0; vis[1]=1;
  while(!q.empty()){
    pii p = q.front(); q.pop();
    int u=p.FI;
    if(vis[n]) break;
    if(p.SE) for(int v : ma[a[u]+b[u]]){
      if(!vis[v]){
        d[v] = d[u]+1; vis[v]=1;
        q.push({v,0});
      }
    }else for(int v : mb[a[u]-b[u]]){
      if(!vis[v]){
        d[v] = d[u]+1; vis[v]=1;
        q.push({v,1});
      }
    }
  }
  return d[n];
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    ma.clear(); mb.clear();
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]);
    FORR(i,1,n){
      scanf("%d",&b[i]);
      ma[a[i]+b[i]].push_back(i);
      mb[a[i]-b[i]].push_back(i);
    }

    int ans = min(bfs(0),bfs(1));
    printf("Field #%d: %d\n\n",kase, ans==INF ? -1 : ans);
  }

  return 0;
}

/*
typedef pair<int,int> pii;
const int MAX = 5e5 + 20;
int n,a[MAX],b[MAX];
map<int,VR<int>> G;
map<int,bool> vis;

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    G.clear(); vis.clear();
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]);
    FORR(i,1,n){
      scanf("%d",&b[i]);
      G[a[i]+b[i]].push_back(a[i]-b[i]);
      G[a[i]-b[i]].push_back(a[i]+b[i]);
    }

    queue<pii> q;
    q.push({a[1]+b[1],1}); vis[a[1]+b[1]]=1;
    q.push({a[1]-b[1],1}); vis[a[1]-b[1]]=1;
    int ans = -1;
    while(!q.empty()){
      pii t = q.front(); q.pop();
      int u = t.FI;
      if(u==a[n]+b[n] || u==a[n]-b[n]){
        ans = t.SE; break;
      }
      for(int v : G[u]) if(!vis.count(v)){
        q.push({v,t.SE+1}); vis[v]=1;
      }
    }

    printf("Field #%d: %d\n\n",kase,ans);
  }

  return 0;
}
*/
