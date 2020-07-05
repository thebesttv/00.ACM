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

const int MAXN=10020, MAXM=5020;
const int INF=0x3f3f3f3f;
int n,m,a[MAXN],f[MAXM][MAXN],r[MAXM][MAXN];

inline int square(int n){
  return n*n;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&m);
    FORR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    
    FORR(j,1,n) f[1][j]=square(a[j]-a[1]), r[1][j]=1;
    FORR(i,2,m){
      r[i][n+1]=n-1;
      ROR(j,n,i){
        f[i][j]=INF;
        FORR(k,r[i-1][j],r[i][j+1]){
          int t = f[i-1][k] + square(a[j]-a[k+1]);
          if(f[i][j]>t) f[i][j]=t, r[i][j]=k;
        }
      }
    }
    printf("Case %d: %d\n",kase,f[m][n]);
  }

  return 0;
}
