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

const int MAX = 1e6 + 20;
int n,a[MAX],f[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  if(n==1){
    printf("%d %d\n",1,1);
    return 0;
  }

  f[1] = 1;
  int tMax = 0, r = 0;
  FORR(i,2,n){
    if(a[i] <= a[i-1])
      f[i] = f[i-1] + 1;
    else
      f[i] = 1;

    if(a[i] != a[i-f[i]+1]){
      if(f[i] > tMax)
        tMax = f[r=i];
    }
  }

  if(!tMax) r = 1;

  reverse(a+r-f[r]+1, a+r+1);
  bool ok = 1;
  FORR(i,2,n) if(a[i] < a[i-1]){
    ok = 0; break;
  }
  if(ok) printf("%d %d\n",r-f[r]+1,r);
  else printf("impossible\n");

  return 0;
}
