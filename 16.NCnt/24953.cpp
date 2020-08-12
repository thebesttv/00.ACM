// Tag: 树的最小支配集 i
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

const int MAX = 10020;
int n,dp[MAX][3];
VR<int> G[MAX];

int f(int u, int op, int fa){
  int &a = dp[u][op];
  if(a != -1) return a;
  if(op == 0){  // u
    a = 1;
    for(int v : G[u]) if(v!=fa)
      a += min(f(v,0,u), min(f(v,1,u), f(v,2,u)));
  }else if(op == 1){  // v
    a = 0; int inc = n; // <b> at least one v is chosen, a = sum(min(f(v,0),f(v,1))) + inc </b>
    for(int v : G[u]) if(v!=fa){
      int f0 = f(v,0,u), f1 = f(v,1,u);
      if(f0 <= f1) inc = 0, a += f0;
      else inc = min(inc, f0-f1), a += f1;
    }
    a += inc;
  }else{  // fa
    a = 0;
    for(int v : G[u]) if(v!=fa)
      a += min(f(v,0,u), f(v,1,u));
  }
  return a;
}

int main(void){
  MST(dp,-1);
  scanf("%d",&n); int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].pb(v); G[v].pb(u);
  }
  printf("%d\n",min(f(1,0,-1),f(1,1,-1)));

  return 0;
}
