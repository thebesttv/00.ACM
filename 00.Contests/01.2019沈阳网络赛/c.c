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

const int MAXN=1020, MAXM=10020;
const int MAX=MAXM<<1;

int n,m;
int p[MAXN],c[MAXN];
int f[MAX*2];

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    MST(f,0x3f); f[0]=0;

    FOR(i,0,n) scanf("%d%d",&p[i],&c[i]);

    FOR(S,0,MAX) FOR(i,0,n){
      f[S+c[i]] = min( f[S+c[i]], f[S]+p[i]);
    }

    int pMin=0x3f3f3f3f, wMax=0;
    FOR(i,m,MAX) if(f[i]<=pMin)
      pMin=f[i], wMax=i;
    printf("%d %d\n",pMin,wMax);
  }

  return 0;
}
