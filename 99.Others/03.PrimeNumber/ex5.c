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

bool maybePrime(int n){
  return powmod(2,n) == 2%n
}

bool isPrime(int n){
  if(n==1) return 0;
  if(!(n&1)) return n==2;
  int r = sqrt(n)+1;
  FORR(i,3,r) if(n%i==0) return 0;
  return 1;
}

int main(void){
  int n=100000000;
  FORR(i,1,n) if(maybePrime(i) && isPrime(i)){
    printf("%d\n",i);
  }

  return 0;
}
