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

const int MAX = 2020;
int n,a[MAX];
map<int, VR<int>> pos;

int find(int x, int p){
  if(!pos.count(x)) return 0;
  VR<int> &v = pos[x];
#ifdef DEBUG
  printf("  find(%d, %d): %d\n",x,p,lower_bound(ALL(v), p) - v.begin());
#endif
  return v.end() - lower_bound(ALL(v), p);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    pos.clear(); scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d",&a[i]);
      pos[a[i]].push_back(i);
#ifdef DEBUG
      printf("  pos[%d] += %d\n",a[i],i);
#endif
    }

    int ans = 0;
    FOR(i,0,n) FOR(j,i+1,n)
      ans += find(2*a[j]-a[i], j+1);
    printf("%d\n",ans);
  }

  return 0;
}
