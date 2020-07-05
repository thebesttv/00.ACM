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

const int MAX = 1e5 + 20;
const int MOD = 1000000007;
int n,k;
LL *f, *g, s[MAX];

int main(void){
  int T; scanf("%d",&T);
  f = new LL [MAX];
  g = new LL [MAX];

  while(T--){
    scanf("%d%d",&n,&k);
    LL ans = 0; f[n] = 1;
    FORR(i,1,n){
      FORR(j,1,n) s[j] = (s[j-1] + f[j])%MOD;
      FORR(j,0,n){
        int r = min(n,j+k);
        g[j] = (s[r] - s[j]+MOD)%MOD;
      }
#ifdef DEBUG
      //printf("f[%d]:",n); FORR(i,0,n) printf(" %lld",f[i]); putchar('\n');
      //printf("s[%d]:",n); FORR(i,0,n) printf(" %lld",s[i]); putchar('\n');
      printf("g[%d]:",n); FORR(i,0,n) printf(" %lld",g[i]); putchar('\n');
#endif
      ans = (ans + g[0])%MOD;
      swap(f,g);
    }
    ans = ans*2ll%MOD;
    printf("%lld\n",ans);
  }

  return 0;
}
