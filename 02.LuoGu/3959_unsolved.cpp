// Tag: 
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
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
int n,m,G[20][20],dp[1<<12][14][14];

int f(int st, int u, int d){
  int &a = dp[st][u][d];
  if(a!=-1) return a;
  a = INF;
  if(d >= 1) FORR(v,1,n) if(u!=v && (st&(1<<(v-1))) && G[u][v]!=INF){
    a = min(a, f(st & (~(1<<(u-1))), v, d-1) + G[u][v] * d);
  }
#ifdef DEBUG
  if(a!=INF){
    printf("f(");
    FOR(i,0,n) putchar('0' + ((st>>i)&1));
    printf(", %d, %d): %d\n",u,d,a);
  }
#endif
  return a;
}

int main(void){
  MST(G,0x3f), MST(dp,-1);
  scanf("%d%d",&n,&m);
  while(m--){
    int u,v,w; scanf("%d%d%d",&u,&v,&w);
    G[u][v] = G[v][u] = min(G[u][v], w);
  }
  FOR(i,0,n) dp[1<<i][i+1][0] = 0;
  int ansMin = INF, st = (1<<n)-1;
  FORR(i,1,n) FORR(d,0,n)
    ansMin = min(ansMin,f(st,i,d));
  printf("%d\n",ansMin);

  return 0;
}
