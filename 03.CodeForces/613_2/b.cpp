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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1e5 + 20;
int n, a[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    bool allPos = 1;
    scanf("%d",&n);
    LL tot = 0;
    FOR(i,0,n){
      scanf("%d",&a[i]);
      tot += a[i];
      if(a[i] <= 0) allPos = 0;
    }

    if(allPos){
      printf("YES\n"); continue;
    }else if(tot==0){
      printf("NO\n"); continue;
    }

    LL s = 0; bool ok = 1;
    FOR(i,1,n){ // [1:n)
      s += a[i];
      if(s >= tot){
        ok = 0; break;
      }
      if(s<0) s = 0;
    }

    if(ok){
      s = 0;
      FOR(i,0,n-1){
        s += a[i];
        if(s >= tot){
          ok = 0; break;
        }
        if(s<0) s = 0;
      }
    }
    printf("%s\n", ok ? "YES" : "NO");
  }

  return 0;
}
