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

LL n,MOD;

inline LL V2IDX(LL v, LL N, LL Ndr, LL nv) {
  return v >= Ndr ? (N/v - 1) : (nv - v);
}

LL primesum(LL N) {
  LL *S; LL *V;

  LL r = (LL)sqrt(N);
  LL Ndr = N/r;

  LL nv = r + Ndr - 1;

  V = new LL[nv];
  S = new LL[nv];

  for (LL i=0; i<r; i++) {
    V[i] = N/(i+1);
  }
  for (LL i=r; i<nv; i++) {
    V[i] = V[i-1] - 1;
  }

  for (LL i=0; i<nv; i++) {
    S[i] = V[i] * (V[i] + 1) / 2 - 1;
  }

  for (LL p=2; p<=r; p++) {
    if (S[nv-p] > S[nv-p+1]) {
      LL sp = S[nv-p+1];
      LL p2 = p*p;
      for (LL i=0; i<nv; i++) {
        if (V[i] >= p2) {
          S[i] -= p * (S[V2IDX(V[i]/p, N, Ndr, nv)] - sp);
        } else {
          break;
        }
      }
    }
  }

  return S[0] % MOD;
}

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}
LL rev(LL x) { return pow_mod(x, MOD-2); }

int main() {
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&n,&MOD);
    if(n == 1){
      printf("0\n");
    }else if(n == 2){
      printf("6\n");
    }else{
      LL ans = ((n + 4) % MOD * (n-1)%MOD * rev(2) %MOD + primesum(n+1) - 2 + MOD)%MOD;
      printf("%lld\n",ans);
    }
  }
}
