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

const int MAX = 4e5 + 20;
const LL MOD = 1e9 + 7;
int n; char s[MAX];
LL f[MAX],g[MAX],pow26[MAX];

bool ok(int i, int j){
  int len = n-j+1;
  LL x = (f[i] - f[i-len] * pow26[len] % MOD + MOD) % MOD;
  return x == g[j];
}

int main(void){

  scanf("%d%s",&n,s+1);
  FORR(i,1,n) f[i] = (f[i-1] * 26 + s[i]-'a')%MOD;
  ROR(i,n,1) g[i] = (g[i+1] * 26 + s[i]-'a')%MOD;

  pow26[0] = 1;
  FORR(i,1,n) pow26[i] = pow26[i-1]*26%MOD;

  int ans = n;
  if((n&1) && ok(n/2, n/2+2)){
    ans = 0;
  }

  FORR(i,(n+1)/2+1,n){
    if(ok(i-1, i)){
      ans = min(ans, 2*i-2-n);
    }
    if(i==n || ok(i-1,i+1)){
      ans = min(ans, 2*i-1-n);
    }
  }
  printf("%d\n",ans);

  return 0;
}
