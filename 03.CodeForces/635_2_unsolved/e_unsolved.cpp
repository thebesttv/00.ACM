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

const int MAX = 3020;
const LL MOD = 998244353;
int n,m; char s[MAX], t[MAX];
LL frac[MAX], rfrac[MAX];
LL f[MAX][MAX];

LL pow_mod(LL x, LL a){ // x^a
  LL ans = 1;
  while(a){
    if(a&1) ans = ans * x % MOD;
    x = x * x % MOD;
    a >>= 1;
  }
  return ans;
}

LL rev(LL x){
  return pow_mod(x, MOD-2);
}

LL C(int n, int m){
  return frac[n] * rfrac[m] % MOD * rfrac[n-m] % MOD;
}

int main(void){
  frac[0] = frac[1] = rfrac[0] = rfrac[1] = 1;
  FORR(i,2,3000){
    frac[i] = frac[i-1] * i % MOD;
    rfrac[i] = rev(frac[i]);
  }

  scanf("%s%s",s+1,t+1);
  n = strlen(s+1);
  m = strlen(t+1);

  LL ans = 0;
  FORR(l,0,n){
    if(l>m){
      MST(f,0);
      ROR(i,n,1)//
    }else{
    }
  }

  return 0;
}
