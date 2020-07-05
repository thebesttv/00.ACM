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

const int MAX = 120;
const int INF = 0x3f3f3f3f;
int n,a[MAX],b[MAX],c[MAX];
int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  FORR(i,1,n) scanf("%d",&b[i]);
  FORR(i,1,n) scanf("%d",&c[i]);

  int ans = -INF;
  FORR(i,1,n){
    int tMin = INF;
    FORR(j,1,n){
      int dMin = INF, r = -1;
      FORR(k,1,n){
        int s = a[i]+b[j]+c[k];
        if(abs(s) < dMin){
          dMin = abs(s), r = k;
        }else if(abs(s) == dMin && s > dMin){
          dMin = abs(s), r = k;
        }
      }
      tMin = min(tMin, a[i]+b[j]+c[r]);
    }
    ans = max(ans, tMin);
  }
  printf("%d\n",ans);

  return 0;
}
