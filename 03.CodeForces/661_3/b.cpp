// Tag: notag
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 120;
int n,a[MAX],b[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n) scanf("%d",&b[i]);
    int aMin = a[0], bMin = b[0];
    FOR(i,1,n) aMin = min(aMin, a[i]);
    FOR(i,1,n) bMin = min(bMin, b[i]);
    LL ans = 0;
    FOR(i,0,n){
      int ta = a[i] - aMin, tb = b[i] - bMin;
      ans += max(ta, tb);
    }
    printf("%lld\n",ans);
  }

  return 0;
}
