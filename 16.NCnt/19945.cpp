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

LL l,r,dp[20][10][20][2][2][2]; int v[20];
LL f(int cur, int last, int cnt, bool st, bool has4, bool has8, bool limited, bool lead){
  if(!cur) return st && !(has4 && has8);
  LL &a = dp[cur][last][cnt][st][has4][has8];
  if(!limited && !lead && a!=-1) return a;
  int l = lead ? 1 : 0, r = limited ? v[cur] : 9; LL sum = 0;
  FORR(i,l,r){
    int nc = i == last ? cnt+1 : 1;
    sum += f(cur-1, i, nc, st || nc>=3, has4 || i==4, has8 || i==8, limited && i==r, lead && !i);
  }
  if(!limited && !lead) a = sum;
  return sum;
}

LL solve(LL x){
  int len=0; MST(v,0);
  while(x) v[++len]=x%10,x/=10;
  return f(11,0,0,0,0,0,true,true);
}

int main(void){
  MST(dp,-1); scanf("%lld%lld",&l,&r);
  printf("%lld\n",solve(r) - solve(l-1));

  return 0;
}
