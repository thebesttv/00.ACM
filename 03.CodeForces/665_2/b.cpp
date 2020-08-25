// Tag: 贪心
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

VR<pii> v{{2,1},{0,2},{2,2},{0,0},{1,1},{2,0},{0,1},{1,0},{1,2}};
LL a[3],b[3];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,3) scanf("%lld",&a[i]);
    FOR(i,0,3) scanf("%lld",&b[i]);
    LL ans = 0;
    for(auto p : v){
      LL d = min(a[p.FI],b[p.SE]);
      a[p.FI] -= d, b[p.SE] -= d;
      if(p.FI > p.SE) ans += d * p.FI * p.SE;
      else if(p.FI < p.SE) ans -= d * p.FI * p.SE;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
