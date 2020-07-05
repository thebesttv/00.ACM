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

const int MAX = 1e5 + 20;
const int MOD = 1e9 + 7;
int n;
LL a[MAX], C[1020], pow2[1020], powk[MAX][1020]; // powk[i][j] = a[i] ^ j
LL f[1020]; // f[k] = sum{ vi ^ k | 1<=i<=n}

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) d = a, x = 1, y = 0;
  else gcd(b, a%b, d, y, x), y-=x*(a/b);
}

LL rev(LL a){
  LL d,x,y;
  gcd(a,MOD,d,x,y);
  return (x+MOD)%MOD;
}

int main(void){
  pow2[0] = 1;
  FORR(i,1,1000)
    pow2[i] = (pow2[i-1]<<1)%MOD;

  C[0] = 1;
  FOR(k,1,1000)
    C[k] = (n-k+1) * rev(k) % MOD * C[k-1] % MOD;

  scanf("%d",&n);
  FORR(i,1,n) scanf("%lld",&a[i]);

  sort(a+1,a+1+n);
  FORR(i,1,n){
    powk[i][0] = 1;
    // sum[0] += pow[i][0];
    ++sum[0];
    FORR(j,1,1000){
      powk[i][j] = powk[i][j-1] * a[i] % MOD;
      sum[j] += pow[i][j];
    }
  }

  LL ans = 0;
  FORR(k,0,1000){
    
  }
  return 0;
}
