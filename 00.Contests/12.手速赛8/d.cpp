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
typedef pair<int,LL> pii;

const int MAX = 1e5 + 20;
int n,q; LL u; char s[MAX];

pii get(LL u){
  FOR(i,0,n){
    LL r = 1ll<<(n-i-1);
    if(u >= (1ll<<i) && (u - (1ll<<i))%(1ll<<(i+1))==0 ){
      LL k = ( u - (1ll<<i) ) / (1ll<<(i+1));
      if(k >= r) continue;

      if( (1ll<<i) + k*(1ll<<(i+1)) == u)
        return {i, k};
    }
  }
  return {-1,-1};
}

LL getNo(int i, LL k){
  return (1ll<<i) + k*(1ll<<(i+1));
}

int main(void){
  LL node; scanf("%lld%d",&node,&q);
  ++node;
  while((1ll<<n) != node) ++n;
#ifdef DEBUG
  printf("  n: %d\n",n);
#endif

  while(q--){
    scanf("%lld%s",&u,s);
    int i; LL k; pii t = get(u);
    i = t.FI, k = t.SE;
#ifdef DEBUG
    printf("  u %lld, i: %d, k: %lld\n",u,i,k);
#endif
    int len = strlen(s);
    FOR(j,0,len){
      if(s[j]=='U'){
        if(i==n-1) continue;
        ++i, k/=2;
      }else if(s[j]=='L'){
        if(i==0) continue;
        k = k*2; --i;
      }else{  // R
        if(i==0) continue;
        k = k*2+1; --i;
      }
#ifdef DEBUG
      printf("  %c: i %d, k %lld\n",s[j],i,k);
#endif
    }
    LL ans = getNo(i,k);
    printf("%lld\n",ans);
  }

  return 0;
}
