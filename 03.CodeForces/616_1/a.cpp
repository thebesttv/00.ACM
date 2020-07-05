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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 3520;
int n,m,k,a[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&m,&k);
    FORR(i,1,n) scanf("%d",&a[i]);
    int ansMax = 0;
    if(k >= m-1){
      FORR(i,1,m) ansMax = max(ansMax, a[i]);
      FORR(i,n-m+1,n) ansMax = max(ansMax, a[i]);
    }else{
      FORR(l,0,k){
        int r = k - l;
        int tMin = 0x3f3f3f3f;
        // printf(" %d, %d\n", l+1,n-r);
        FOR(x,0,m-k){
          int rl = l+1+x, rr = l+1+x+n-m;
          int tMax = max(a[l+x+1], a[n+l-m+x+1]);
#ifdef DEBUG
          printf("  a[%d], a[%d], tMax: %d\n",l+x+1, n+l-m+x+1,tMax);
#endif
          tMin = min(tMin, tMax);
        }
        ansMax = max(ansMax,tMin);
      }
    }
    printf("%d\n",ansMax);
  }

  return 0;
}
