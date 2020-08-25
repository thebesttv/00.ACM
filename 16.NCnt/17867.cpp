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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

LL n,st,dp[20][7][2]; int v[20];

LL f(int cur, int sum, bool has7, bool limited){
  if(!cur) return sum==0 || has7;
  LL &a = dp[cur][sum][has7];
  if(!limited && a!=-1) return a;
  int r = limited ? v[cur] : 9; LL ans = 0;
  FORR(i,0,r){
    ans += f(cur-1, (sum*10+i)%7, has7 || i==7, limited && i==r);
  }
  if(!limited) a = ans;
  return ans;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len]=x%10,x/=10;
  return f(len,0,false,true);
}

LL solve(LL l, LL r){
  LL ans = solve(r) - solve(l-1);
#ifdef DEBUG
  printf("[%lld, %lld]: %lld\n",l,r,ans);
#endif
  return ans;
}

int main(void){
  MST(dp,-1);
  scanf("%lld%lld",&st,&n); ++st;
  LL l = st, r = 1e16;
  while(l < r){
    LL m = (l+r)/2;
    if(solve(st, m) >= n) r = m;
    else l = m+1;
  }
  printf("%lld\n",l);
  
  return 0;
}
