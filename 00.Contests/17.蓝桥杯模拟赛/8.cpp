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

const int MAX = 1020;
const int MOD = 10000;
int n,dp[MAX][MAX];

int f(int i, int j){
  int &a = dp[i][j];
  if(a!=-1) return a;
  a = 1;
  int d = abs(i-j);
  FOR(k,1,d) a += f(j,k);
  return a%=MOD;
}

int main(void){
  scanf("%d",&n);
  MST(dp,-1);
  LL ans = 0;
  FORR(i,1,n)
    ans += f(n,i);
  ans %= MOD;
  printf("%lld\n",ans);

  return 0;
}
