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
typedef pair<LL,int> pii;

const int MAX = 1e7, MAX_ = MAX+20;
int n, m;

bool vis[MAX_];
VR<int> prime;
int a[MAX_], b[MAX_], f[MAX_], g[MAX_];
void init(){
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
      f[i] = 1;
      a[i] = 1, b[i] = i;
    }
    FOR(j,0,prime.size()){
      int p = prime[j], t = p * i;
      if(t>MAX) break;
      vis[t] = 1;
      if(i%p==0){
        a[t] = a[i] + 1, b[t] = b[i] * p;
        if(b[t]==t) f[t] = 1;
        else f[t] = (a[t] == a[t/b[t]] ? -f[t/b[t]] : 0);
        break;
      }else{
        a[t] = 1, b[t] = p;
        f[t] = (a[i]==1 ? -f[i] : 0);
      }
    }
    g[i] = g[i-1] + f[i];
  }
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    LL ans = 0;
    int i=1, j;
    while(i<=n){
      j = min(n/(n/i), m/(m/i));
      ans += 1ll*(n/i)*(m/i)*(g[j]-g[i-1]);
      i = j+1;
    }
    printf("%lld\n",ans);
  }

  return 0;
}

/*
const int MAX = 1e7, MAX_ = MAX+20;
int n, m;

bool vis[MAX_];
VR<int> prime;
int f[MAX_], g[MAX_];

struct Node{
  LL n; int cnt, u;
};
queue<Node> q;

void mark(Node n){
  LL t = n.n;
  while(t<=MAX){
    g[t] = n.cnt&1 ? 1 : -1;
    t *= n.n;
  }
}

void init(){
  FORR(i,2,MAX){
    if(!vis[i]){
      prime.push_back(i);
    }
    FOR(j,0,prime.size()){
      int t = prime[j] * i;
      if(t>MAX) break;
      vis[t] = 1;
      if(i%prime[j]==0) break;
    }
  }

  q.push({1,0,0});
  while(!q.empty()){
    Node t = q.front(); q.pop();
    FOR(i,t.u,prime.size()){
      LL tn = t.n * prime[i];
      if(tn>MAX) break;
      Node newN{tn, t.cnt+1, i+1};
      q.push(newN);
      mark(newN);
    }
  }
  FORR(i,2,MAX) g[i] += g[i-1];
}

int main(void){
  init();
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    LL ans = 0;
    int i=1, j;
    while(i<=n){
      j = min(n/(n/i), m/(m/i));
      ans += 1ll*(n/i)*(m/i)*(g[j]-g[i-1]);
      i = j+1;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
*/
