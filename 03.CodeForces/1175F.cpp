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

const int MAX = 3e5 + 20;
int n,a[MAX],vis[MAX];
LL H[MAX], sH[MAX], sa[MAX];

int main(void){
  // srand(time(NULL));
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    H[i] = 1ll*rand()*rand();
    sH[i] = sH[i-1]^H[i];
  }
  
  int ans = 0, col = 0;
  FOR(k,0,2){
    FORR(i,1,n) sa[i] = sa[i-1] ^ H[a[i]];
    FORR(i,1,n) if(a[i]==1){
      ans += k==0;
      vis[1] = ++col;
      int tMax = 1;
      for(int r = i+1;r<=n;++r){
        if(vis[a[r]]==col) break;
        vis[a[r]] = col;
        tMax = max(tMax, a[r]);
        int l = r - tMax + 1;
        if(l<=0) continue;
        if((sa[r]^sa[l-1]) == sH[tMax]){
          ++ans;
#ifdef DEBUG
          printf("  l: %d, r: %d, tMax: %d\n",l,r,tMax);
#endif
        }
      }
    }
    if(!k) reverse(a+1,a+n+1);
  }
  printf("%d\n",ans);

  return 0;
}
