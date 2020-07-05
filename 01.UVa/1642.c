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

const int MAX = 100020;
typedef pair<LL,int> pii;
int n;

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    LL x; VR<pii> v;
    LL ans = 0;
    FORR(j,1,n){
      VR<pii> tv;
      scanf("%lld",&x);
      tv.emplace_back(x,j);
      for(auto &p : v){
        tv.emplace_back(gcd(x,p.FI),p.SE);
      }
      tv.emplace_back(0,0); // for comparison

      v.clear();
      FOR(i,0,tv.size()-1)
        if(tv[i].FI != tv[i+1].FI){
          v.push_back(tv[i]);
#ifdef DEBUG
          printf("  x: %lld, gcd: %lld, i: %d, j: %d, n: %d\n",x,tv[i].FI,tv[i].SE,j, j - tv[i].SE+1);
#endif
          //ans = max(ans, tv[i].FI * (j - tv[i].SE + 1));
          ans = max(ans, v.back().FI * (j - v.back().SE + 1));
        }
    }
    printf("%lld\n",ans);
  }

  return 0;
}
