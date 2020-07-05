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

const int MAX = 1e5+20;
int n, b[MAX]; LL a[MAX];

int main(void){
  scanf("%d",&n); LL sum = 0, ans = 0;
  FORR(i,1,n) scanf("%lld",&a[i]), sum += a[i];
  a[0] = a[n]; a[n+1] = a[1];
  FORR(i,1,n) ans += a[i]*a[i+1];

  FORR(i,1,n) scanf("%d",&b[i]);

  FORR(i,1,n) if(b[i]){
    LL t = sum - a[i-1] - a[i] - a[i+1];
    if(b[i-1]) t += a[i-1];
    if(i==n && b[1]) t += a[1];

    sum -= a[i];
    ans += max(t,0ll) * a[i];
  }

  printf("%lld\n",ans);

  return 0;
}
