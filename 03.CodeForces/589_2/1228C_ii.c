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

const LLU MOD = 1e9+7;
int x; LLU n;
VR<LLU> prime;

bool isPrime(int n){
  if(n==1) return 0;
  if(!(n&1)) return n==2;
  int r = sqrt(n+0.5);
  for(int i=3;i<=r;i+=2)
    if(n%i==0) return 0;
  return 1;
}

LLU pow(LLU x, LLU y){
  if(y==0) return 1;
  if(y==1) return x;
  LLU t = pow(x,y>>1);
  t = t * t % MOD;
  if(y&1) t = t * x % MOD;
  return t;
}

int main(void){
  scanf("%d%llu",&x,&n);

  int r = sqrt(x+0.5);
  FORR(i,1,r) if(x%i==0){
    if(isPrime(i)) prime.push_back(i);
    if(i*i!=x && isPrime(x/i)) prime.push_back(x/i);
  }
#ifdef DEBUG
  printf("prime:");
  for(LLU p : prime) printf(" %llu",p);
  putchar('\n');
#endif

  LLU ans = 1;
  for(LLU p : prime){
    LLU pk = p;
    while(pk <= n){
      LLU m = n/pk - n/pk/p;  // n/pk/p ???
      ans = ans * pow(pk%MOD,m) % MOD;
      //if(1.0*pk*p > 1.0*n) break; // double 精度不行
      if(pk > n/p) break; // 把 pk*p > n 改成 pk > n/p 防止溢出
      pk *= p;
    }
  }
  printf("%llu\n",ans);

  return 0;
}
