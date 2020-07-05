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

const int MAX = 5e4;
int a,b,c,d,k;

int mu[MAX+20];
VR<int> prime;
bool vis[MAX+20];
void init(){
  mu[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      mu[i] = -1;
    }
    for(int p : prime){
      int t = p * i;
      if(t > MAX) break;
      vis[t] = 1;
      if(i % p == 0){
        mu[t] = 0;
        break;
      }else{
        mu[t] = -mu[i];
      }
    }
    mu[i] += mu[i-1];
  }
}

LL A(int n, int m){
  LL ans = 0;
  int i = 1, j;
  n/=k, m/=k;
  if(n > m) swap(n,m);
  while(i<=n){
    j = min( n / (n/i), m / (m/i) );
    ans += 1ll*(mu[j]-mu[i-1])*(n/i)*(m/i);
    i = j+1;
  }
  return ans;
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    LL ans = A(b,d) - A(a-1,d) - A(b,c-1) + A(a-1,c-1);
    printf("%lld\n",ans);
  }

  return 0;
}
