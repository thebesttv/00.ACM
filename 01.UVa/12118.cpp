// Tag: 欧拉回路 ii
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

const int MAX = 1020;
int n,m,t; VR<int> G[MAX];
bool vis[MAX];

int bfs(int u){
  queue<int> q;
  q.push(u); vis[u] = 1;
  int cnt = 0;
  while(!q.empty()){
    u = q.front(); q.pop();
    if(G[u].size()&1) ++cnt;
    for(int v : G[u]) if(!vis[v]){
      q.push(v); vis[v] = 1;
    }
  }
  return cnt;
}

int main(void){
  int kase = 0;
  while(scanf("%d%d%d",&n,&m,&t)==3 && n){
    FORR(i,1,n) G[i].clear(), vis[i]=0;
    int u,v; int ans = m;
    while(m--){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);
    }

    int cnt0 = 0, cnt2 = 0, tot = 0;
    FORR(i,1,n) if(!vis[i] && G[i].size()){
      int s = bfs(i);
#ifdef DEBUG
      printf("  bfs(%d): %d\n",i,s);
#endif
      while(s > 2) s-=2, ++ans;
      if(s) ++cnt2;
      else ++cnt0;
      ++tot;
    }
    ans += max(0,tot - 1);
#ifdef DEBUG
    printf("cnt0: %d, cnt2: %d, cur ans: %d\n",cnt0,cnt2,ans);
#endif

    if(cnt0 >= 2){
      cnt0 -= 2;
      ans += (cnt0+1)/2;
    }
    printf("Case %d: %d\n",++kase,ans*=t);
  }

  return 0;
}
