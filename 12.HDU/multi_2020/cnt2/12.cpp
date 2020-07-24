// Tag: DP iii LCS
// LCS: longest common subsequence, 最长公共子序列
// edit distance = |A| + |B| - |LCS(A,B)|
// f[i][j]: B[1:i]中有j个在LCS中时，对应在A中的最小下标
// g[i][ch]: A[i:n]中，ch第一次出现位置
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

const int MAXA = 100000, MAXB = 40;
const int INF = 0x3f3f3f3f;
int n,m,f[MAXB][MAXB],g[MAXA][26];
char a[MAXA],b[MAXB];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s%s",a+1,b+1);
    n = strlen(a+1), m = strlen(b+1);
    FOR(i,0,26) g[n][i] = INF;
    g[n][a[n]-'a'] = n;
    ROR(i,n-1,1){
      FOR(j,0,26) g[i][j] = g[i+1][j];
      g[i][a[i]-'a'] = i;
    }
    int q,l,r,t; scanf("%d",&q);
    while(q--){
      scanf("%d%d",&l,&r); MST(f,0x3f);
      f[0][0] = l-1; int ans = 0;
      FORR(i,1,m) FORR(j,0,i){
        f[i][j] = f[i-1][j];
        if(j && f[i-1][j-1] <n && (t = g[f[i-1][j-1]+1][b[i]-'a']) <= r)
          f[i][j] = min(f[i][j], t);
        if(f[i][j] < INF) ans = max(ans, j);
      }
      printf("%d\n", r-l+1 + m - ans*2);
    }
  }

  return 0;
}
