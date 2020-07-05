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

const int MAX = 130;
int n, a[MAX], s;
bool ok(int k){
  return n*k > 2*s;
}

int main(void){
  scanf("%d",&n);
  int aMax = 0;
  FORR(i,1,n){
    scanf("%d",&a[i]);
    aMax = max(aMax, a[i]);
    s += a[i];
  }
  int t = 2*s / n;
  int k = 0x3f3f3f3f;

  if(ok(t)) k = t;
  if(ok(t+1)) k = min(k, t+1);
  if(ok(t-1)) k = min(k,t-1);

  k = max(k, aMax);
  printf("%d\n",k);

  return 0;
}
