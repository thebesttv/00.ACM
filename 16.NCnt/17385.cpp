// Tag: 
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

LL ans[120]; int len[120];
int tgt,v[120][20]; LL n,f[20][120][120]; // f[cur][sum1%sum2][sum2]

LL dfs(int cur, int sum1, int sum2, bool limited, int *v){
  if(!cur) return sum2 == tgt && !sum1;
  LL &a = f[cur][sum1][sum2];
  if(!limited && a!=-1) return a;
  int r = limited ? v[cur] : 9; LL sum = 0;
  FORR(i,0,r)
    if(sum2 + i <= tgt){
      sum += dfs(cur-1, (sum1*10+i)%tgt, sum2+i, limited && i==r, v);
    }else break;
  if(!limited) a = sum;
  return sum;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(i,1,T){
    scanf("%lld",&n); int l = 0;
    while(n) v[i][++l]=n%10,n/=10;
    len[i] = l;
  }

  for(tgt=1;tgt<=120;++tgt){
    MST(f,-1); 
    FORR(i,1,T) ans[i] += dfs(len[i], 0, 0, true, v[i]);
  }
  FORR(kase,1,T) printf("Case %d: %lld\n",kase,ans[kase]);

  return 0;
}
