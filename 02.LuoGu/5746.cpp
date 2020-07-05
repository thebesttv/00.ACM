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

const int MAX = 10000, MAX_ = MAX+20, MAXK = 1020;
const int MOD = 1e4;
int n, e2=0, f[MAXK][MAXK], s[MAXK][MAXK];
VR<pii> v;

int phi[MAX_];
VR<int> prime;
bool vis[MAX_];
void init(){
  phi[1] = 1;
  FORR(i,2,MAX){
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
        phi[t] = phi[i]*phi[p];
      }
    }
  }
}

int pow_mod(int a, int x){
  int ans = 1;
  while(x){
    if(x&1) ans = 1ll*ans*a%MOD;
    a = 1ll*a*a%MOD;
    x>>=1;
  }
  return ans;
}

int main(void){
  init(); v.push_back({1,0});
  scanf("%d",&n);
  FOR(i,0,n){
    pii t; scanf("%d%d",&t.FI,&t.SE);
    if(t.FI==2) e2 = t.SE;
    else v.push_back(t);
  }
  n = v.size() - 1;
  int ans0=0, ans1=0;
  FORR(i,1,n){
    f[i][1] = phi[v[i].FI];
    s[i][1] = (s[i-1][1] + f[i][1])%MOD;
    ans1 = (ans1 + f[i][1])%MOD;
    FORR(j,2,i){
      f[i][j] = 1ll*s[i-1][j-1]*phi[v[i].FI]%MOD;
      s[i][j] = (s[i-1][j]+f[i][j])%MOD;
      if(j&1) ans1 = (ans1 + f[i][j])%MOD;
      else    ans0 = (ans0 + f[i][j])%MOD;
    }
  }
#ifdef DEBUG
  FORR(i,1,n) FORR(j,1,i)
    printf("  f[%d][%d]: %d\n",i,j,f[i][j]);
#endif
  if(e2) v.push_back({2,e2});
  int m = 1;
  for(auto p : v)
    m = 1ll*m*pow_mod(p.FI,p.SE)%MOD;
  int ans2 = ( (m-1-ans0-ans1)%MOD + MOD )%MOD;
  printf("%d\n%d\n%d\n",ans0,ans1,ans2);

  return 0;
}
