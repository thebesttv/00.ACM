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
int n,m,k,p[MAX],d[MAX],wp,dp;
VR<int> G[MAX],rG[MAX];
bool vis[MAX];
queue<int> q;

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    rG[v].push_back(u);
  }
  scanf("%d",&k);
  FORR(i,1,k) scanf("%d",&p[i]);

  // vis, cnt, d
  q.push(p[k]), vis[p[k]]=1, d[p[k]]=0;
  while(!q.empty()){
    u = q.front(); q.pop();

    for(int v : rG[u]) if(!vis[v]){
      q.push(v), vis[v] = 1;
      d[v] = d[u]+1;

      //for(int tu : G[v]) if(d[v]==d[tu]+1) ++cnt[v];
    }
  }

  wp=dp=0;
  FOR(i,1,k){
    u=p[i], v=p[i+1];
    if(d[u] != d[v]+1){ // wrong path
      ++wp;
    }else{
      int cnt = 0;
      for(int tv : G[u]) if(d[u]==d[tv]+1)
        ++cnt;
      if(cnt>1) ++dp;
    }
  }
  printf("%d %d\n",wp,wp+dp);

  return 0;
}
