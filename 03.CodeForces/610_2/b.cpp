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
int n, k, a[MAX];
LL p, s[MAX], f[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%lld%d",&n,&p,&k);
    FORR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    //FORR(i,1,n) s[i] = s[i-1] + a[i];
    int ans = 0;
    FORR(i,1,n){
      f[i] = a[i] + f[i-1];
      if(i>=k) f[i] = min(f[i], a[i] + f[i-k]);
      if(f[i]<=p) ans = i;
    }
    printf("%d\n",ans);
  }

  return 0;
}
