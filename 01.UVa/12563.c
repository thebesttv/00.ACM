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
typedef long long LL;
typedef long long unsigned LLU;

const int MAXN=50+2, MAXT=180*MAXN+678;
int n,t,a[MAXN],s[MAXN];
int f[MAXT];  // f[i][j]: 1:i 首中，时间恰好为j，最多曲数
// f[i][j] = max( f[i-1][j], f[i-1][j-a[i]]+1 )

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    s[0]=0; MST(f,-0x3f);
    scanf("%d%d",&n,&t);
    FORR(i,1,n) scanf("%d",&a[i]), s[i]=s[i-1]+a[i];
    f[0]=0;
    FORR(i,1,n) ROR(j,s[i],a[i])
      f[j] = max(f[j], f[j-a[i]]+1);

    int nMax=0, tMax=0;
    ROR(j,t-1,0) if(f[j]>0 && f[j]>nMax){ // 遍历所有，确保 n 取最大
      nMax=f[j], tMax=j;
    }
    printf("Case %d: %d %d\n",kase,nMax+1, tMax+678);
  }

  return 0;
}
