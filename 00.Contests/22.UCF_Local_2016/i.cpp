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

const int MAX = (1<<16)+20;
const int MOD = 1000000007;
int n, dp[MAX][20][2], v[20][2], frac[20];

int f(int st, int last, int o){ // o=0: original orientiation, o=1: flipped
  int &a = dp[st][last][o];
  if(a!=-1) return a;
  a = 0;
  int ost = st & ~(1<<last);
  FOR(i,0,n) if(ost&(1<<i)){
    if(v[i][1] == v[last][o])
      a = (a + f(ost, i, 0))%MOD;
    else if(v[i][0] == v[last][o])
      a = (a + f(ost, i, 1))%MOD;
  }
#ifdef DEBUG
  printf("  f(%d, %d, %d): %d, ost: %d\n",st,last,o,a,ost);
#endif
  return a;
}

bool same(){
  FOR(i,0,n) if(v[i][0]!=v[0][0] || v[i][1]!=v[0][1])
    return false;
  return true;
}

int main(void){
  frac[0]=frac[1]=1;
  FORR(i,2,16) frac[i] = 1ll*frac[i-1]*i%MOD;
  int T; scanf("%d",&T);
  while(T--){
    MST(dp,-1); scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d%d",&v[i][0],&v[i][1]);
      if(v[i][0] > v[i][1])
        swap(v[i][0],v[i][1]);
      dp[1<<i][i][0] = dp[1<<i][i][1] = 1;
    }

    if(same()){
      printf("%d\n",frac[n]);
      continue;
    }

    LL ans = 0;
    FOR(i,0,n)
      ans = (ans + f((1<<n)-1,i,0)
            + (v[i][0]!=v[i][1])*f((1<<n)-1,i,1))%MOD;
    printf("%lld\n",ans);
  }

  return 0;
}




/*
const int MAX = (1<<16)+20;
const int MOD = 1000000007;
int n,f[MAX][7][7]; pii p[20];
VR<int> v[20];

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    if(x&1) ans = ans*a%MOD;
    a = a*a%MOD;
    x>>=1;
  }
  return ans;
}

int rev(int n){
  return pow_mod(n,MOD-2);
}

int main(void){
  int T; scanf("%d",&T);
  FOR(i,0,1<<16){
    int c=0,t=i;
    while(t) c += t&1, t>>=1;
    v[c].push_back(i);
  }

  FORR(kase,1,T){
    scanf("%d",&n);
    MST(f,0);
    FOR(i,0,n){
      scanf("%d%d",&p[i].FI,&p[i].SE);
      if(p[i].FI > p[i].SE) swap(p[i].FI,p[i].SE);
      f[1<<i][p[i].FI][p[i].SE] = f[1<<i][p[i].SE][p[i].FI] = 1;
    }

    bool same = p[0].FI != p[0].SE;
    if(same) FOR(i,1,n) if(p[0]!=p[i]){
      same=0; break;
    }

    FOR(len,1,n) for(int st : v[len]){
      FORR(l,1,6) FORR(r,1,6) if(f[st][l][r]){
        int &a = f[st][l][r];
        FOR(i,0,n) if(!(st&(1<<i))){
          if(p[i].FI==r){
            int &b = f[st|(1<<i)][l][p[i].SE];
            b = (b + a)%MOD;
          }else if(p[i].SE==r){
            int &b = f[st|(1<<i)][l][p[i].FI];
            b = (b + a)%MOD;
          }
        }
      }
    }

    LL ans = 0;
    FORR(i,1,6) FORR(j,1,6)
      ans = (ans + f[(1<<n)-1][i][j])%MOD;
    if(same) ans = ans*rev(2)%MOD;
    printf("%lld\n",ans);
  }

  return 0;
}
*/
