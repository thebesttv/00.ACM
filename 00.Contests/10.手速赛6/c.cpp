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

const int MAX = 200020;
int n,q,a[MAX];
LL s[MAX],lt,k;

int main(void){
  scanf("%d%d",&n,&q);
  FORR(i,1,n) scanf("%d",&a[i]), s[i] = s[i-1] + a[i];
  int l = 1;
  while(q--){
    scanf("%lld",&k);
    k += lt;
    int r = lower_bound(s+1,s+1+n,k+s[l-1]) - s;
#ifdef DEBUG
    printf("  get k: %lld, left: %lld, r: %d\n",k,lt,r);
#endif
    if(r>n){
      lt = 0; l = 1;
    }else{
      if(s[r]-s[l-1] == k){
        l = r+1;
        lt = 0;
        if(l>n) l = 1;
      }else{
        lt = k - (s[r-1]-s[l-1]);
        l = r;
      }
    }
    printf("%d\n",n-l+1);
  }
  return 0;
}
