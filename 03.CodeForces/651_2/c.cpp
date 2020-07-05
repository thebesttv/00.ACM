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

/*
bool win(){
  if(n == 1) return false;
  if(n == 2) return true;

  FOR(i,0,40) if(n == (1ll<<i))
    return false;

  if(n&1) return true;
  if(n % 4 == 0) return true;

  n /= 2; int cnt = 0, r = sqrt(n+0.5);
  FORR(i,3,r) if(n%i==0){
    while(n%i==0) n/=i, ++cnt;
    if(cnt >= 2) return true;
  }
  if(n > 1) ++cnt;

  return cnt >= 2;
}
*/

bool isPrime(LL n){
  if(!(n&1)) return n == 2;
  int r = sqrt(n+0.5);
  FORR(i,2,r) if(n%i==0)
    return false;
  return true;
}

bool win(){
  if(n&1) return n >= 3;
  FOR(i,1,40) if(n == (1ll<<i))
    return n == 2;
  if(n%4==0) return true;
  return !isPrime(n/2);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld",&n);
    printf("%s\n", win() ? "Ashishgup" : "FastestFinger");
  }

  return 0;
}
