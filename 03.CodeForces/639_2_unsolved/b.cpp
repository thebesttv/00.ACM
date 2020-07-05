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

const int MAX = 100000, MAX_ = MAX + 20;
LL f[MAX_];

int main(void){
  f[1] = 2;
  FORR(i,2,MAX){
    f[i] = f[i-1] + 2 * i + i-1;
  }
#ifdef DEBUG
  FORR(i,1,10) printf("  f[%d]: %lld\n",i,f[i]);
  printf("f[%d]: %lld\n",MAX,f[MAX]);
#endif

  int T; scanf("%d",&T);
  while(T--){
    LL n; scanf("%lld",&n);
    int cnt = 0;
    while(n >= 2){
      int idx = lower_bound(f, f+MAX+1,n) - f;
      if(f[idx] > n) --idx;
      n -= f[idx]; ++cnt;
    }
    printf("%d\n",cnt);
  }

  return 0;
}
