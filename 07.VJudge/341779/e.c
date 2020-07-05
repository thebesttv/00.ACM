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

const int MAX=120;
int n,a[MAX][MAX],f[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) FORR(j,1,i)
      scanf("%d",&a[i][j]);

    f[1] = a[1][1];
    FORR(i,2,n){
      f[i] = f[i-1] + a[i][i];
      ROR(j,i-1,2)
        f[j] = max(f[j-1], f[j]) + a[i][j];
      f[1] += a[i][1];
    }
    int ansMax=0;
    FORR(i,1,n) ansMax=max(ansMax,f[i]);
    printf("%d\n",ansMax);
  }
  
  return 0;
}
