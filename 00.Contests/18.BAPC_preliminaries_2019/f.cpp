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
  cin >> n;
  LL k=-1, d = -1;
  int r = sqrt(n+0.5);
  if(1ll*r*r == n){
    k = 0, d = r;
  }else FORR(i,1,r) if(n%i==0){
    LL l = i, r = n/i;
    if(r>l && ((r-l)&1)==0){
      d = l, k = (r-l)/2;
      break;
    }
  }

  if(k!=-1) printf("%lld %lld\n",k+d, k);
  else printf("impossible\n");

  return 0;
}
