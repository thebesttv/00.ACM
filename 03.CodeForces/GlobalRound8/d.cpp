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
int n, a[MAX], cnt[MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d",&a[i]);
    FOR(j,0,20) if(a[i]&(1<<j))
      ++cnt[j];
  }

  LL ans = 0;
  FOR(i,0,n){
    LL t = 0;
    FOR(j,0,20) if(cnt[j]){
      --cnt[j]; t |= (1ll<<j);
    }
    ans += t * t;
  }
  printf("%lld\n",ans);

  return 0;
}
