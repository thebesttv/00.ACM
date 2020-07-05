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

const int MAX = 1e5, MAX_ = MAX+20;
int n,k; LL s[MAX_];

int main(void){
  FORR(i,1,MAX) s[i] = s[i-1] + i;
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    int t = lower_bound(s,s+MAX+1,k) - s;
    int p1 = n-t, p2 = p1 + s[t]-k+1;
#ifdef DEBUG
    printf("  %d, %d\n",p1,p2);
#endif
    FOR(i,1,p1) putchar('a');
    putchar('b');
    FOR(i,p1+1,p2) putchar('a');
    putchar('b');
    FORR(i,p2+1,n) putchar('a');
    putchar('\n');
  }

  return 0;
}
