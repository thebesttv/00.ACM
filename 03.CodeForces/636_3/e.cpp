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
int n,m,a,b,c,d1[MAX],d2[MAX],d3[MAX];
LL p[MAX]; VR<int> G[MAX];

void bfs(int u, int *d){
  queue<int> q;
  q.push(u); d[u] = 0;
  while(!q.empty()){
    u = q.front(); q.pop();
    for(int v : G[u]) if(d[v]==-1){
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    FORR(i,1,n) G[i].clear(), d1[i]=d2[i]=d3[i]=-1;

    FORR(i,1,m) scanf("%lld",&p[i]);
    int u, v; sort(p+1,p+1+m);
    FORR(i,1,m){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);

      p[i] += p[i-1];
    }

    bfs(b,d1);
    bfs(a,d2);
    bfs(c,d3);

    LL ansMin = p[m] * 2ll;
    FORR(i,1,n){
      int dup = d1[i], sig = d2[i] + d3[i];
      if(dup + sig > m) continue;
#ifdef DEBUG
      printf("  node %d, dup: %d, sig: %d + %d\n",i,dup,d2[i],d3[i]);
#endif
      ansMin = min(ansMin, 2ll * p[dup] + (p[dup+sig]-p[dup]));
    }
    printf("%lld\n",ansMin);
  }

  return 0;
}
