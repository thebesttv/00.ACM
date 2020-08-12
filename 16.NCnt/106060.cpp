// Tag: 树的最小点覆盖
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

const int MAX = 1520;
int n,dp[MAX][2];
VR<int> G[MAX];

int f(int u, int op, int fa){
  int &a = dp[u][op];
  if(a!=-1) return a;

  if(op){
    a = 1;
    //for(int v : G[u]) if(v!=fa)
    //  a += min(f(v,0,u),f(v,1,u));
    FOR(i,0,G[u].size()) if(G[u][i]!=fa)
      a += min(f(G[u][i],0,u),f(G[u][i],1,u));
  }else{
    a = 0;
    //for(int v : G[u]) if(v!=fa)
    //  a += f(v,1,u);
    FOR(i,0,G[u].size()) if(G[u][i]!=fa)
      a += f(G[u][i],1,u);
  }

  return a;
}

int main(void){
  while(scanf("%d",&n)==1){
    FORR(i,1,n) G[i].clear(), dp[i][0]=dp[i][1]=-1;
    int u,v,x;
    FORR(i,1,n){
      scanf("%d:(%d)",&u,&x); ++u;
      while(x--){
        scanf("%d",&v); ++v;
        G[u].push_back(v);
        G[v].push_back(u);
#ifdef DEBUG
        printf("(%d, %d)\n",u,v);
#endif
      }
    }
    printf("%d\n",min(f(1,0,-1), f(1,1,-1)));
  }

  return 0;
}
