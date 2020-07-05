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

const int MAX = 1e5, MAX_ = MAX + 20;
const int MOD = 1e9 + 7;
int n, f;

VR<int> d[MAX_];
int mu[MAX_], frac[MAX_], rfrac[MAX_];;

int pow_mod(int a, int x){
  int ans=1;
  while(x){
    if(x&1) ans=1ll*ans*a%MOD;
    a=1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}

int rev(int n){
  return pow_mod(n, MOD-2);
}

void init(){
  mu[1] = 1;
  frac[0] = rfrac[0] = 1;
  FORR(i,1,MAX){
    d[i].push_back(i);
    for(int j=i+i;j<=MAX;j+=i){
      mu[j] -= mu[i];
      d[j].push_back(i);
    }
    frac[i] = 1ll*frac[i-1]*i%MOD;
    rfrac[i] = rev(frac[i]);
#ifdef DEBUG
    if(i<10) printf(" frac[%d]: %d, rev: %d, mu[%d]: %d\n",i,frac[i],rfrac[i],i,mu[i]);
#endif
  }
}

int C(int n, int m){
  if(n<m) return 0;
  return 1ll*frac[n]*rfrac[m]%MOD*rfrac[n-m]%MOD;
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&f);
    int ans = 0;
    for(int i : d[n]){
      ans = (ans + 1ll*mu[n/i]*C(i-1,f-1))%MOD;
    }
    ans = (ans+MOD)%MOD;
    printf("%d\n",ans);
  }

  return 0;
}

/*
const int MAX = 1e5, MAX_ = 1e5 + 20;
const int MOD = 1000000007;
int n,f;

int mu[MAX_], frac[MAX_], rfrac[MAX_];
bool vis[MAX_];
VR<int> prime, d[MAX_];

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) d=a, x=1, y=0;
  else gcd(b,a%b,d,y,x), y -= x*(a/b);
}

int rev(LL a){
  LL x,y,d;
  gcd(a,MOD,d,x,y);
  return (x%MOD+MOD)%MOD;
}

void init(){
  mu[1] = 1;
  frac[0] = rfrac[0] = 1;
  FORR(i,1,MAX){
    d[i].push_back(i);
    for(int j=i+i;j<=MAX;j+=i){
      mu[j] -= mu[i];
      d[j].push_back(i);
    }
    frac[i] = 1ll*frac[i-1]*i%MOD;
    rfrac[i] = rev(frac[i]);
  }
}

int g(int k){
  int tn = n/k - 1, tm = f - 1;
  return 1ll*frac[tn]*rfrac[tm]%MOD*rfrac[tn-tm]%MOD;
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&f);
    int ans = 0;
    for(int i : d[n]){
      if(n/i<f) break;
      ans = (ans + 1ll*mu[i]*g(i))%MOD;
    }
    ans = (ans+MOD)%MOD;
    printf("%d\n",ans);
  }

  return 0;
}
*/
