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

const int MAX = 100;
int n,m,G[MAX][MAX],cnt0[MAX],cnt1[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(cnt0,0), MST(cnt1,0);
    scanf("%d%d",&n,&m);
    int len = n + m - 1;
    FORR(i,1,n) FORR(j,1,m){
      scanf("%d",&G[i][j]);
      if(G[i][j]) cnt1[i+j-1]++;
      else cnt0[i+j-1]++;
    }
    int ans = 0;
    FORR(i,1,len/2){
      ans += min(cnt0[i]+cnt0[len+1-i], cnt1[i]+cnt1[len+1-i]);
    }
    printf("%d\n",ans);
  }

  return 0;
}
