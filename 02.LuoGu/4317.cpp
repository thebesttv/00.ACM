// Tag: 数位DP
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

const LL MOD = 10000007;
const int MAX = 80;
int v[MAX]; LL n,f[MAX][MAX];

LL dfs(int cur, int last, int cnt, bool limited){
  if(!cur) return max(cnt, 1);
  LL &a = f[cur][cnt], prod = 1;
  if(!limited && a!=-1) return a;

  int r = limited ? v[cur] : 1;
  FORR(i,0,r){
    prod = prod * dfs(cur-1, i, cnt + i, limited && i == v[cur]) % MOD;
  }

  if(!limited) a = prod;
  return prod;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len] = x&1, x>>=1;
  MST(f,-1);
  return dfs(len,0,0,true);
}

int main(void){
  scanf("%lld",&n);
  printf("%lld\n",solve(n));

  return 0;
}
