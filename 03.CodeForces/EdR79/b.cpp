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

const int MAX = 1e5 + 20;
int n; LL s, a[MAX], sum[MAX];

int count(LL s){
  int p = lower_bound(sum+1,sum+n+1,s) - sum;
  if(sum[p] > s) --p;
  return p;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%lld",&n,&s);
    int ansMax = 0, r = 0;
    FORR(i,1,n){
      scanf("%lld",&a[i]);
      sum[i] = sum[i-1] + a[i];
      if(sum[i]<=s) ansMax = i;
    }
    if(sum[n] <= s){
      printf("0\n"); continue;
    }

    FORR(i,1,n){
      if(sum[i-1]>=s) break;
      int cnt = count(s+a[i]);
#ifdef DEBUG
      printf("  %d, s+sum[i]: %lld, %d\n",i,s+sum[i],cnt);
#endif
      if(cnt>ansMax){
        ansMax = cnt; r = i;
      }
    }

    if(ansMax) printf("%d\n",r);
    else printf("0\n");
  }

  return 0;
}
