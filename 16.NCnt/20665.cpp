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

int v[20]; LL l, r, f[20][7][7];

LL dfs(int cur, int sum1, int sum2, bool limited){
  if(!cur) return !sum1 && !sum2;
  LL &a = f[cur][sum1][sum2];
  if(!limited && a!=-1) return a;
  LL sum = 0; int r = limited ? v[cur] : 9;
  FORR(i,0,r){
    sum += dfs(cur-1, (sum1+i)%7, (sum2*10+i)%7, limited && i==r);
  }
  if(!limited) a = sum;
  return sum;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len]=x%10,x/=10;
  return dfs(len, 0, 0, true);
}

int main(void){
  MST(f,-1);
  while(scanf("%lld%lld",&l,&r) && (l||r)){
    printf("%lld\n",solve(r) - solve(l-1));
  }

  return 0;
}
