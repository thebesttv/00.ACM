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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1000;
const int MOD = 10056;
int n,f[MAX+20];
int C[MAX+20][MAX+20];

int main(void){

  C[1][0] = C[1][1] = 1;
  f[0] = f[1] = 1;
  FORR(i,2,MAX){
    C[i][0] = 1;
    FORR(k,1,i){
      C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;
      f[i] = (f[i] + C[i][k]*f[i-k]%MOD)%MOD;
    }
  }

  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    printf("Case %d: %d\n",kase,f[n]);
  }

  return 0;
}

/*
const int MAX = 1000;
const int MOD = 10056;
int n,f[MAX+20]; bool vis[MAX+20];
VR<int> prime; int cnt[MAX];
int C[MAX+20][MAX+20];

void add(int n, int d){
  FOR(i,0,prime.size()) if(n%prime[i]==0){
    while(n%prime[i]==0){
      n/=prime[i], cnt[i]+=d;
    }
    if(n==1) return;
  }
}

int pow(int a, int b){
  if(!b) return 1;
  LL ans = pow(a,b/2);
  ans = ans * ans % MOD;
  if(b&1) ans = ans * a % MOD;
  return ans;
}

int get(){
  LL ans = 1;
  FOR(i,0,prime.size()) if(cnt[i])
    ans = ans * pow(prime[i],cnt[i]) % MOD;
  return ans;
}

int main(void){
  FORR(i,2,MAX) if(!vis[i]){
    prime.push_back(i);
    for(int j=i*i;j<=MAX;j+=i) vis[j]=1;
  }

  C[1][0] = C[1][1] = 1;
  FORR(i,2,MAX){
    C[i][0] = 1;
    FORR(k,1,i){
      add(i-k+1,1); add(k,-1);
      C[i][k] = get();
#ifdef DEBUG
    printf("  c[%d][%d]: %d\n",i,k,C[i][k]);
#endif
    }
  }

  f[0] = f[1] = 1;
  FORR(i,2,MAX){
    FORR(k,1,i)
      f[i] = (f[i] + C[i][k]*f[i-k]%MOD)%MOD;
  }

  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    printf("Case %d: %d\n",kase,f[n]);
  }

  return 0;
}
*/
