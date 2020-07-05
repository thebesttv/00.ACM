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
int n; LL x;
char s[MAX];
int bal[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%lld",&n,&x);
    scanf("%s",s+1);

    int l = 0, r = 0;
    FORR(i,1,n){
      bal[i] = bal[i-1] + ( s[i]=='0' ? 1 : -1 );
      l = min(l, bal[i]);
      r = max(r, bal[i]);
    }

    if(bal[n]==0){
      if(l<=x && x<=r)
        printf("-1\n");
      else
        printf("0\n");
    }else{
      int ans = 0;
      if(x == 0) ++ans; // empty

      FORR(i,1,n) if((x-bal[i])%bal[n] == 0 && (x-bal[i])/bal[n] >=0)
        ++ans;

      printf("%d\n",ans);
    }
  }

  return 0;
}
