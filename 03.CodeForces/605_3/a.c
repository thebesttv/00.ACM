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

LL v[3][3];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,3){
      scanf("%lld",&v[i][0]);
      v[i][1] = v[i][0] - 1;
      v[i][2] = v[i][0] + 1;
    }
    LL ansMin = abs(v[0][0] - v[1][0]) +
                abs(v[1][0] - v[2][0]) +
                abs(v[2][0] - v[0][0]);
    FOR(i,0,3) FOR(j,0,3) FOR(k,0,3)
      ansMin = min(ansMin, abs(v[0][i]-v[1][j])
                         + abs(v[1][j]-v[2][k])
                         + abs(v[2][k]-v[0][i]));
    printf("%lld\n",ansMin);
  }

  return 0;
}
