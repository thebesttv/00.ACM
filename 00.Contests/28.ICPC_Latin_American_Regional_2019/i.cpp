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

const int MAX = 2020;
const LL MOD = 1e9+7;
int n,m,to[MAX];
LL cnt[MAX]; bool vis[MAX];
VR<int> G[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,m){
    int k,x; scanf("%d",&k);
    while(k--){
      scanf("%d",&x);
      if(x==1) continue;
      G[i].push_back(x);
      ++to[x];
    }
  }

  queue<int> q;
  cnt[1] = 1; vis[1] = 1;
  FORR(i,1,m) if(!to[i]){
    q.push(i);
  }
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v : G[u]){
      if(vis[u]) vis[v] = 1;
      cnt[v] = (cnt[v] + cnt[u])%MOD;
      --to[v];
      if(!to[v]) q.push(v);
    }
  }
  LL ans = 0, ans2 = 0;
  FORR(i,m+1,n) if(cnt[i] || vis[i]){
    ans = (ans+cnt[i])%MOD;
    ++ans2;
  }
  printf("%lld %lld\n",ans,ans2);

  return 0;
}
