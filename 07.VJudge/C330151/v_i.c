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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=100020;
int n,s;
struct Ind{
  LL t,d;
  bool operator < (const Ind &b) const {
    return d*b.t > b.d*t;
  }
}ind[MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%lld%lld",&ind[i].t,&ind[i].d);
    s+=ind[i].d;
  }
  sort(ind,ind+n);

  LL ans=0;
  FOR(i,0,n){
    s-=ind[i].d;
    ans += 2ll * ind[i].t * s;
  }
  printf("%lld\n",ans);

  return 0;
}
