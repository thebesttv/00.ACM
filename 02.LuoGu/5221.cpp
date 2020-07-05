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

const int MAX = 1e6, MAX_ = MAX+20;
const int MOD = 104857601;
int n;

int pow_mod(int a, LL x){
  int ans = 1;
  while(x){
    if(x&1) ans = 1ll*ans*a%MOD;
    a=1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}

int rev(int n){
  return pow_mod(n,MOD-2);
}

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

bool vis[MAX_];
VR<int> prime;
int f[MAX_];
void init(){
  f[1] = f[0] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      f[i] = rev(i);
    }
    for(int p : prime){
      int t = p*i;
      if(t>MAX) break;
      vis[t] = 1;
      if(i%p==0){
        f[t] = f[i];
        break;
      }else{
        f[t] = 1;
      }
    }
  }
  FORR(i,1,MAX) f[i] = 1ll*f[i-1]*f[i]%MOD;
}

int main(void){
  init();
  scanf("%d",&n);

  int ans = 1;
  FORR(i,2,n) ans = 1ll*ans*i%MOD;
  ans = pow_mod(ans, 2*n);

  int i=1, j;
  while(i<=n){
    j = n/(n/i);
    int t = 1ll*f[j]*rev(f[i-1])%MOD;
    ans = 1ll*ans * pow_mod(t, 2ll*(n/i)*(n/i))%MOD;
    i = j+1;
  }
  printf("%d\n",ans);

  return 0;
}
