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
int n,k,a[MAX],b[MAX],w[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,k) scanf("%d",&w[i]);
    sort(a,a+n,greater<int>());
    sort(w,w+k);
    LL ans = 0; int idx = 0;
    FOR(i,0,k){
      b[i] = a[idx++]; w[i]--;
      ans += b[i];
    }
    FOR(i,0,k) if(w[i]){
      while(w[i]--) b[i] = a[idx++];
      ans += b[i];
    } else ans += b[i];
    printf("%lld\n",ans);
  }

  return 0;
}
