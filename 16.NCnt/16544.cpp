// Tag: iii TODO 环 TSP 状压DP
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

const int MAX = 20;
const LL MOD = 998244353;
int n,m,k,cnt[1<<MAX]; LL f[1<<MAX][MAX],sum[MAX+2];  // nmd sum 越界了……fuck
bool G[MAX][MAX];

int cal(int x){
  int c = 0;
  //while(x) c += x&1, x>>=1;
  while(x) x&=(x-1), ++c;
  return c;
}

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}
LL rev(LL x) { return pow_mod(x,MOD-2); }

int main(void){
  FOR(i,0,1<<20) cnt[i] = cal(i);

  scanf("%d%d%d",&n,&m,&k);
  while(m--){
    int u,v; scanf("%d%d",&u,&v);
    G[u][v] = G[v][u] = 1;
  }

  MST(f,0); FOR(i,0,n) f[1<<i][i] = 1;
  FOR(st,0,1<<n) FOR(first,0,n) if(st&(1<<first)){
    FOR(i,first+1,n) if(st&(1<<i)){
      LL &a = f[st][i];
      FOR(j,0,n) if(j!=i && (st&(1<<j)) && G[i+1][j+1]){
        a = (a + f[st^(1<<i)][j])%MOD;
      }
      if(G[i+1][first+1]) sum[cnt[st]] = (sum[cnt[st]] + a)%MOD;
    }
    break;
  }

  LL rev2 = rev(2);
#ifdef DEBUG
  printf("ori:\n");
  FORR(i,0,n) printf("sum[%d]: %lld\n",i,sum[i]);
#endif
  FORR(i,3,n) sum[i] = sum[i] * rev2 %MOD;
#ifdef DEBUG
  printf("after:\n");
  FORR(i,0,n) printf("sum[%d]: %lld\n",i,sum[i]);
#endif

  FORR(i,1,k){
    LL ans = 0;
    FORR(j,3,n) if(j%k == i-1) ans = (ans + sum[j])%MOD;
    printf("%lld\n",ans);
  }

  return 0;
}
