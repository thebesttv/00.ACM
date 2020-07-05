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

const int MAX = 40;
int n, k; LL S[MAX][MAX], f[MAX][MAX], frac[MAX];

int main(void){
  S[1][1] = 1;
  FORR(i,2,20) FORR(j,1,i)
    S[i][j] = S[i-1][j-1] + (i-1)*S[i-1][j];

  frac[0] = 1;
  FORR(i,1,20){
    frac[i] = frac[i-1] * i;
    FORR(j,1,i)
      f[i][j] = f[i][j-1] + S[i][j] - S[i-1][j-1];
  }

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    printf("%.4lf\n",1.0*f[n][k]/frac[n]);
  }

  return 0;
}
