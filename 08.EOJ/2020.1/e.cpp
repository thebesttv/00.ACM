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

LL n,k;

LL cnt(LL x){
  LL ans = 0, p;
  if(x&1){  // odd
    p = 1;
  }else{
    p = 2;
  }

  while(x <= n){
    LL d = min(p-1, n-x) + 1;
    if(d < 0) break;
    ans += d;
    p *= 2; x *= 2;
  }
  return ans;
}

int main(void){
  //scanf("%d",&n);
  //FORR(i,1,n) printf("  cnt[%d]: %lld\n",i,cnt(i));

  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&n,&k);
    if(n==1){
      printf("%d\n",1);
    }else if(n==2){
      printf("%d\n", k==1 ? 2 : 1);
    }else{

      LL ans = k<n ? 2 : 1;
      // odd  2n-1
      LL l = 1, r = ( (n&1) ? (n+1)/2 : n/2) + 1;
      bool done = 0;
      while(l<r){
        LL m = (l+r+1)/2;
        if(cnt(2*m-1) >= k){
          l = m; done = 1;
        }else r = m-1;
      }
      if(done) ans = max(ans, 2*l - 1);

      // even 2*n
      l = 1, r = n/2 + 1;
      done = 0;
      while(l<r){
        LL m = (l+r+1)/2;
        if(cnt(m*2) >= k){
          l = m; done = 1;
        }else r = m-1;
      }
      if(done) ans = max(ans, 2*l);

      printf("%lld\n",ans);
    }
  }
  return 0;
}

  /*
     int cnt[1000];
     VR<int> v[1000];

     int main(void){
     int n; scanf("%d",&n);
     v[1].push_back(1);
     ++cnt[1];

     FORR(i,2,n){
     int t = i;
     do{
     v[i].push_back(t);
     ++cnt[t];
     if(t&1) --t;
     else t /= 2;
     }while(t != 1);
     v[i].push_back(1);
     ++cnt[1];
     reverse(ALL(v[i]));

// FORR(j,1,i) printf("%3d ", cnt[j]);
}
FORR(i,1,n){
printf("cnt[%d]: %d\n",i,cnt[i]);
}
return 0;
}
*/
