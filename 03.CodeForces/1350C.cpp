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
int n,a[MAX];
VR<int> G[MAX];

LL power(LL a, LL x){
  LL ans = 1;
  while(x--) ans *= a;
  return ans;
}

void div(int n){
  int r = sqrt(n+0.5);
  FORR(i,2,r) if(n%i==0){
    int cnt = 0;
    while(n%i==0) n/=i, ++cnt;
    G[i].push_back(cnt);
  }
  if(n>1) G[n].push_back(1);
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]), div(a[i]);

  LL ans = 1;
  FORR(i,2,200000) if(G[i].size() >= n-1){
    sort(ALL(G[i]));
#ifdef DEBUG
    printf("  *= %d ^ %d\n",i,G[i][G[i].size()==n ? 1 : 0]);
#endif
    ans *= power(i, G[i][G[i].size()==n ? 1 : 0]);
  }
  printf("%lld\n",ans);

  return 0;
}
