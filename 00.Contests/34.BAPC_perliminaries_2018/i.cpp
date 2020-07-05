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

const int MAX = 1e6 + 20;
const int MOD = 1e9 + 7;
int n; char s[MAX];
LL f[MAX], g[MAX], p10[MAX];

bool same(int l1, int r1, int l2, int r2){
  int len = r1 - l1 + 1;
#ifdef DEBUG
  printf("  (%d,%d): %lld, (%d,%d): %lld\n",l1,r1,(g[r1]-g[l1-1]*p10[len]%MOD + MOD)%MOD,
      l2,r2,(g[r2]-g[l2-1]*p10[len]%MOD + MOD)%MOD);
#endif
  return (f[r1]^f[l1-1]) == (f[r2]^f[l2-1])
      && (g[r1]-g[l1-1]*p10[len]%MOD + MOD)%MOD ==
         (g[r2]-g[l2-1]*p10[len]%MOD + MOD)%MOD;
}

int main(void){
  scanf("%s",s+1); n = strlen(s+1);
  p10[0] = 1;
  FORR(i,1,n){
    f[i] = f[i-1] ^ s[i];
    g[i] = (g[i-1]*10 + s[i]-'0')%MOD;
    p10[i] = p10[i-1]*10%MOD;
  }

  int i = 1, ans = 0, mid = (n+1)/2;
  while(i <= mid){
    int j = i;
    while(i<=mid && !same(i,j, n-j+1, n-i+1)) ++j;
#ifdef DEBUG
    printf("  same: %d, %d, %d, %d\n",i,j,n-j+1, n-i+1);
#endif
    if(i == n-j+1) ++ans;
    else ans += 2;
    i = j+1;
  }

  printf("%d\n",ans);

  return 0;
}
