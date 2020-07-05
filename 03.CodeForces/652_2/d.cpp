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

const int MAX = 2e6 + 20;
const LL MOD = 1e9 + 7;
int n; LL f[MAX][2];

int main(void){
  int T; scanf("%d",&T);
  f[3][1] = 1;
  f[4][0] = f[4][1] = 1;
  FORR(i,5,int(2e6)){
    f[i][0] = ( max(f[i-1][0], f[i-1][1]) + max(f[i-2][0], f[i-2][1]) * 2) % MOD;
    f[i][1] = ( 1 + f[i-1][0] + f[i-2][0] * 2) % MOD;
  }
  while(T--){
    scanf("%d",&n);
    printf("%lld\n", max(f[n][0],f[n][1]) * 4 % MOD);
  }

  return 0;
}
