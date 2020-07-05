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

const int MAX = 2e5 + 20;
const LL MOD = 1e9 + 7;
int n; LL a[MAX], b[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) scanf("%lld",&a[i]);
    FORR(i,1,n){
      scanf("%lld",&b[i]);
      b[i] = b[i] * i * (n-i+1);
    }
    sort(a+1,a+1+n,greater<LL>());
    sort(b+1,b+1+n);
    LL ans = 0;
    FORR(i,1,n){
      b[i] %= MOD;
      ans = (ans + a[i]*b[i]%MOD)%MOD;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
