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

const int MAX = 1e5 + 20;
int n; LL a,r,m;
LL h[MAX],s[MAX];

int main(void){
  scanf("%d%lld%lld%lld",&n,&a,&r,&m);
  FORR(i,1,n) scanf("%lld",&h[i]);
  sort(h+1,h+1+n);
  FORR(i,1,n) s[i] = s[i-1] + h[i];

  LL ansMin = 0x3f3f3f3f3f3f3f3fLL;

  {
    LL k = s[n] / n, sum = 0;
    FORR(i,1,n)
      if(h[i]<k) sum += k-h[i];
      else break;
    ansMin = min(ansMin, (s[n]-k*n)*r + sum*m);
  }

  {
    LL k = s[n] / n + 1, sum = 0;
    FORR(i,1,n) if(h[i]>k)
      sum += h[i]-k;
    ansMin = min(ansMin, (k*n-s[n])*a + sum*m);
  }

  FORR(i,1,n){
    LL lo = (i-1)*h[i] - s[i-1];
    LL hi = s[n]-s[i] - (n-i)*h[i];
    LL cost = 0;
    if(m < a + r){
      LL d = min(hi, lo);
      hi -= d, lo -= d;
      cost = d * m + hi * r + lo * a;
    }else{
      cost = hi * r + lo * a;
    }
    ansMin = min(ansMin, cost);
  }
  printf("%lld\n",ansMin);

  return 0;
}
