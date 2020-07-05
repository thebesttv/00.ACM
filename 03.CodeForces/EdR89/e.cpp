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
const LL MOD = 998244353;
int n,m,a[MAX],b[MAX],f[MAX],g[MAX];
map<int,VR<int>> pos;

LL cal(){
  LL ans = 1;
  if(!pos.count(b[1])) return 0;
  int tMin = b[1], r = pos[b[1]].back();
  FORR(i,1,r) tMin = min(tMin, a[i]);
  if(tMin < b[1]) return 0;

  if(!pos.count(b[m])) return 0;
  tMin = b[m], r = pos[b[m]].back();
  FORR(i,r,n) tMin = min(tMin, a[i]);
  if(tMin < b[m]) return 0;

  FORR(i,2,m){
    if(!pos.count(b[i])) return 0;
    int l = pos[b[i-1]].back(),
        r = pos[b[i]].back();
    if(l > r) return 0;

    f[l] = a[l];
    FORR(j,l+1,r) f[j] = min(f[j-1], a[j]);
    g[r] = a[r];
    ROR(j,r-1,l) g[j] = min(g[j+1], a[j]);

    int cur = 0;
    FOR(j,l,r) if(f[j]>=b[i-1] && g[j+1]>=b[i])
      ++cur;
    ans = ans * cur % MOD;
  }
  return ans;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]), pos[a[i]].push_back(i);
  FORR(i,1,m) scanf("%d",&b[i]);
  printf("%lld\n",cal());

  return 0;
}
