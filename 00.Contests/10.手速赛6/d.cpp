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

const int MAX = 200020;
int n; LL a, b;
LL x[MAX], vx[MAX], vy[MAX];
map<LL,int> mp;
map<int,int> mpx,mpy;
map<pii,int> mpxy;

inline LL f(int n){
  return (n-1ll)*n/2;
}

int main(void){
  scanf("%d%lld%lld",&n,&a,&b);
  FOR(i,0,n){
    scanf("%lld%lld%lld",&x[i],&vx[i],&vy[i]);
    // if(vx[i]==0 && vy[i]==0) continue;

    ++mp[ a*vx[i] - vy[i] ];
    ++mpx[vx[i]]; ++mpy[vy[i]];
    ++mpxy[{vx[i],vy[i]}];
  }

  LL ans = 0;
  for(auto p : mp){
    ans += f(p.SE);
  }
  /*
  for(auto p : mpx){
    ans -= f(p.SE);
  }
  for(auto p : mpy){
    ans -= f(p.SE);
  }
  */
  for(auto p : mpxy){
    ans -= f(p.SE);
  }
  printf("%lld\n",ans*2);

  return 0;
}
