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

const int MAX = 1e5 + 20;
int a,b,c,v1[MAX],v2[MAX],v3[MAX];

LL pow2(LL x) { return x * x; }
LL f(LL x, LL y, LL z) { return pow2(x-y) + pow2(x-z) + pow2(y-z); }
LL getMin(LL x, LL y) {
  if(x==-1) return y;
  return min(x,y);
}

LL findMin(int x, int *v1, int a, int *v2, int b){
  LL tMin = -1;
  int j = lower_bound(v1,v1+a,x) - v1;

  if(j < a) {
    int k = lower_bound(v2,v2+b,(x+v1[j])/2) - v2;
#ifdef DEBUG
      printf("  for x = %d, j: %d, k: %d\n",x,j,k);
#endif
    if(k < b){
      //if(tMin==-1) tMin = f(x,v1[j],v2[k]);
      //else tMin = min(tMin, f(x,v1[j],v2[k]));
      tMin = getMin(tMin, f(x,v1[j],v2[k]));
    }
    if(k > 0){
      tMin = getMin(tMin, f(x,v1[j],v2[k-1]));
    }
  }

  if(j > 0){
    int k = lower_bound(v2,v2+b,(x+v1[j-1])/2) - v2;
#ifdef DEBUG
      printf("  for x = %d, j: %d, k: %d\n",x,j-1,k);
#endif
    if(k < b){
      tMin = getMin(tMin, f(x,v1[j-1],v2[k]));
    }
    if(k > 0){
      tMin = getMin(tMin, f(x,v1[j-1],v2[k-1]));
    }
  }
  return tMin;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&a,&b,&c);
    FOR(i,0,a) scanf("%d",&v1[i]);
    FOR(i,0,b) scanf("%d",&v2[i]);
    FOR(i,0,c) scanf("%d",&v3[i]);
    sort(v1,v1+a), sort(v2,v2+b), sort(v3,v3+c);

    LL ans = f(v1[0], v2[0], v3[0]);
    FOR(i,0,a){
      ans = min(ans, findMin(v1[i], v2, b, v3, c));
      ans = min(ans, findMin(v1[i], v3, c, v2, b));
    }
    printf("%lld\n",ans);
  }

  return 0;
}
