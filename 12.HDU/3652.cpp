// Tag: 数位DP why
// Link: [HDU 2089]
// 与 [HDU 2089] 比，这里的 f 为何多 last 一维？
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

const int MAX = 20;
int n,v[MAX],f[MAX][MAX][2][MAX];

int dfs(int cur, int last, bool ok, int mod, bool limited, bool lead){
  if(!cur) return ok && !mod;
  int &a = f[cur][last][ok][mod];
  if(!limited && !lead && a != -1) return a;
  int sum = 0, r = limited ? v[cur] : 9;
  FORR(i,0,r){
    sum += dfs(cur-1, i, ok || (last==1 && i==3),  (mod*10+i)%13, limited && i==v[cur], lead && !i);
  }

  if(!limited && !lead) a = sum;
  return sum;
}

int solve(int x){
  int len = 0;
  while(x) v[++len] = x%10, x/=10;
  MST(f,-1);
  return dfs(len, 0, false, 0, true, true);
}

int main(void){
  while(scanf("%d",&n) == 1)
    printf("%d\n",solve(n));

  return 0;
}
