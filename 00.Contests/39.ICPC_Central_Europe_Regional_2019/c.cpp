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

const int MAX = 3e5 + 20;
int n,to[MAX]; VR<int> G[MAX];
int ans; bool vis[MAX];

void dfs(int u){
  vis[u] = 1;
  int cnt = 0;
  for(int v : G[u]) if(!vis[v]){
    dfs(v); ++cnt;
  }
  if(cnt >= 2) ans += cnt-1;
}

int main(void){
  scanf("%d",&n);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
    ++to[u], ++to[v];
  }
  FORR(i,1,n) if(to[i]==1){
    dfs(i); break;
  }
  printf("%d\n",ans);

  return 0;
}
