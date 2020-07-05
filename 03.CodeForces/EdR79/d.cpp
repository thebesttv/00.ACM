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

const int MAX = 1e6 + 20;
const LL MOD = 998244353;

int n; VR<int> v[MAX];
int cnt[MAX];

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) d = a, x = 1, y = 0;
  else gcd(b, a%b, d, y, x), y -= x * (a/b);
}

LL rev(LL a){
  LL d,x,y;
  gcd(a,MOD,d,x,y);
  return (x+MOD)%MOD;
}

int main(void){
  scanf("%d",&n);
  int k,x;
  FOR(i,0,n){
    scanf("%d",&k);
    while(k--){
      scanf("%d",&x);
      v[i].push_back(x);
      ++cnt[x];
    }
  }

  LL ans = 0, revn = rev(n);
  FOR(i,0,n){
    int sz = v[i].size();
    LL revk = rev(sz);
    FOR(j,0,sz){
      ans = (ans + revn * revk % MOD * cnt[v[i][j]] % MOD * revn % MOD) % MOD;
    }
  }
  printf("%lld\n",ans);

  return 0;
}
