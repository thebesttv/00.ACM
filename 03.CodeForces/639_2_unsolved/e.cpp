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
int n, m, vis[MAX], to[MAX];
VR<int> G[MAX];
char s[MAX];

bool dfs(int u){
  if(vis[u] == -1) return false;

  vis[u] = -1;
  for(int v : G[u]) if(vis[u] != 1){
    if(!dfs(v)) return false;
  }
  vis[u] = 1;
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u, v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    ++to[v];
  }

  bool bad = 0;
  FORR(i,1,n) if(!vis[i]){
    if(!dfs(i)){
      bad = 1; break;
    }
  }

  if(bad){
    printf("-1\n"); return 0;
  }

  int cnt = 0;
  FORR(i,1,n)
    if(!to[i]){
      ++cnt;
      s[i] = 'A';
    }else{
      s[i] = 'E';
    }

  printf("%d\n%s\n",cnt,s+1);

  return 0;
}
