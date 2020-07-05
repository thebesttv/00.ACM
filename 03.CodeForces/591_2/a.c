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

LL x,y;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&x,&y);
    printf("%s\n", x-y==1 ? "NO" : "YES");
  }

  return 0;
}

/*
bool isPrime(LL n){
  if(n==1) return 0;
  if((n&1)==0) return n==2;
  int r=sqrt(n+0.5);
  for(int i=3;i<=r;i+=2)
    if(n%i==0) return 0;
  return 1;
}
*/

/*
bool isPrime(LL n){
  if(n==1) return 0;
  if((n&1)==0) return n==2;
  if(n==3) return 1;
  if(n%6!=1 && n%6!=5) return 0;
  int r=sqrt(n+0.5);
  for(int i=5;i<=r;i+=6)
    if(n%i==0 || n%(i+2)==0) return 0;
  return 1;
}

bool ok(LL m){
  if((m&1)==0) return 1;
  if(isPrime(m)) return 1;
  LL r=sqrt(m+0.5);
  FORR(i,3,r) if(m%i==0){
    if(isPrime(i)) return true;
    if(isPrime(m/i)) return true;
  }
  return 0;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    LL x,y; scanf("%lld%lld",&x,&y);
    printf("%s\n", ok(x-y) ? "YES" : "NO" );
  }

  return 0;
}
*/
