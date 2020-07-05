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

const int MAX = 50000, MAX_ = MAX+20;
int n,m;

int mu[MAX_], d[MAX_];
bool vis[MAX_];
VR<int> prime;
void init(){
  /*
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
  */

  mu[1] = 1;
  FORR(i,1,MAX){
    ++d[i];
    for(int j=i+i;j<=MAX;j+=i){
      ++d[j];
      mu[j] -= mu[i];
    }
    d[i] += d[i-1];
    mu[i] += mu[i-1];
  }
}

LL f(int n, int m){
  return 1ll*d[n]*d[m];
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    int i = 1, j; LL ans = 0;
    while(i<=n){
      j = min(n/(n/i),m/(m/i));
      ans += f(n/i, m/i) * (mu[j]-mu[i-1]);
      i = j+1;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
