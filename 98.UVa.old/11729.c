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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1000 + 10;
int n, kase=0;
struct Ind{
  int a,b;

  bool operator < (const Ind &i) const {
    return b > i.b;
  }
}ind[MAX];

int main(void){
  while(scanf("%d",&n) && n){
    FOR(i,0,n) scanf("%d%d", &ind[i].a, &ind[i].b);
    sort(ind, ind+n);

    int ans=0,sa=0;
    FOR(i,0,n){
      sa += ind[i].a;
      ans = max(ans, sa + ind[i].b);
    }
    printf("Case %d: %d\n",++kase,ans);
  }

  return 0;
}
