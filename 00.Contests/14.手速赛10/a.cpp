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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 2020;
const LL MOD = 998244353;
int n,m,k;
LL f[MAX][MAX];

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  f[1][0] = m;
  FORR(i,2,n) FOR(j,0,i){
    f[i][j] = f[i-1][j];
    if(j) f[i][j] = (f[i][j] + f[i-1][j-1]*(m-1)%MOD)%MOD;
  }
  printf("%lld\n",f[n][k]);

  return 0;
}
