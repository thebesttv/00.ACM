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

const int MAX = 1e7 + 20;
LL n;
int v[MAX], tail;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    tail = 0; v[tail++] = 0;
    scanf("%lld",&n);
    for(LL i = 1,j; i<=n; i=j+1){
      j = n / (n/i);
      v[tail++] = n/i;
    }
    printf("%d\n",tail);
    reverse(v+1,v+tail);
    FOR(i,0,tail) printf("%d ",v[i]); putchar('\n');
  }

  return 0;
}
