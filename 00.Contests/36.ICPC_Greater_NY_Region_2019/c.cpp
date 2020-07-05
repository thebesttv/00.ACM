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

const int MAX = 40;
const double EPS = 0;
int n,m, su, eu;
VR<int> G[MAX];
double ans[MAX], f[MAX], g[MAX];

double cal(){
  FORR(i,1,n) f[i] = g[i] = 0;
  f[su] = 1; double sum = 0;
  FOR(round,0,100){
    sum += f[eu];
    FORR(u,1,n) for(int v : G[u])
      g[v] += f[u] / (G[u].size()+1);
    memcpy(f,g,sizeof(g)); MST(g,0);
  }
  return sum / (G[eu].size()+1);
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(u,1,n){
    int x, v; scanf("%d",&x);
    while(x--) scanf("%d",&v), G[u].push_back(v);
  }

  FOR(i,0,m){
    int idx;
    scanf("%d%d%d",&idx,&su,&eu);
    ans[idx] = cal();
  }
  FORR(i,1,m) printf("%d %.5lf\n",i,ans[i]);

  return 0;
}

/*
const int MAX = 40;
const double EPS = 1e14;
int n,m, su, eu;
VR<int> G[MAX];
double ans[MAX], f;

void dfs(int u, double p){
  if(p > EPS) return;
  double d = G[u].size()+1;
  if(u == eu) f += 1 / d / p;

  for(int v : G[u])
    dfs(v, d * p);
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(u,1,n){
    int x, v; scanf("%d",&x);
    while(x--) scanf("%d",&v), G[u].push_back(v);
  }

  FOR(i,0,m){
    f = 0; int idx;
    scanf("%d%d%d",&idx,&su,&eu);
    dfs(su, 1);
    ans[idx] = f;
  }
  FORR(i,1,m) printf("%d %.5lf\n",i,ans[i]);

  return 0;
}
*/
