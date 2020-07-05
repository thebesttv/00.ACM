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

LL u, v, cnt[100];

void bad(){
  printf("-1\n"); exit(0);
}

int main(void){
  scanf("%lld%lld",&u,&v);

  if((u&1)!=(v&1)) bad();
  if(u==0) cnt[0] = v;
  else{
    LL k = v / u;
    if((k&1)==0) --k;
    if(k<=0) bad();

    FOR(i,0,60) if(u&(1ll<<i))
      cnt[i] += k;
    v -= k * u;
    // cnt[2] += v/2;
    cnt[0] += v;
  }
#ifdef DEBUG
  FOR(i,0,60) if(cnt[i])
    printf("  cnt[%d]: %lld\n",i,cnt[i]);
#endif

  FOR(i,0,60){
    LL &a = cnt[i];
    //if(u&(1ll<<i)){ // odd
    //  if(a==1) continue;
    //}else{  // even
      RORR(j,59,i){ // d be even
        LL d = a * (1ll<<i) / (1ll<<j);
        if(d&1) --d;
        if(d<=0) continue;
        cnt[j] += d;
        a = ( a * (1ll<<i) - d * (1ll<<j) ) / (1ll<<i);
      }
    //}
  }
#ifdef DEBUG
  FOR(i,0,60) if(cnt[i])
    printf("  cnt[%d]: %lld\n",i,cnt[i]);
#endif

  VR<LL> ans;
  while(true){
    LL s = 0;
    FOR(i,0,62) if(cnt[i]){
      --cnt[i]; s |= (1ll<<i);
    }
    if(!s) break;
    ans.push_back(s);
  }

  printf("%d\n",ans.size());
  if(ans.size())
    for(auto x : ans) printf("%lld ",x); putchar('\n');

  return 0;
}
