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

const int MAX = 2e5 + 20, MAXR = 2e6+20;
int n,q,a[MAX],s[MAX],f[MAXR];
VR<int> Q[int(1e6+20)];
int ans[int(1e5+20)];

int main(void){
  scanf("%d",&n);
  int aMax = 0;
  FORR(i,1,n){
    scanf("%d",&a[i]), s[i] = s[i-1] + a[i];
    aMax = max(aMax, a[i]);
  }
  s[n+1] = 2e6 + 2;

  FORR(i,1,n){
    int j = s[i];
    while(j<s[i+1])
      f[j++] = i;
  }
#ifdef DEBUG
  FORR(i,1,20) printf("  f[%d]: %d\n",i,f[i]);
#endif

  scanf("%d",&q); int t, r = s[n];
  FORR(i,1,q) scanf("%d",&t), Q[t].push_back(i);

  FOR(t,1,aMax) for(int x : Q[t])
    ans[x] = -1;
  FORR(t,aMax,r) if(Q[t].size()){
    int cnt = 0, i = 1, j;
    while(i<=n){
      j = f[s[i-1]+t]; ++cnt;
      i = j+1;
    }
    for(int x : Q[t])
      ans[x] = cnt;
  }

  FORR(i,1,q){
    if(ans[i]<0)
      printf("Impossible\n");
    else
      printf("%d\n",ans[i]);
  }

  return 0;
}
