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

const int MAX = 1e4 + 20;
const int MOD = 1000000007;
int n,k;
LL f[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    MST(f,0);
    LL ans = 0;
    f[0][n] = 1;
    /*
    FOR(i,0,n){
      ans = (ans + f[i][0])%MOD;
      FORR(j,1,n) if(f[i][j]){
        int d = min(j,k);
        FORR(h,1,d)
          f[i+1][j-h] = (f[i+1][j-h] + f[i][j])%MOD;
      }
    }
    */
    FORR(i,1,n){
      FORR(j,0,n) FORR(h,1,k){
        f[i][j] += f[i-1][j+h];
      }
      ans += f[i][0];
    }
    ans *= 2;
    printf("%lld\n",ans);
  }

  return 0;
}
