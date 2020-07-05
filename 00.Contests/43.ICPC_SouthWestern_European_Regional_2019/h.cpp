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

LL n;

int main(void){
  scanf("%lld",&n);
  int cnt = 0, last = -1, c = 0;
  LL s = 0x600DCAFEll;
  while(n--){
    if((s&1)==0) ++cnt;
#ifdef DEBUG
    if(last != ((s>>20)&1)){
      if(c) printf("  %d\n",c);
      last = ((s>>20)&1); c = 0;
    }
    ++c;
#endif
    s = (s + (s>>20) + 12345) & ((1ll<<40)-1);
  }
  printf("%d\n",cnt);

  return 0;
}
