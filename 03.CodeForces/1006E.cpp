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

const int MAX = 2e5 + 20;
int n,q,size[MAX],dfn[MAX],mp[MAX];
VR<int> G[MAX];

int dfnCnt=0;
int dfs(int u){
  dfn[u] = ++dfnCnt;
  mp[dfn[u]] = u;

  int &s = size[u]; s=1;
  for(int v : G[u]){
    s += dfs(v);
  }
  return s;
}

int main(void){
  scanf("%d%d",&n,&q);
  int u,k;
  FORR(i,2,n){
    scanf("%d",&u);
    G[u].push_back(i);
  }
  dfs(1);

  while(q--){
    scanf("%d%d",&u,&k);
    int ans = -1;
    if(k <= size[u])
      ans = mp[dfn[u]+k-1];
    printf("%d\n",ans);
  }

  return 0;
}
