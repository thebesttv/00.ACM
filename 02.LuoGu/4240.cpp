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

const int MAX = 1e5, MAX_ = 1e5 + 20;
const int MOD = 998244353;
int n,m;

int pow_mod(int a, int x){
  int ans = 1;
  while(x){
    if(x&1) ans = 1ll*ans*a%MOD;
    a = 1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}

int rev(int n){
  return pow_mod(n,MOD-2);
}

bool vis[MAX_];
VR<int> prime;
int phi[MAX_], f[MAX_];
void init(){
  phi[1] = 1; f[1] = 1;
  FORR(i,2,n){
    if(!vis[i]){
      prime.push_back(i);
      phi[i] = i-1;
    }
    for(int p : prime){
      int t = p*i;
      if(t>MAX) break;
      vis[t] = 1;
      if(i%p==0){
        phi[t] = p*phi[i];
        break;
      }else{
        phi[t] = (p-1)*phi[i];
      }
    }
    phi[i] = (phi[i-1]+phi[i])%MOD;
    f[i] = (f[i-1] + 1ll*i*rev(phi[i])) % MOD;
  }
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    int ans = 0, i = 1, j;
    while(i<=n){
      j = min(n/(n/i), m/(m/i));
      ans += 1ll*phi[n/i]*phi[m/i]%MOD*(f[j]-f[i-1]+MOD)%MOD;
      i = j+1;
    }
    printf("%d\n",ans);
  }

  return 0;
}
