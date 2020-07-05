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

const int MAX = 5020;
int n,m,n1,n2,n3, col[MAX]; bool vis[MAX];
VR<int> G[MAX];
int belong[MAX], cnt[MAX][2];
int f[MAX][MAX], g[MAX][MAX], ans[MAX], chosen[MAX];

bool dfs(int u, int color, int ccCnt){
  vis[u] = 1, col[u] = color, belong[u] = ccCnt;
  for(int v : G[u]){
    if(vis[v]){
      if(col[v] == color)
        return false;
      continue;
    }

    if(!dfs(v, color^1, ccCnt))
      return false;
  }
  return true;
}

int main(void){
  scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&n3);
  int u,v;
  while(m--){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int ccCnt = 0;
  FORR(i,1,n){
    if(!vis[i] && !dfs(i, 0, ++ccCnt)){
        printf("NO\n"); return 0;
    }
    ++cnt[belong[i]][col[i]];
  }

#ifdef DEBUG
  FORR(i,1,ccCnt) printf("  component %d: %d, %d\n",i,cnt[i][0],cnt[i][1]);
#endif

  f[0][0] = 1;
  FORR(i,1,ccCnt) FORR(j,0,n){
    if(j >= cnt[i][0] && f[i-1][j-cnt[i][0]]){
      f[i][j] = 1; g[i][j] = 0; continue;
    }
    if(j >= cnt[i][1] && f[i-1][j-cnt[i][1]]){
      f[i][j] = 1; g[i][j] = 1; continue;
    }
  }

  if(!f[ccCnt][n2] || !f[ccCnt][n1+n3]){
    printf("NO\n"); return 0;
  }
#ifdef DEBUG
  FORR(i,1,ccCnt) FORR(j,0,n)
    if(f[i][j]) printf("    %d, %d\n",i,j);
#endif

  int remain = n2;
  ROR(i,ccCnt,1){
    int color = g[i][remain];
    chosen[i] = color;
    remain -= cnt[i][color];
  }

  printf("YES\n");
  FORR(i,1,n){
    if(chosen[belong[i]] == col[i]){
      ans[i] = 2;
    }else if(n1){
      ans[i] = 1; --n1;
    }else{
      ans[i] = 3;
    }
    printf("%d",ans[i]);
  }
  putchar('\n');

  return 0;
}
