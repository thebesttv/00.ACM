// Tag: 状压DP
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

const int MOD = 100000000;
const int MAX = 14;
int n,m,G[MAX]; LL f[MAX][1<<13];

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    MST(G,0), MST(f,0);
    FORR(i,1,n) FOR(j,0,m){
      int x; scanf("%d",&x);
      if(x) G[i] |= 1<<j;
      else  G[i] &= ~(1<<j);
    }
    f[0][0] = 1; G[0] = 0;
    FORR(i,1,n) FOR(st1,0,1<<m) if((st1 | G[i]) == G[i] && (st1 & (st1<<1))==0){
      FOR(st2,0,1<<m) if((st2 | G[i-1]) == G[i-1] && (st2 & (st2<<1)) == 0 && (st2 & st1) == 0){
        f[i][st1] = (f[i][st1] + f[i-1][st2])%MOD;
      }
#ifdef DEBUG
      if(f[i][st1]) printf("f[%d][%d]: %lld\n",i,st1,f[i][st1]);
#endif
    }
    LL ans = 0;
    FOR(st,0,1<<m) ans = (ans + f[n][st])%MOD;
    printf("%lld\n",ans);
  }

  return 0;
}
