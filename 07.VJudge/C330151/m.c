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

const int MAX=1020;
int n,m,a[MAX][MAX],f[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&m);
    FORR(i,1,n) FORR(j,1,m) scanf("%d",&a[i][j]);
    FORR(j,1,m) f[1][j]=f[1][j-1]+a[1][j];
    FORR(i,2,n) FORR(j,1,m){
      f[i][j] = max(f[i-1][j], max(f[i][j-1],f[i-1][j-1])) + a[i][j];
    }
    printf("Scenario #%d:\n%d\n\n",kase,f[n][m]);
  }

  return 0;
}
