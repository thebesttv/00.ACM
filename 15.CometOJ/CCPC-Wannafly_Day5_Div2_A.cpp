// https://www.cometoj.com/contest/23/problem/A?problem_id=326
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
int n,m,dep[MAX],dfn[MAX],dfnCnt;
VR<int> G[MAX];

void dfs(int u, int d){
  dfn[u] = ++dfnCnt;
  dep[u] = d;
  for(int v : G[u]) if(!dfn[v]){
    dfs(v, d+1);
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  int u, v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1,1);
  FORR(i,1,n)
    printf("%d %d\n",dep[i],dfn[i]);

  return 0;
}
