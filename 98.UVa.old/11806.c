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

const int MAX = 400;
const LL MOD = 1000007;
int n,m,k; LL C[MAX+20][MAX+20];

int main(void){
  C[1][0] = C[1][1] = 1;
  FORR(i,2,MAX){
    C[i][0] = 1;
    FORR(j,1,i)
      C[i][j] = ( C[i-1][j] + C[i-1][j-1] )%MOD;
  }

  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d%d",&n,&m,&k);
    if(k<2 || k>m*n){
      printf("Case %d: 0\n",kase);
      continue;
    }

    LL ans = 0;
    FOR(i,0,16){
      int cnt = 0, r = n, c = m;
      if(i&1) r--, cnt++;
      if(i&2) r--, cnt++;
      if(i&4) c--, cnt++;
      if(i&8) c--, cnt++;

      if(cnt&1) ans = (ans - C[r*c][k] + MOD)%MOD;
      else      ans = (ans + C[r*c][k])%MOD;
    }

    printf("Case %d: %lld\n",kase,ans);
  }
  return 0;
}
