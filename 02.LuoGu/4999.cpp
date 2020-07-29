// Tag: 
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

const LL MOD = 1e9 + 7;
const int MAX = 20;

int v[MAX]; LL l,r,f[MAX][200];

LL dfs(int cur, int last, int sum, bool limited){
  if(!cur) return sum;
  LL &a = f[cur][sum];
  if(!limited && a != -1) return a;
  int r = limited ? v[cur] : 9; LL ans = 0;
  FORR(i,0,r){
    ans = (ans + dfs(cur-1, i, sum+i, limited && i==r))%MOD;
  }
  if(!limited) a = ans;
  return ans;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len] = x%10, x/=10;
  MST(f,-1);
  return dfs(len,0,0,true);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",(solve(r) - solve(l-1) + MOD)%MOD);
  }

  return 0;
}
