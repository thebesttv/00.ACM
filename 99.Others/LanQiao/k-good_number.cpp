// Tag: 数位DP
// Url: http://lx.lanqiao.cn/problem.page?gpid=T13
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

const LL MOD = 1000000007;
const int MAX = 120;
int k,l; LL f[MAX][MAX];

LL dfs(int cur, int last, bool lead){
  if(!cur) return 1;
  LL &a = f[cur][last];
  if(!lead && a != -1) return a;

  LL sum = 0;
  FOR(i,lead ? 1 : 0,k) if(abs(last - i) != 1){
    sum += dfs(cur-1,i,false);
  }
  sum %= MOD;
  if(!lead) a = sum;
#ifdef DEBUG
  printf("  dfs(%d, %d, %d): %lld\n",cur,last,lead,sum);
#endif
  return sum;
}

int main(void){
  scanf("%d%d",&k,&l); MST(f,-1);
  printf("%lld\n",dfs(l,-1,true));

  return 0;
}
