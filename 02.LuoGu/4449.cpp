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

const int MAX = 5000000, MAX_ = MAX+20;
const int MOD = 1000000007;
int n,m,k;

int power(int a, int x){
  if(x==0) return 1;
  if(x==1) return a;
  int ans = power(a,x>>1);
  ans = 1ll * ans * ans % MOD;
  if(x&1) ans = 1ll * ans * a % MOD;
  return ans;
}

bool vis[MAX_];
VR<int> prime;
int mu[MAX_];
int powN[MAX_], g[MAX_];

void init(){
  mu[1] = 1, powN[1] = 1, g[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      mu[i] = -1;
      powN[i] = power(i,k);
      g[i] = powN[i] - 1;
    }

    for(int p : prime){
      int t = p * i;
      if(t>MAX) break;
      vis[t] = 1;
      powN[t] = 1ll * powN[p] * powN[i] % MOD;
      if(i%p==0){
        mu[t] = 0;
        g[t] = 1ll * powN[p] * g[i] % MOD;
        break;
      }else{
        mu[t] = -mu[i];
        g[t] = (powN[p]-1ll) * g[i] % MOD;
      }
    }
  }

  FORR(i,2,MAX){
    mu[i] += mu[i-1];
    g[i] = (1ll*g[i] + g[i-1]) % MOD;
  }
}

int main(void){
  int T; scanf("%d%d",&T,&k);
  init();
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    int ans = 0;
    int i = 1, j;
    while(i<=n){
      j = min( n/(n/i), m/(m/i) );
      ans = (ans + 1ll*(n/i)*(m/i)%MOD * (g[j]-g[i-1]+MOD ) % MOD )%MOD;
      i = j+1;
    }
    printf("%d\n",ans);
  }

  return 0;
}

/*
const int MAX = 5000000, MAX_ = MAX+20;
const LL MOD = 1000000007;
int n,m,k;

LL power(int a, int x){
  if(x==0) return 1;
  if(x==1) return a;
  LL ans = power(a,x>>1);
  ans = ans * ans % MOD;
  if(x&1) ans = ans * a % MOD;
  return ans;
}

bool vis[MAX_];
VR<int> prime;
int mu[MAX_];
LL powN[MAX_], g[MAX_];

void init(){
  mu[1] = 1, powN[1] = 1, g[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      mu[i] = -1;
      powN[i] = power(i,k);
      g[i] = powN[i] - 1;
    }

    for(int p : prime){
      int t = p * i;
      if(t>MAX) break;
      vis[t] = 1;
      powN[t] = powN[p] * powN[i] % MOD;
      if(i%p==0){
        mu[t] = 0;
        g[t] = powN[p] * g[i] % MOD;
        break;
      }else{
        mu[t] = -mu[i];
        g[t] = (powN[p]-1) * g[i] % MOD;
      }
    }
  }

  FORR(i,2,MAX){
    mu[i] += mu[i-1];
    g[i] = (g[i-1] + g[i]) % MOD;
  }
#ifdef DEBUG
  FORR(i,1,100) printf("  mu[%d]: %d, pow[%d]: %lld\n",
      i, mu[i]-mu[i-1], i, powN[i]-powN[i-1]);
#endif
}

int main(void){
  int T; scanf("%d%d",&T,&k);
  init();
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    LL ans = 0;
    int i = 1, j;
    while(i<=n){
      j = min( n/(n/i), m/(m/i) );
      ans = (ans + 1ll*(n/i)*(m/i)%MOD * ( (g[j]-g[i-1]+MOD)%MOD )%MOD )%MOD;
      i = j+1;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
*/

/*
const int MAX = 5000000, MAX_ = MAX+20;
const LL MOD = 1000000007;
int n,m,k;

LL power(int a, int x){
  if(x==0) return 1;
  if(x==1) return a;
  LL ans = power(a,x>>1);
  ans = ans * ans % MOD;
  if(x&1) ans = ans * a % MOD;
  return ans;
}

bool vis[MAX_];
VR<int> prime;
int mu[MAX_];
LL powN[MAX_];

void init(){
  mu[1] = 1, powN[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      mu[i] = -1;
      powN[i] = power(i,k);
    }
    for(int p : prime){
      int t = p * i;
      if(t>MAX) break;
      vis[t] = 1;
      powN[t] = powN[p] * powN[i] % MOD;
      if(i%p==0){
        mu[t] = 0;
        break;
      }else{
        mu[t] = -mu[i];
      }
    }
  }
  FORR(i,2,MAX){
    mu[i] += mu[i-1];
    powN[i] = (powN[i] + powN[i-1]) % MOD;
  }
#ifdef DEBUG
  FORR(i,1,100) printf("  mu[%d]: %d, pow[%d]: %lld\n",
      i, mu[i]-mu[i-1], i, powN[i]-powN[i-1]);
#endif
}

LL f(int n, int m){
  LL ans = 0;
  int i = 1, j;
  while(i<=n){
    j = min( n/(n/i), m/(m/i) );
    ans = (ans + 1ll*(n/i)*(m/i)*(mu[j]-mu[i-1]) )%MOD;
    i = j+1;
  }
  return ans;
}

int main(void){
  int T; scanf("%d%d",&T,&k);
  init();
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    LL ans = 0;
    int i = 1, j;
    while(i<=n){
      j = min( n/(n/i), m/(m/i) );
      ans = (ans + f(n/i, m/i) * ( (powN[j]-powN[i-1]+MOD)%MOD )%MOD )%MOD;
      i = j+1;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
*/
