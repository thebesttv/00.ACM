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
int n; LL a[MAX], s[MAX];

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FORR(i,1,n){
      scanf("%lld",&a[i]);
      s[i]=a[i]-a[i-1];
    }
    if(n<3 || s[2]<0 || s[3]<0){
      printf("Case #%d: No\n",kase); continue;
    }
    s[n+1] = -a[n];

    LL sum = 0;
    FORR(i,1,n){
      // if(i+3 > n+1) break;
      if(s[i]>0) sum += s[i];
      if(i+3 <= n+1 && s[i+3]<0) sum += s[i+3];
      if(sum < 0) break;
    }
    printf("Case #%d: %s\n",kase, sum==0 ? "Yes" : "No");
  }

  return 0;
}
