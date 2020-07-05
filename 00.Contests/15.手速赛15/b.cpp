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

const int MAX = 1e5 + 20;
int n,k,m,l,r,a[MAX];

int main(void){
  scanf("%d%d%d",&n,&k,&l); m = n*k;
  FOR(i,0,m) scanf("%d",&a[i]);
  sort(a,a+m);

  int cnt = 0; r = a[0]+l;
  FOR(i,0,m)
    if(a[i]<=r) ++cnt;
    else break;
#ifdef DEBUG
  printf("  cnt: %d\n",cnt);
#endif

  if(cnt<n){
    printf("0\n"); return 0;
  }
  LL ans = 0;
  if(k==1){
    ans = a[0];
    FOR(i,1,n) ans += a[cnt-i];
  }else{
    /*
    int x = (cnt-n)/(k-1);
    int idx = 0;
    FOR(i,0,x) ans+=a[idx],idx+=k;
    FOR(i,0,(n-x)) ans += a[cnt-i-1];
    int i = 0;
    */

    int idx = 0;
    FOR(i,0,n){
      int d = min(k,cnt-idx - (n-i-1));
      ans += a[idx];
      idx += d;
#ifdef DEBUG
      printf("  %d\n",d);
#endif
    }
  }
  printf("%lld\n",ans);

  return 0;
}
