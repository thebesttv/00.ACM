// Tag: 树形DP ii
// 排列构成小根堆，令
//  f[i] 表示以 i 为根的子树的排列个数
//  g[i] 表示子树节点个数
//  f[i] = C(g[i]-1, g[i*2]) * f[i*2] * f[i*2+1]
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

const int MAX = 2e6 + 20;
int n,g[MAX]; LL f[MAX],frac[MAX],rfrac[MAX],MOD;

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}
LL rev(LL x){
  return pow_mod(x,MOD-2);
}
LL C(int n, int m){
  return frac[n] * rfrac[m] %MOD * rfrac[n-m]%MOD;
}

int main(void){
  scanf("%d%lld",&n,&MOD);
  frac[0] = rfrac[0] = 1;
  FORR(i,1,int(1e6))
    frac[i] = frac[i-1]*i%MOD,
    rfrac[i] = rev(frac[i]);

  ROR(i,n,1) g[i] = 1 + g[i<<1] + g[i<<1|1];
  ROR(i,n,1){
    LL c = C(g[i]-1, g[i<<1]);
    f[i] = c * max(f[i<<1],1ll) %MOD * max(f[i<<1|1],1ll) %MOD;
#ifdef DEBUG
    printf("f[%d]: %lld * %lld * %lld = %lld\n",i,c,f[i<<2],f[i<<2|1],f[i]);
#endif
  }
  printf("%lld\n",f[1]);

  return 0;
}
