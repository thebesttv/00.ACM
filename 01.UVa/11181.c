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

const int MAX=30;
int n,r; bool chosen[MAX]; double p[MAX];
double sum[MAX], tot;

void dfs(int cur, int cnt){
  if(n-cur+1 < r-cnt) return;

  if(cur == n+1){
    double t = 1;
    FORR(i,1,n)
      if(chosen[i]) t *= p[i];
      else t *= 1-p[i];
    tot += t;
    FORR(i,1,n) if(chosen[i])
      sum[i] += t;
    return;
  }
  if(cnt<r){
    chosen[cur]=1; dfs(cur+1,cnt+1);
  }
  chosen[cur]=0; dfs(cur+1,cnt);
}

int main(void){
  int kase = 0;
  while(scanf("%d%d",&n,&r)==2 && n){
    MST(sum,0); tot = 0;
    FORR(i,1,n) scanf("%lf",&p[i]);
    dfs(1,0);
#ifdef DEBUG
    printf("tot: %lf\n",tot);
    FORR(i,1,n) printf("  sum[%d]: %lf\n",i,sum[i]);
#endif
    printf("Case %d:\n",++kase);
    FORR(i,1,n) printf("%.6lf\n", sum[i] / tot);
  }

  return 0;
}
