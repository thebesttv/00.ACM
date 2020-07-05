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

const int MAX = 1020;
int n, s, k;
map<int,int> mp;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    mp.clear();
    scanf("%d%d%d",&n,&s,&k);
    int x;
    FOR(i,0,k) scanf("%d",&x), mp[x] = 1;
    int p = s, cnt = 0, ans = 0x3f3f3f3f;
    while(p>=1 && mp[p]){
      --p; ++cnt;
    }
    if(p>=1) ans = cnt;

    p = s, cnt = 0;
    while(p<=n && mp[p]){
      ++p; ++cnt;
    }
    if(p<=n) ans = min(ans, cnt);
    printf("%d\n",ans);
  }

  return 0;
}
