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

const int MAX = 1e6, MAX_ = MAX+20;
const int MOD = 1e9+7;
int n,m;
int mu[MAX_],f[MAX_],rf[MAX_],g[MAX_];

int pow_mod(int a, LL x){
  int ans=1;
  while(x){
    if(x&1) ans=1ll*ans*a%MOD;
    a=1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}
int rev(int n){
  return pow_mod(n,MOD-2);
}

void init(){
  f[0]=rf[0]=0; f[1]=rf[1]=1;
  mu[1]=1;
  FORR(i,1,MAX){
    g[i] = 1;
    if(i>1){
      f[i] = (f[i-1]+f[i-2])%MOD;
      rf[i] = rev(f[i]);
    }
    for(int j=i+i;j<=MAX;j+=i){
      mu[j]-=mu[i];
    }
  }

  g[0]=1;
  FORR(i,1,MAX){
    for(int j=i,cnt=1;j<=MAX;j+=i,++cnt) if(mu[cnt]){
      g[j] = 1ll*g[j]*(mu[cnt]==1 ? f[i] : rf[i])%MOD;
    }
    g[i] = 1ll*g[i]*g[i-1]%MOD;
  }
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    int ans=1, i=1, j;
    while(i<=n){
      j = min(n/(n/i), m/(m/i));
      ans = 1ll*ans*pow_mod( 1ll*g[j]*rev(g[i-1])%MOD, 1ll*(n/i)*(m/i))%MOD;
      i = j+1;
    }
    printf("%d\n",ans);
  }

  return 0;
}


















































/*
const int MAX = 1e6, MAX_ = MAX + 20;
const LL MOD = 1e9 + 7;
int n,m;

int pow_mod(int a, LL x){
  int ans = 1;
  while(x){
    if(x&1) ans = 1ll*ans*a%MOD;
    a = 1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}

int rev(int n){
  return pow_mod(n,MOD-2);
}

int mu[MAX_], fib[MAX_], rfib[MAX_], f[MAX_];
void init(){
  mu[1] = 1; fib[1] = 1;

  FORR(i,1,MAX){
    if(i>1) fib[i] = (fib[i-1] + fib[i-2])%MOD;
    rfib[i] = rev(fib[i]);

    f[i] = 1;

    for(int j=i+i;j<=MAX;j+=i){
      mu[j] -= mu[i];
    }
  }
  f[0] = 1;
  FORR(i,1,MAX){
    for(int j=i,cnt=1;j<=MAX;j+=i,++cnt) if(mu[cnt]){
      f[j] = f[j] * 1ll * (mu[cnt]==1 ? fib[i] : rfib[i]) % MOD;
    }
    f[i] = 1ll*f[i]*f[i-1]%MOD;
  }
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    int ans = 1, i = 1, j;
    while(i<=n){
      j = min(n/(n/i), m/(m/i));
      ans = 1ll*ans * pow_mod( int(1ll * f[j] * rev(f[i-1]) % MOD), 1ll*(n/i)*(m/i)) % MOD;
      i = j + 1;
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
