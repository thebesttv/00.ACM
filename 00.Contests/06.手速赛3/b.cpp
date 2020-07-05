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

const int MAX = 2e5 + 20;
const LL MOD = 998244353;
int n; char s[MAX];
int l, r;

int main(void){
  scanf("%d%s",&n,s+1);
  l = 1, r = n;
  while(l+1 <= n && s[l+1] == s[1]) ++l;
  while(r-1 >= 1 && s[r-1] == s[n]) --r;
#ifdef DEBUG
  printf("  %d %d\n",l,r);
#endif
  LL ans = 0;
  if(s[1] == s[n]){
    ans = ( l + 1ll ) * (n - r + 2ll) % MOD;
  }else{
    ans = ( l + n - r + 2) % MOD;
  }
  printf("%lld\n",ans);

  return 0;
}
