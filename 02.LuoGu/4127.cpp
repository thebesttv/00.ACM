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

const int MAX = 180;
int v[MAX],target; LL l,r,f[20][MAX][MAX];

LL dfs(int cur, int sum, int mod, bool limited){
  if(!cur) return sum == target && !mod;
  LL &a = f[cur][sum][mod];
  if(!limited && a != -1) return a;
  int r = limited ? v[cur] : 9; LL s = 0;
  FORR(i,0,r)
    if(sum + i <= target){
      s += dfs(cur-1, sum+i, (mod*10+i)%target, limited && i==r);
    }else break;
  if(!limited) a = s;
  return s;
}

LL solve(LL x){
  int len = 0;
  while(x) r += x%10, v[++len] = x%10, x/=10;
  LL sum = 0; int r = len * 9;
  FORR(i,1,r){
    MST(f,-1); target = i;
    sum += dfs(len, 0, 0, true);
  }
  return sum;
}

int main(void){
  scanf("%lld%lld",&l,&r);
  printf("%lld\n",solve(r) - solve(l-1));

  return 0;
}
