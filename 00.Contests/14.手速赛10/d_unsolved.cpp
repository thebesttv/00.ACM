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

const int MAX = 1e5, MAX_ = MAX+20;
const int MOD = 1e9+7;
int n,q; char s[MAX_];
int frac[MAX_], rfrac[MAX_];
int cnt[128];
bool no[128];

int pow_mod(int a, int x){
  int ans=1;
  while(x){
    if(x&1) ans=1ll*ans*a%MOD;
    a=1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}
int rev(int n){
  return pow_mod(n,MOD-2);
}
int C(int n, int m){
  if(n<m) return 0;
  return 1ll*frac[n]*rfrac[m]%MOD*rfrac[n-m]%MOD;
}

int main(void){
  frac[0]=rfrac[0]=frac[1]=rfrac[1] = 1;
  FORR(i,2,MAX){
    frac[i] = 1ll*frac[i-1]*i%MOD;
    rfrac[i] = rev(frac[i]);
  }

  scanf("%s%d",s+1,&q);
  n = strlen(s+1);
  FORR(i,1,n) ++cnt[s[i]];

  while(q--){
    int x,y; scanf("%d%d",&x,&y);
    x = s[x], y = s[y];
    int ans=0;
    if(x==y){
      if(cnt[x]*2>n) ans=0;
      else{
        ans = C(n/2, cnt[x]);
        no[x] = 1;
        int t = n-cnt[x];

        FORR(i,'a','z') if(cnt[i] && !no[i]){
          ans = 1ll*ans*C(t,cnt[i])%MOD;
          t -= cnt[i];
        }
        FORR(i,'A','Z') if(cnt[i] && !no[i]){
          ans = 1ll*ans*C(t,cnt[i])%MOD;
          t -= cnt[i];
        }
        no[x] = 0;
      }
    }else{
      if((cnt[x]+cnt[y])*2>n) ans=0;
      else{
        ans = 1ll*C(n/2, cnt[x])*C(n/2-cnt[x], cnt[y])%MOD;
        int t = n-cnt[x]-cnt[y];
        no[x]=no[y]=1;

        FORR(i,'a','z') if(cnt[i] && !no[i]){
          ans = 1ll*ans*C(t,cnt[i])%MOD;
          t -= cnt[i];
        }
        FORR(i,'A','Z') if(cnt[i] && !no[i]){
          ans = 1ll*ans*C(t,cnt[i])%MOD;
          t -= cnt[i];
        }
        no[x]=no[y]=0;
      }
    }
    ans = ans*2ll%MOD;
    printf("%d\n",ans);
  }

  return 0;
}
