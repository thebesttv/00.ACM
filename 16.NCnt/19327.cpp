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

LL l,r,dp[20][4]; int v[20];
// st = 0: no 007
//    = 1: the first 0
//    = 2: the second 0
//    = 3: has 007

LL f(int cur, int st, bool limited, bool lead){
  if(!cur) return st == 3;
  LL &a = dp[cur][st];
  if(!limited && !lead && a!=-1) return a;
  int r = limited ? v[cur] : 9; LL sum = 0;
  if(st == 0){
    FORR(i,0,r) sum += f(cur-1, st + (!lead && !i), limited && i==r, lead && !i);
  }else if(st == 1){
    FORR(i,0,r) sum += f(cur-1, st + (!i), limited && i==r, lead && !i);
  }else if(st == 2){
    FORR(i,0,r) sum += f(cur-1, st + (i==7), limited && i==r, lead && !i);
  }else{
    FORR(i,0,r) sum += f(cur-1, st, limited && i==r, lead && !i);
  }
  if(!limited && !lead) a = sum;
  return sum;
}

LL solve(LL x){
  if(x<=0) return 0;
  int len = 0;
  while(x) v[++len]=x%10,x/=10;
  return f(len,0,true,true);
}

int main(void){
  MST(dp,-1);
  int T; scanf("%d",&T); LL ans = 0;
  while(T--){
    scanf("%lld%lld",&l,&r);
    ans ^= solve(r) - solve(l-1);
  }
  printf("%lld\n",ans);

  return 0;
}
