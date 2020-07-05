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

const int MAX = 1e5 + 20;
const int INF = 0x3f3f3f3f;
int n,ori[MAX],a[MAX],f[MAX],g[MAX];
VR<int> pos[80];

int cal(int x){
  FORR(i,1,n) a[i] = (ori[i]>x ? -INF : ori[i]);
  VR<int> &v = pos[x+40]; MST(f,0), MST(g,0);

  // f
  for(auto it = v.rbegin(); it != v.rend(); ++it){
    int p = *it; f[p] = x;
    int dMax = x; LL d = x;
    FORR(i,p+1,n){
      if(a[i] == -INF) break;
      if(a[i] == x){
        f[p] = max(1ll*f[p], d + f[i]);
        break;
      }
      d += a[i];
      dMax = max(1ll*dMax, d);
    }
    f[p] = max(f[p], dMax);
#ifdef DEBUG
    printf("  x: %d, f[%d]: %d\n",x,p,f[p]);
#endif
  }

  for(int p : v){
    g[p] = x;
    int dMax = x; LL d = x;
    ROR(i,p-1,1){
      if(a[i] == -INF) break;
      if(a[i]==x){
        g[p] = max(1ll*g[p], d + g[i]);
        break;
      }
      d += a[i];
      dMax = max(1ll*dMax, d);
    }
    g[p] = max(g[p], dMax);
#ifdef DEBUG
    printf("  x: %d, g[%d]: %d\n",x,p,g[p]);
#endif
  }

  int ansMax = 0;
  for(int p : v){
    ansMax = max(ansMax, f[p] + g[p] - x*2);
  }
#ifdef DEBUG
  if(ansMax) printf("  x: %d, ansMax: %d\n",x,ansMax);
#endif
  return ansMax;
}

int main(void){
  scanf("%d",&n); int cntP = 0;
  FORR(i,1,n){
    scanf("%d",&ori[i]);
    pos[ori[i]+40].push_back(i);
    if(ori[i] > 0) ++cntP;
  }

  if(cntP <= 1){
    printf("0\n"); return 0;
  }

  int ansMax = 0;
  FORR(x,1,30) ansMax = max(ansMax, cal(x));
  printf("%d\n",ansMax);

  return 0;
}
