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

const int MOD = 1000000007;
const int MAX = 1e6;
int n, p;
map<int,int> mp;

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    if(x&1) ans = ans*a%MOD;
    a = a*a%MOD;
    x>>=1;
  }
  return ans;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    mp.clear();
    scanf("%d%d",&n,&p);
    int k, sum = n, tMax = 0;
    while(n--){
      scanf("%d",&k); ++mp[k];
      tMax = max(tMax, k);
    }
    if(p==1){
      printf("%d\n",sum&1);
      continue;
    }
    LL ans = 0, left = 0, last = tMax;
    for(auto it = mp.rbegin(); it != mp.rend(); ++it){
      bool bad = 0;
      if(left){
        if((last - it->FI) * log(p) <= log(1.0 * sum / left)){
          FOR(k,it->FI,last){
            left *= p;
            if(left > sum) { bad = 1; break; }
          }
        } else bad = 1;
      }

      if(bad){
        while(it != mp.rend()){
          ans = (ans - it->SE * pow_mod(p, it->FI)%MOD + MOD) % MOD;
          ++it;
        }
        break;
      }

      last = it->FI;
      sum -= it->SE;

      if(left <= it->SE){
        it->SE -= left;
        ans = (ans - (left - (it->SE & 1)) * pow_mod(p, it->FI)%MOD + MOD) %MOD;
        left = it->SE & 1;
      }else{
        ans = (ans - it->SE * pow_mod(p, it->FI)%MOD + MOD)%MOD;
        left -= it->SE;
      }
    }
    printf("%lld\n",ans);
  }

  return 0;
}
