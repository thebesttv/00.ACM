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

const int MAX = 2e5 + 20;
int n,a,b,k,h[MAX],cnt[MAX];

int cal(int h){
  if(h>a+b){
    if(h%(a+b)==0) h=a+b;
    else h %= (a+b);
  }
  if(a >= h) return 0;
  return ceil(1.0*h/a) - 1;
}

int main(void){
  scanf("%d%d%d%d",&n,&a,&b,&k);
  FOR(i,0,n){
    scanf("%d",&h[i]);
    cnt[i] = cal(h[i]);
#ifdef DEBUG
    printf("  h: %d, cnt: %d\n",h[i],cnt[i]);
#endif
  }
  sort(cnt, cnt+n);
  int ans = 0;
  FOR(i,0,n){
    if(k >= cnt[i]){
      k-=cnt[i]; ++ans;
    }else break;
  }
  printf("%d\n",ans);

  return 0;
}
