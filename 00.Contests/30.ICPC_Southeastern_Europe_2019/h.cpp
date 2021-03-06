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

const int MAX = 1020;
int n;

int main(void){
  scanf("%d",&n);
  VR<int> a(n), b(n);
  FOR(i,0,n) scanf("%d",&a[i]);
  FOR(i,0,n) scanf("%d",&b[i]);
  int ans = 0;
  FOR(i,0,n){
    int tMin = 0x3f3f3f3f;
    FOR(j,0,n) tMin = min(tMin,abs(a[i]-b[j]));
    ans = max(ans, tMin);
  }
  printf("%d\n",ans);

  return 0;
}
