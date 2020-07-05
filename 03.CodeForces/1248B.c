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

const int MAX = 1e5 + 20;
int n, a[MAX]; LL s[MAX];

LL f(LL x){
  return x * x;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n);
  s[0] = a[0];
  FOR(i,1,n) s[i] = a[i] + s[i-1];

  LL ans = 0;
  if(n&1){
    ans = f(s[n/2-1]) + f(s[n-1] - s[n/2-1]);
    ans = max(ans, f(s[n/2]) + f(s[n-1]-s[n/2]));
  }else{
    ans = f(s[n/2-1]) + f(s[n-1] - s[n/2-1]);
  }
  printf("%lld\n",ans);

  return 0;
}
