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

int l,r,v[20],f[20][10];

int dfs(int cur, int last, bool limited, bool lead){
  if(!cur) return 1;
#ifdef DEBUG
  printf("  dfs(%d, %d, %d, %d)\n",cur,last,limited,lead);
#endif
  int &a = f[cur][last];
  if(!limited && !lead && a != -1) return a;

  int r = limited ? v[cur] : 9, sum = 0;
  FORR(i,0,r) if(lead || abs(last-i)>=2){
    sum += dfs(cur-1, i, limited && i == v[cur], lead && !i);
  }
  if(!limited && !lead) a = sum;
  return sum;
}

int solve(int x){
  int len = 0;
  while(x) v[++len] = x%10, x/=10;
  MST(f,-1);
#ifdef DEBUG
  printf("solve: %d\n",dfs(len,-2,true,true));
#endif
  return dfs(len, -2, true, true);
}

int main(void){
  scanf("%d%d",&l,&r);
  printf("%d\n",solve(r) - solve(l-1));

  return 0;
}
