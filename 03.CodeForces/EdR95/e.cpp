// Tag: 概率期望 ii
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

const int MAX = 2e5 + 20;
const LL MOD = 998244353;
int n,m,d[MAX]; LL s[MAX];

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans * a %MOD : ans;
    a = a*a%MOD; x>>=1;
  }
  return ans;
}
LL rev(LL x) { return pow_mod(x, MOD-2); }

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&d[i]);
  sort(d+1,d+1+n);
  FORR(i,1,n) s[i] = (s[i-1] + d[i])%MOD;

  while(m--){
    int a,b; scanf("%d%d",&a,&b);
    int idx = lower_bound(d+1,d+1+n,b) - d;
    int big = n - idx + 1;
    if(big < a) { printf("0\n"); continue; }
    LL ans = ((1 - a * rev(big)%MOD + MOD)%MOD * (s[n] - s[idx-1] + MOD)%MOD
      + (1 - a * rev(big+1)%MOD + MOD)%MOD * s[idx-1] %MOD)%MOD;
    printf("%lld\n",ans);
  }

  return 0;
}
