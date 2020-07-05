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

const int MAX = 1e5 + 20;
int n,m,s,k,c[MAX];
int d[MAX][104];
bool vis[MAX];
VR<int> G[MAX],cv[104];

void bfs(int col){
  //MST(vis,0);
  queue<int> q;
  for(int u : cv[col])
    q.push(u), d[u][col]=0;

  while(!q.empty()){
    int u = q.front(); q.pop();
    int t = d[u][col]+1;
    for(int v : G[u]) if(d[v][col]>t){
      d[v][col] = t; q.push(v);
    }
  }
}

int main(void){
  MST(d,0x3f);
  scanf("%d%d%d%d",&n,&m,&k,&s);
  FORR(i,1,n){
    scanf("%d",&c[i]);
    cv[c[i]].push_back(i);
  }

  int u,v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  FORR(i,1,k) bfs(i);
#ifdef DEBUG
  FORR(u,1,n){
    FORR(i,1,k) printf("  d[%d][%d]: %d\n",
        u,i,d[u][i]);
  }
#endif

  FORR(i,1,n){
    int ans = 0;
    sort(d[i]+1,d[i]+1+k);
    FORR(j,1,s) ans += d[i][j];
    printf("%d ",ans);
  }
  putchar('\n');

  return 0;
}
