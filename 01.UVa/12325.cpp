// Tag: 枚举 优化 i
// 如果单纯枚举物品1或物品2的个数，则复杂度为 O(V/S)
// 1. 若 S >= sqrt(V)，复杂度为 O(sqrt(V))
// 2. 若 S < sqrt(V)，考虑 s2 个物品1，s1 个物品2，两者体积皆为 s1*s2，前者价值为 s2*v1，后者为 s1*v2
// 若 s2*v1 >= s1*v2，则任意 s1 个物品2都可以换成 s1 个物品1而价值不变低，因此物品2只有 [0:s1) 个
// 否则，则物品1只有 [0:s2) 个
// 此时复杂度为 O(S)，亦为 O(sqrt(V))
// 总复杂度为 O(sqrt(V))
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

LL v,s1,v1,s2,v2;
const int THR = sqrt(INT_MAX);

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%lld%lld%lld%lld%lld",&v,&s1,&v1,&s2,&v2);
    LL ans = 0;
    if(v/s1 <= THR){
      FORR(i,0,v/s1) ans = max(ans, i*v1 + (v-i*s1)/s2*v2); // 1
    }else if(v/s2 <= THR){
      FORR(i,0,v/s2) ans = max(ans, i*v2 + (v-i*s2)/s1*v1); // 2
    }else{
      if(s2 * v1 >= s1 * v2)
        FOR(i,0,s1) ans = max(ans, i*v2 + (v-i*s2)/s1*v1);  // 2
      else
        FOR(i,0,s2) ans = max(ans, i*v1 + (v-i*s1)/s2*v2);  // 1
    }
    printf("Case #%d: %lld\n",kase,ans);
  }

  return 0;
}
