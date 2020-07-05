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

const int MAX = 320;
const LL MOD = 1000000000;
int n; LL f[MAX][MAX];
char s[MAX];

LL dp(int l, int r){
  if((r-l)&1) return 0;
  LL &a = f[l][r];
  if(a!=-1) return a;
  if(s[l]!=s[r]) return a=0;
  a = 0;
  FORR(k,l+2,r) if(s[l]==s[k]){
    a = ( a + dp(l+1,k-1) * dp(k,r) % MOD )%MOD;
  }
  return a;
}

int main(void){
  while(scanf("%s",s+1)==1){
    n = strlen(s+1);
    MST(f,-1);
    FORR(i,1,n) f[i][i]=1;

    printf("%lld\n",dp(1,n));
  }
  return 0;
}
