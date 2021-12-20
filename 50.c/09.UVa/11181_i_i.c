/*
  解题报告：
    使用条件概率。
    令 E 为r个人买的概率，Ei 为第i个人买的概率，则 ansi = P(Ei|E)
    又因为 P(Ei|E) = P(EiE) / P(E)，只需求得 P(E) 和每个 P(Ei) 即可。
    而为了求出 P(E)，要使用dfs。
    在dfs时，用rec[i]表示i是否买，共 C(n,r) 次计算得出 P(E)，每次都要 ans += mul{ rec[i] ? p[i] : 1-p[i] }。
    而每个 P(Ei) 其实就是 rec[i]=1 时的所有组合，因此可以在大的dfs中也顺便计算。
    那么只需一遍dfs即可。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=30;
int n,r;
double p[MAX],a[MAX],tot;

void dfs(int cur, int step, double t, int S){
  if(cur==n){
    if(step!=r) return;
    tot+=t;
    FOR(i,0,n) if((S>>i)&1) a[i]+=t;
    return;
  }
  if(step<r) dfs(cur+1,step+1,t*p[cur],S|(1<<cur));
  dfs(cur+1,step,t*(1.0-p[cur]),S);
}

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&r)==2 && n){
    MST(a,0); tot=0;
    FOR(i,0,n) scanf("%lf",&p[i]);
    dfs(0,0,1,0);
    printf("Case %d:\n",++kase);
    FOR(i,0,n) printf("%.6lf\n",a[i]/tot);
  }

  return 0;
}

/*
const int MAX=30;
int n,r;
bool rec[MAX];
double p[MAX],a[MAX],tot;

void dfs(int cur, int step){
#ifdef DEBUG
  printf("  dfs(%d,%d)\n",cur,step);
#endif
  if(cur==n){
    if(step!=r) return;
    double sum=1;
    FOR(i,0,n) sum *= rec[i] ? p[i] : (1-p[i]);
    FOR(i,0,n) if(rec[i]) a[i]+=sum;
    tot+=sum;
    return;
  }
  if(step<r) {rec[cur]=1; dfs(cur+1,step+1);}
  rec[cur]=0; dfs(cur+1,step);
}

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&r)==2 && n){
    MST(a,0); tot=0;
    FOR(i,0,n) scanf("%lf",&p[i]);
    dfs(0,0);
    printf("Case %d:\n",++kase);
    FOR(i,0,n) printf("%.6lf\n",a[i]/tot);
  }

  return 0;
}
*/
