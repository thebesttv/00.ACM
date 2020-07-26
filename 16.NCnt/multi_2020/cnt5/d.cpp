// Tag: iii 环 LIS
// LIS: longest increasing subsequence
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

const int MAX = 520;
int n,a[MAX],f[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  int tMax = 0;
  FOR(k,0,n){
    FORR(i,1,n){
      int &x = f[i]; x = 1;
      FOR(j,1,i) if(a[j] < a[i])
        x = max(x, f[j] + 1);
      tMax = max(tMax, x);
    }
    ROR(i,n,1) a[i+1] = a[i];
    a[1] = a[n+1];
  }
  printf("%d\n",n - tMax);

  return 0;
}