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

const int MAX = 10;
int n,k,cnt[1<<MAX]; LL f[MAX][MAX*MAX][1<<MAX];

int main(void){
  FOR(st,0,1<<9) FOR(j,0,9) cnt[st] += (st>>j)&1;

  scanf("%d%d",&n,&k);
  f[0][0][0] = 1;
  FOR(i,0,n) FORR(j,0,k) FOR(st1,0,1<<n) if((st1&(st1<<1))==0 && f[i][j][st1]){
    LL a = f[i][j][st1];
    FOR(st2,0,1<<n) if(j+cnt[st2]<=k && (st2&(st2<<1))==0 && (st2&st1)==0 && (st2&(st1<<1))==0 && (st2&(st1>>1))==0){
      f[i+1][j+cnt[st2]][st2] += a;
#ifdef DEBUG
    printf("f[%d][%d][%d] -> f[%d][%d][%d]\n",i,j,st1,i+1,j+cnt[st2],st2);
#endif
    }
#ifdef DEBUG
    printf("f[%d][%d][%d]: %lld\n",i,j,st1,a);
#endif
  }
  LL ans = 0;
  FOR(st,0,1<<n) ans += f[n][k][st];
  printf("%lld\n",ans);

  return 0;
}
