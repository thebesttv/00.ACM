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

const int MAX = 1e5, MAX_ = MAX+20;
const int MAXQ = 2e4 + 20;

struct Query{
  int n,m,a,no;
  bool operator < (const Query &b) const {
    return a < b.a;
  }
}Q[MAXQ];
unsigned ans[MAXQ];

struct F{
  int i, v;
  bool operator < (const F &b) const {
    return v < b.v;
  }
}f[MAX_];

bool vis[MAX_];
int mu[MAX_], tf[MAX_];
VR<int> prime;
void init(){
  mu[1] = 1; tf[1] = 1; f[1] = {1,1};
  FORR(i,2,MAX){
    f[i].i = i;
    if(!vis[i]){
      prime.push_back(i);
      mu[i] = -1;
      tf[i] = i;
      f[i].v = i + 1;
    }
    for(int p : prime){
      int t = p*i;
      if(t>MAX) break;
      vis[t] = 1;
      if(i%p==0){
        mu[t] = 0;
        tf[t] = p * tf[i];
        f[t].v = f[i].v + tf[t]*f[t/tf[t]].v;
        break;
      }else{
        mu[t] = -mu[i];
        tf[t] = p;
        f[t].v = f[i].v*(p+1);
      }
    }
  }
#ifdef DEBUG
  FORR(i,2,100) printf("f[%d]: %d\n",i,f[i].v);
#endif
  /*
  FORR(i,1,MAX){
    f[i].i = i;
    for(int j=i;j<=MAX;j+=i)
      f[j].v += i;
  }
  */
  sort(f+1,f+1+MAX);
}

struct G{
  int v[MAX_], n;
  void add(int x, int a){
    while(x<=n){
      v[x]+=a; x += x&-x;
    }
  }
  void addF(int i, int a){
    for(int j=i,cnt=1;j<=n;j+=i,++cnt){
      add(j, a*mu[cnt]);
    }
  }
  int sum(int x){
    int s = 0;
    while(x){
      s += v[x]; x -= x&-x;
    }
    return s;
  }
  int sum(int l, int r){
    return sum(r) - sum(l-1);
  }
}g;

int main(void){
  init(); g.n = MAX;
  int T; scanf("%d",&T);
  int n,m,a;
  FOR(i,0,T){
    scanf("%d%d%d",&n,&m,&a);
    Q[i] = {min(n,m),max(n,m),a};
    Q[i].no = i;
  }
  sort(Q,Q+T);

  int p = 1;
  FOR(k,0,T){
    n = Q[k].n, m = Q[k].m, a = Q[k].a;
    while(p<=MAX && f[p].v <= a){
      g.addF(f[p].i, f[p].v);
      ++p;
    }
    int i = 1, j, s = 0;
    while(i<=n){
      j = min(n/(n/i),m/(m/i));
      s += (n/i)*(m/i)*g.sum(i,j);
      i = j + 1;
    }
    unsigned int t = s;
    ans[Q[k].no] = (t<<1)>>1;
  }
  FOR(i,0,T) printf("%u\n",ans[i]);

  return 0;
}
