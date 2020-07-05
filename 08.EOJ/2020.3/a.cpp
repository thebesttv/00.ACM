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

const int MAX = 1e6 + 20;
int k; LL n,m;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%lld%lld",&k,&n,&m);
    LL t1,t2,t3,t4;
    t1=t2=t3=t4=n+m;
    LL x,y;
    FOR(i,0,k){
      scanf("%lld%lld",&x,&y);
      t1 = min(t1, x+y);
      t2 = min(t2, n-x+y);
      t3 = min(t3, x+m-y);
      t4 = min(t4, n-x+m-y);
    }
    printf("%lld\n",max(t1,max(t2,max(t3,t4))));
  }

  return 0;
}
