// Tag: 数位DP
// Link: [HDU 3652]
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

int l,r,v[20];
int f[20][2];

int dfs(int cur, int last, bool st, bool limited){
  if(!cur) return 1;
  int &a = f[cur][st];
  if(!limited && a != -1) return a;
  int sum = 0, r = limited ? v[cur] : 9;
  FORR(i,0,r) if(i!=4){
    if(last == 6 && i == 2) continue;
    sum += dfs(cur-1, i, i==6, limited && i == v[cur]);
  }
  if(!limited) a = sum;
  return sum;
}

int solve(int x){
  int len = 0;
  while(x) v[++len] = x%10, x/=10;
  MST(f,-1);
  return dfs(len, 0, 0, 1);
}

int main(void){
  while(scanf("%d%d",&l,&r)==2 && l && r){
    printf("%d\n", solve(r) - solve(l-1));
  }

  return 0;
}
