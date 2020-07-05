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

const int MAX = 1020;
const LL MOD = 1e9 + 7;
int n,m;
LL f[11][MAX], g[11][MAX];

int main(void){
  scanf("%d%d",&n,&m);

  FORR(j,1,n) f[1][j] = g[1][j] = 1;
  FORR(i,2,m) FORR(j,1,n){
    f[i][j] = (f[i][j-1] + f[i-1][j]) % MOD;
  }
  FORR(i,2,m) ROR(j,n,1){
    g[i][j] = (g[i][j+1] + g[i-1][j]) % MOD;
  }

  LL ans = 0;
  FORR(a,1,n) FORR(b,a,n)
    ans = (ans + f[m][a] * g[m][b] % MOD) % MOD;
  printf("%lld\n",ans);

  return 0;
}
