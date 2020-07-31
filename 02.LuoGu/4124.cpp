// Tag: 数位DP i
// 限制长为11位
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

const int MAX = 14;
int v[MAX]; LL l,r,f[MAX][11][11][2][2][2];

LL dfs(int cur, int last1, int last2, bool st, bool has4, bool has8, bool limited, bool lead){
  if(!cur) return st && (!has4 || !has8);
  LL &a = f[cur][last1+1][last2+1][st][has4][has8];
  if(!limited && !lead && a!=-1) return a;
  int l = lead ? 1 : 0, r = limited ? v[cur] : 9;
  LL sum = 0;
  FORR(i,l,r){
    if(i==4 && has8) continue;
    if(i==8 && has4) continue;
    sum += dfs(cur-1, i, last1, st || (last1 == last2 && i == last1),
        has4 || i==4, has8 || i==8, limited && i==r, false);
  }
  if(!limited && !lead) a = sum;
  return sum;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len]=x%10,x/=10;
  MST(f,-1);
  return dfs(len,-1,-1,false,false,false,true,true);
}

int main(void){
  scanf("%lld%lld",&l,&r);
  printf("%lld\n",solve(r) - (l == 10000000000ll ? 0 : solve(l-1)));

  return 0;
}
