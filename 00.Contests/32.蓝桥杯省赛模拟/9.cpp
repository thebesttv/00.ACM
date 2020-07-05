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
int n, sum = 0, ansMax = 0;
VR<int> G[MAX];

struct Cir{
  int x,y,r,r2;
}cir[MAX];
int ok[MAX];

bool conf(Cir &a, Cir &b){
  int d2 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
  return d2 < (a.r+b.r)*(a.r+b.r);
}

void dfs(int u, int curSum, int delim){
#ifdef DEBUG
  printf("  dfs(%d,%d,%d)\n",u,curSum,delim);
#endif
  if(sum - delim <= ansMax) return;
  ansMax = max(ansMax, curSum);
  if(u == n+1) return;

  if(ok[u]==1){
    int tdelim = 0;
    for(int v : G[u]){
#ifdef DEBUG
      printf("  u: %d, disable %d\n",u,v);
#endif
      --ok[v];
      if(ok[v] == 0)  // <b> </b>
        tdelim += cir[v].r2;
    }

    dfs(u+1, curSum + cir[u].r2, delim + tdelim);

    for(int v : G[u]) ++ok[v];
  }

  dfs(u+1, curSum, delim);
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d%d%d",&cir[i].x,&cir[i].y,&cir[i].r);
    cir[i].r2 = cir[i].r * cir[i].r;
    sum += cir[i].r2;
    FOR(j,1,i) if(conf(cir[i],cir[j])){
      G[i].push_back(j);
      G[j].push_back(i);
    }
    ok[i] = 1;
  }

  dfs(1, 0, 0);

  printf("%d\n",ansMax);

  return 0;
}
