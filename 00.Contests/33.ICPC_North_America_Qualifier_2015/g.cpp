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

const int MAX = (1<<15) + 20;
const int INF = 0x3f3f3f3f;
int n,v[20],len[MAX],dp[MAX];

int f(int st){
  int &a = dp[st];
  if(a==-2) return INF;
  if(a!=-1) return a;
  a = -2;

  int tMin = INF;
  FOR(r1,0,n) if(st&(1<<r1)) {
    // FOR(s,0,n) if(s != r1 && (st&(1<<s)) == 0) {
    //   tMin = min(tMin, f( ( st & (~(1<<r1)) ) | (1<<s) ) + v[r1] + v[s] );
    //   break;
    // }

    FOR(r2,r1+1,n) if(st&(1<<r2)) {
      FOR(s, 0, n) if((st&(1<<s))==0) {
        tMin = min(tMin, f( ( st & (~(1<<r1)) & (~(1<<r2)) ) | (1<<s) ) + max(v[r1],v[r2]) + v[s] );
        break;
      }

      // assume r1 is sender
      tMin = min(tMin, f( st & (~(1<<r2)) ) + max(v[r1],v[r2]) + v[r1] );
    }
  }
  return a = tMin;
}

int main(void){
  MST(dp,-1);
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&v[i]);
  sort(v,v+n);

  dp[0] = 0;
  FOR(i,0,n){
    dp[1<<i] = v[i];
    FOR(j,i+1,n){
      dp[(1<<i) | (1<<j)] = max(v[i],v[j]);
    }
  }

  printf("%d\n",f((1<<n)-1));

  return 0;
}
