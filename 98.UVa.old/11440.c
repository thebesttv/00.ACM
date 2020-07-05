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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1e7, sMAX = sqrt(MAX+0.5);
const int MOD = 100000007;
int n, m;
LL phifrac[MAX]; bool vis[MAX];

int main(void){
  phifrac[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){  // i is prime
      for(LL j=LL(i)*i;j<=MAX;j+=i) vis[j]=1;
      phifrac[i] = phifrac[i-1] * (i-1) % MOD;
    }else{
      phifrac[i] = phifrac[i-1] * i % MOD;
    }
  }

  while(scanf("%d%d",&n,&m)==2 && n){
    LL mul = 1;
    FORR(i,m+1,n) mul = mul * i % MOD;
    LL ans = mul * phifrac[m] % MOD;
    ans = (ans - 1 + MOD)%MOD;
    printf("%lld\n",ans);
  }

  return 0;
}
