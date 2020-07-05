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
int n, m; LL cnt[MAX];
VR<LL> G[MAX];

LL cal(VR<LL> &v, int j){
  FOR(i,0,n) cnt[i] = 0;

  FOR(i,0,n){
    LL i2 = (v[i] - j - 1) / m;
    if(i2<0 || i2>=n || v[i] - j - 1 != m*i2) continue;
    LL d = ( (i - i2)%n + n) % n;
    ++cnt[d];
  }

  LL tMin = LLONG_MAX;
  FOR(i,0,n) tMin = min(tMin, i + n - cnt[i]);
  return tMin;
}

int main(void){
  scanf("%d%d",&n,&m);
  int x;
  FOR(i,0,n) FOR(j,0,m){
    scanf("%d",&x);
    G[j].push_back(x);
  }

  LL ans = 0;
  FOR(j,0,m){
    ans += cal(G[j], j);
  }
  printf("%lld\n",ans);

  return 0;
}
