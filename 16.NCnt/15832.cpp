// Tag: 状压DP
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

const int MAX = 11;
int n,G[MAX][MAX],dp[1<<MAX];

int f(int st){
  int &a = dp[st];
  if(a!=-1) return a;
  FOR(i,0,n) if(st&(1<<i)) FOR(j,0,n) if((st&(1<<j))==0){
    a = max(a, f(st | (1<<j)) + G[i][j]);
  }
  return a;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,n) FOR(j,0,n) scanf("%d",&G[i][j]);
    MST(dp,-1); dp[(1<<n)-1] = 0;
    int ansMax = 0;
    FOR(i,0,n) ansMax = max(ansMax, f(1<<i));
    printf("%d\n",ansMax);
  }
  return 0;
}
