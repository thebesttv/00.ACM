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

const int MAX = 1e5, MAX_ = 1e5 + 20;
const int MOD = 998244353;
int n,c,d,q,b[MAX_],x[MAX_];
int mu[MAX_];
int f[MAX_], fr[MAX_], rfr[MAX_], z[MAX_], rpowD[MAX_];

int pow_mod(int a, int x){
  int ans = 1;
  while(x){
    if(x&1) ans = 1ll*ans*a%MOD;
    a = 1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}

int rev(int n){
  return pow_mod(n, MOD-2);
}

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}
int lcm(int a, int b){
  return a/gcd(a,b)*b;
}

void Moebius(int *f, int *g, int n){
  FORR(i,1,n) g[i]=f[i];
  FORR(i,1,n) for(int j=i+i;j<=n;j+=i)
    g[j] = (g[j] - g[i] + MOD)%MOD;
}

bool solve(){
  FORR(i,1,n){
    scanf("%d",&b[i]);
    b[i] = 1ll*b[i]*rpowD[i]%MOD;
  }
  Moebius(b, z, n);
  FORR(i,1,n){
    if(fr[i]==0 && z[i])
      return false;
    else if(fr[i]) z[i] = 1ll*z[i] * rfr[i]%MOD;
    // z[i] = 1ll*z[i] * rfr[i]%MOD;
  }
#ifdef DEBUG
  FORR(i,1,n) printf("  z[%d]: %d\n",i,z[i]);
#endif

  // Moebius(z, x, n);
  /*
  FORR(i,1,n){
    x[i] = 0;
    for(int j=i,cnt=1;j<=n;j+=i,++cnt)
      x[i] = (x[i] + 1ll*mu[cnt]*z[j])%MOD;
    x[i] = (x[i]+MOD)%MOD;
  }
  */
  FORR(i,1,n) x[i] = z[i];
  ROR(i,n,1){
    for(int j=i+i;j<=n;j+=i)
      x[i] = (x[i] - x[j])%MOD;
    x[i] = (x[i]+MOD)%MOD;
  }

  FORR(i,1,n) x[i] = 1ll*x[i] * rpowD[i]%MOD;
  return true;
}

int main(void){
  mu[1] = 1;
  FORR(i,1,MAX) for(int j=i+i;j<=MAX;j+=i)
    mu[j] -= mu[i];

  scanf("%d%d%d%d",&n,&c,&d,&q);
  f[1] = 1, rpowD[1] = 1;
  FORR(i,2,n){
    if(c-d>=0) f[i] = pow_mod(i, c-d);
    else f[i] = rev(pow_mod(i, d-c));
    rpowD[i] = rev(pow_mod(i,d));
  }
  Moebius(f, fr, n);
  FORR(i,1,n) rfr[i] = rev(fr[i]);

#ifdef DEBUG
  FORR(i,1,n) printf("  fr[%d]: %d, rev: %d\n",i,fr[i],rfr[i]);
#endif

  while(q--){
    if(!solve()) printf("-1");
    else FORR(i,1,n) printf("%d ",x[i]);
    putchar('\n');
  }

  return 0;
}
