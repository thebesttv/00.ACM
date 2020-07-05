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

// 为啥dp只要25层就可以了……

const int MAX = 5e5;
const int THE = 25;
int n,m,c[MAX];
double dp[MAX][THE];
VR<int> G[MAX];

double f(int u, int i){
  if(i>=THE) return 0;
  double &a = dp[u][i];
  if(a>=0) return a;
  double t = 1.0 * c[u] / (1ll<<i);
  a = t;
  for(int v : G[u]){
    a = max(a, max(f(v, i), f(v,i+1) + t));
  }
  return a;
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n){
    scanf("%d",&c[i]);
    FOR(j,0,THE) dp[i][j] = -1;
  }
  int u, v;
  while(m--){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
  }
  printf("%lf\n", f(0,0));

  return 0;
}
