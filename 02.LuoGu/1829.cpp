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

const int MAX = 1e7, MAX_ = MAX+20;
const int MOD = 20101009;
int n,m;

bool vis[MAX_];
VR<int> prime;
int mu[MAX_],h[MAX_],g[MAX_];
void init(){
  mu[1] = 1, h[1] = 1, g[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      mu[i] = -1;
      h[i] = 1 - i;
    }
    for(int p : prime){
      int t = p*i;
      if(t>MAX) break;
      vis[t] = 1;
      if(i%p==0){
        mu[t] = 0;
        h[t] = h[i];
        break;
      }else{
        mu[t] = -mu[i];
        h[t] = h[i]*(1ll-p)%MOD;
      }
    }
    g[i] = ( g[i-1] + 1ll*i*h[i]%MOD + MOD)%MOD;
  }
}

int main(void){
  init();
  while(scanf("%d%d",&n,&m)==2){
    if(n>m) swap(n,m);
    int i = 1, j, ans=0, t1, t2;
    while(i<=n){
      t1 = n/i, t2 = m/i;
      j = min(n/t1, m/t2);
      ans = ( ans + ( (t1+1ll)*t1/2 % MOD)
          *( (t2+1ll)*t2/2 %MOD) %MOD
          * (g[j]-g[i-1]+MOD)%MOD ) %MOD;
      i = j+1;
    }
    printf("%d\n",ans);
  }

  return 0;
}
