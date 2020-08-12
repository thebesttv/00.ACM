// Tag: 树状DP
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

const int MAX = 1e5 + 20;
int n,b[MAX];LL dp[MAX],ansMax;
VR<int> G[MAX];

LL f(int u, int fa){
  LL &a = dp[u];
  if(a!=-1) return a;
  a = 0; VR<LL> vec;
  for(int v : G[u]) if(v!=fa) vec.pb(f(v,u));

  sort(ALL(vec),greater<LL>());
  a = b[u] + max(vec.size() ? vec[0] : 0, 0ll);
  ansMax = max(ansMax, a + max(vec.size() >= 2 ? vec[1] : 0, 0ll));

  return a;
}

int main(void){
  MST(dp,-1); scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&b[i]);
  ansMax = b[1]; int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].pb(v), G[v].pb(u);
  }

  f(1,-1);
  printf("%lld\n",ansMax);

  return 0;
}
