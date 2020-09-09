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

int l,r,v[20],f[20][4];
// for st:
// bit 0 = 1: last is 3
// bit 1 = 1: has 4 or 38

int dfs(int cur, int st, bool limited, bool lead){
  if(!cur) return (st>>1)&1;
  int &a = f[cur][st];
  if(!limited && !lead && a!=-1) return a;
  int r = limited ? v[cur] : 9, sum = 0;
  FORR(i,0,r){
    if(i == 4 || ((st&1) && i==8)) sum += dfs(cur-1, 2, limited && i==r, false);
    else if(i == 3) sum += dfs(cur-1, st | 1, limited && i==r, false);
    else sum += dfs(cur-1, st & 2, limited && i==r, lead && !i);
  }
  if(!limited && !lead) a = sum;
  return sum;
}

int solve(int x){
  if(x < 0) return 0;
  int len = 0;
  while(x) v[++len] = x%10, x/=10;
  return dfs(len, 0, true, true);
}

int main(void){
  MST(f,-1);
  while(scanf("%d%d",&l,&r)==2 && (l||r)){
    printf("%d\n",solve(r)-solve(l-1));
  }

  return 0;
}