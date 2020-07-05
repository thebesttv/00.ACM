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

const int MAX = 8020;
int n,a[MAX],s[MAX],cnt[MAX],vis[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FORR(i,1,n) vis[i] = cnt[i] = 0;
    scanf("%d",&n);
    FORR(i,1,n){
      scanf("%d",&a[i]);
      s[i] = s[i-1] + a[i];
      ++cnt[a[i]];
    }

    int x;
    FORR(l,1,n) FORR(r,l+1,n){
      x = s[r] - s[l-1];
      if(x <= n) vis[x] = 1;
    }

    int ans = 0;
    FORR(i,1,n) ans += vis[i] * cnt[i];
    printf("%d\n",ans);
  }

  return 0;
}
