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

const int MAX = 1e6, MAX_ = 1e6 + 20;
int n,m,k;

bool vis[MAX_];
VR<int> prime;
int mu[MAX_];
void init(){
  mu[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      mu[i] = -1;
    }
    for(int p : prime){
      int t = p*i;
      if(t>MAX) break;
      vis[t] = 1;
      if(i%p==0){
        mu[t] = 0;
        break;
      }else{
        mu[t] = -mu[i];
      }
    }
    mu[i] += mu[i-1];
  }
}

int main(void){
  init();
  scanf("%d%d%d",&n,&m,&k); n/=k, m/=k;
  if(n>m) swap(n,m);
  LL ans = 0; int i=1,j;
  while(i<=n){
    j = min(n/(n/i), m/(m/i));
    ans += 1ll*(n/i)*(m/i)*(mu[j]-mu[i-1]);
    i = j+1;
  }
  printf("%lld\n",ans);

  return 0;
}
