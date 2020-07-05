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

const int MAX = 30;
int n,l,r;
LL f[MAX][MAX][MAX];

LL dp(int i, int j, int k){
  if(i<=0) return 0;
  LL &a = f[i][j][k];
  if(a!=-1) return a;
  a = 0;
  if(j>1) a += dp(i-1,j-1,k);
  if(k>1) a += dp(i-1,j,k-1);
  a += dp(i-1,j,k) * (i-2);
  return a;
}

int main(void){
  MST(f,-1);
  f[1][1][1] = 1;
  f[2][2][1] = f[2][1][2] = 1;

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&l,&r);
    printf("%lld\n",dp(n,l,r));
  }

  return 0;
}
