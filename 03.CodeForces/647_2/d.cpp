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

const int MAX = 5e5 + 20;
int n,m,f[MAX];
VR<int> G[MAX], t[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  while(m--){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  FORR(u,1,n){
    scanf("%d",&v);
    t[v].push_back(u);
  }

  bool ok = 1;
  VR<int> ans;
  FORR(i,1,n){
    for(int u : t[i]){
      if(f[u] != i-1){
        ok = 0; break;
      }
      for(int v : G[u])
        if(f[v] == i-1)
          f[v] = i;
      ans.push_back(u);
    }
    if(!ok) break;
  }

  if(!ok) printf("-1");
  else for(int x : ans) printf("%d ",x);
  putchar('\n');

  return 0;
}
