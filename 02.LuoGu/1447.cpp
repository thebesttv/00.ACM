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

const int MAX = 1e5, MAX_ = 1e5+20;
int n, m;

bool vis[MAX_];
VR<int> prime;
LL phi[MAX_];
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
        phi[t] = p * phi[i];
        break;
      }else{
        phi[t] = phi[p] * phi[i];
      }
    }
  }
  FORR(i,2,MAX) phi[i] += phi[i-1];
}

int main(void){
  init();
  scanf("%d%d",&n,&m);
  if(n>m) swap(n,m);
  LL s = 0;
  int i=1, j;
  while(i<=n){
    j = min(n/(n/i), m/(m/i));
    s += 1ll*(n/i)*(m/i)*(phi[j]-phi[i-1]);
    i = j+1;
  }
  LL ans = 2*s - 1ll*n*m;
  printf("%lld\n",ans);

  return 0;
}

/*
const int MAX = 1e5, MAX_ = 1e5+20;
int n, m;

bool vis[MAX_];
VR<int> prime, d[MAX_];
int mu[MAX_], g[MAX_];
void init(){
  mu[1] = 1;
  FORR(i,1,MAX){
    d[i].push_back(i);
    for(int j=i+i,cnt=2;j<=MAX;j+=i,++cnt){
      d[j].push_back(i);
      mu[j] -= mu[i];
    }
  }
  FORR(i,1,MAX){
    for(int j=i,cnt=1;j<=MAX;j+=i,++cnt)
      g[j] += i*mu[cnt];
    g[i] += g[i-1];
  }
}

int main(void){
  init();
  scanf("%d%d",&n,&m);
  if(n>m) swap(n,m);
  LL s = 0;
  int i=1, j;
  while(i<=n){
    j = min(n/(n/i), m/(m/i));
    s += 1ll*(n/i)*(m/i)*(g[j]-g[i-1]);
    i = j+1;
  }
  LL ans = 2*s - 1ll*n*m;
  printf("%lld\n",ans);

  return 0;
}
*/
