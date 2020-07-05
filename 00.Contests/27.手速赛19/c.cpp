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
int n,v[MAX],t[MAX];
LL s[MAX],full[MAX],part[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&v[i]);
  FORR(i,1,n) scanf("%d",&t[i]), s[i] = t[i] + s[i-1];

  FORR(i,1,n)
    if(v[i]<t[i]){
      part[i] += v[i];
    }else{
      int r = lower_bound(s+1,s+1+n,v[i]+s[i-1]) - s;
      r = min(r, n);
      if(s[r]-s[i-1] > v[i]) --r;
      LL d = s[r] - s[i-1]; v[i] -= d;
#ifdef DEBUG
      printf("  for v: %d, l: %d, r: %d, left: %d\n",int(v[i]+d),i,r,int(v[i]));
#endif
      ++full[i], --full[r+1];
      part[r+1] += v[i];
    }

  LL d = 0;
  FORR(i,1,n){
    d += full[i];
    printf("%lld ", part[i] + d*t[i]);
  }
  putchar('\n');

  return 0;
}
