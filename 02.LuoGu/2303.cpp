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

LL n;
set<LL> d;

void calD(LL n){
  int r = sqrt(n+0.5);
  FORR(i,2,r) if(n%i==0){
    d.insert(i);
    while(n%i==0) n/=i;
  }
  if(n>1) d.insert(n);
}

int main(void){
  cin >> n;
  LL ans = n;
  calD(n);
  for(LL x : d){
    int a = 0;
    while(n%x==0) n/=x, ++a;
    ans = ans / x * ( (x-1)*a + x);
  }
  cout << ans << endl;

  return 0;
}

/*
LL n;

LL phi(LL n){
  int r = sqrt(n+0.5);
  LL ans = n;
  FORR(i,2,r) if(n%i==0){
    ans -= ans/i;
    while(n%i==0) n/=i;
  }
  if(n>1) ans -= ans/n;
  return ans;
}

int main(void){
  cin >> n;
  LL ans = 0;
  int r = sqrt(n+0.5);
  FORR(i,1,r) if(n%i==0){
    ans += i * phi(n/i);
    if(1ll*i*i != n)
      ans += (n/i) * phi(i);
  }
  cout << ans << endl;

  return 0;
}
*/
