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

const int MAXN=1020, MAXM=120;
int n,m,f[MAXN],g[MAXM];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&f[i]);

  int ans=0;
  FORR(l,1,n){
    FORR(r,l,n){
      g[f[r]]++;
      int cntMax=0, rec=0;
      FORR(k,1,m) if(g[k]>cntMax){
        cntMax=g[k]; rec=k;
      }
      if(cntMax*2 > r-l+1) ans++;
    }
    MST(g,0);
  }
  printf("%d\n",ans);

  return 0;
}
