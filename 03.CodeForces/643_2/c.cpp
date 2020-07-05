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

LL a,b,c,d;

LL f(LL x){
  LL l = max(c - x + 1, 1ll*b);
  LL len = c - l + 1, beg = min(x+l-1, 1ll*d) - c + 1;
#ifdef DEBUG
  printf("  x: %lld, l: %lld, len: %lld, beg: %lld\n",x,l,len,beg);
  printf("  %lld\n", x+c-1 <= d ? (beg*2+len-1)*len/2 : (beg + (d-c+1)) * (d-c+1-beg+1)/2 + (d-c+1) * (len - (d-c+1-beg+1)));
#endif
  if(len<=0 || beg<=0) return 0;

  if(x+c-1 <= d){
    return (beg*2+len-1)*len/2;
  }else{
    return (beg + (d-c+1)) * (d-c+1-beg+1)/2 + (d-c+1) * (len - (d-c+1-beg+1));
  }
}

void g(LL ans){
  LL sum = 0;
  FORR(x,a,b){
    int cnt = 0;
    FORR(y,b,c)
      FORR(z,c,d)
        if(x+y>z) ++sum, ++cnt;
    printf("  x: %d, cnt: %d\n",x,cnt);
  }
  if(sum != ans){
    printf("WRONG\n");
    exit(1);
  }
}

int main(void){
  cin >> a >> b >> c >> d;
  LL ans = 0;
  FORR(x,a,b) ans += f(x);
  printf("%lld\n",ans);
#ifdef DEBUG
  g(ans);
#endif

  return 0;
}
