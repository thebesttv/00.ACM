// Tag: notag
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1020;
const int INF = 0x3f3f3f3f;
int n,dp[MAX],ansMin,r;
VR<int> G[MAX];

int f(int u){
  int &a = dp[u];
  if(a) return a;

  a = 1; int tMax = 0;
  for(int v : G[u]) if(!dp[v]){
    a += f(v); tMax = max(tMax, f(v));
  }
  tMax = max(tMax, n-a);

  if(tMax < ansMin){
    ansMin = tMax, r = u;
  }else if(tMax == ansMin){
    r = min(r, u);
  }
  return a;
}

int main(void){
  while(scanf("%d",&n)==1){
    ansMin = INF, r = -1;
    FORR(i,1,n) dp[i]=0,G[i].clear();
    int u,v;
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    f(1);
    printf("%d %d\n",r,ansMin);
  }

  return 0;
}
