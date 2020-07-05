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

const int MAX=2020;
const int INF=0x3f3f3f3f;
int n,k,v[MAX];
int f[MAX][MAX];

int main(void){
  while(scanf("%d%d",&n,&k)==2){
    FORR(i,1,n) scanf("%d",&v[i]);
    sort(v+1,v+1+n);

    FORR(i,1,n) FORR(j,1,k) f[i][j]=INF;

    FORR(i,2,n){
      int d = v[i]-v[i-1];
      for(int j=1;j<=i/2 && j<=k;++j){
        f[i][j] = min(f[i-1][j], f[i-2][j-1] + d*d);
      }
    }
    printf("%d\n",f[n][k]);
  }

  return 0;
}
