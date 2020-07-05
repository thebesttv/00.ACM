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

LL k;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld",&k); VR<LL> v;
    for(int i=0;i<100 && (1ll<<i)<=k;++i){
      v.push_back(1ll<<i); k -= 1ll<<i;
    }
    if(k) v.push_back(k);
    sort(ALL(v));
    printf("%d\n",v.size());
    for(LL x : v) printf("%lld ",x);
    putchar('\n');
  }

  return 0;
}
