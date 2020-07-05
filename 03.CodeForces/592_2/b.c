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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1020;
int n,f[2][MAX],ansMax; char canGo[MAX];
bool vis[2][MAX];

void dfs(int i, int j, int cnt){
  ansMax=max(ansMax,cnt);
  vis[i][j]=1;
  /*
  if(j<n && !vis[i][j+1]){
    dfs(i,j+1,cnt+1);
  }
  if(j>1 && !vis[i][j-1]){
    dfs(i,j-1,cnt+1);
  }
  if(canGo[j]=='1' && !vis[i^1][j]){
    dfs(i^1,j,cnt+1);
  }
  */
  if(canGo[j]=='1' && !vis[i^1][j]){
    dfs(i^1,j,cnt+1);
  }else{
    if(j<n && !vis[i][j+1]){
      dfs(i,j+1,cnt+1);
    }
    if(j>1 && !vis[i][j-1]){
      dfs(i,j-1,cnt+1);
    }
  }
  vis[i][j]=0;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    ansMax=0;
    scanf("%d",&n); scanf("%s",canGo+1);
    if(canGo[1]=='1' || canGo[n]=='1'){
      printf("%d\n",n*2); continue;
    }
    MST(vis,0); dfs(0,1,1);

    for(int i=1,j=n;i<j;i++,j--){
      swap(canGo[i],canGo[j]);
    }
    MST(vis,0); dfs(0,1,1);
    printf("%d\n",ansMax);
  }

  return 0;
}

/*
const int MAX=1020;
int n,f[2][MAX]; char canGo[MAX];

int dp(int i, int j){
  int &a=f[i][j];
  if(a!=-1) return a;
  a=1;
  if(j<n){
    //a = max(a, dp(i,j+1) + 1);
    if(dp(i,j+1)+1>a){
      a = dp(i,j+1) + 1;
      printf("  f[%d][%d] <- %d %d: %d\n",i,j,i,j+1,dp(i,j+1));

    }
  }
  if(canGo[j]=='1'){
    //a = max(a, dp(i^1,j) + 1);
    if(dp(i^1,j)+1>a){
      a = dp(i^1,j) + 1;
      printf("  f[%d][%d] <- %d %d: %d\n",i,j,i^1,j,dp(i^1,j));
    }

  }
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,-1);
    scanf("%d",&n); scanf("%s",canGo+1);
    int ansMax=1;
    FORR(j,1,n) ansMax=max(ansMax, max(dp(0,j),dp(1,j)));
#ifdef DEBUG
    FORR(j,1,n) FOR(i,0,2)
      printf("  f[%d][%d]: %d\n",i,j,dp(i,j));
#endif
    printf("%d\n",ansMax);
  }

  return 0;
}
*/
