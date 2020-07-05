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

const int MAX=1000*1000+20, MAXT=10020;
LLU a, b; int n;
int f[MAX];
typedef pair<int,int> pii;
set<pii> st;

struct Que{
  LLU a,b; int n, num;
  bool operator < (const Que &b) const {
    return n < b.n;
  }
}Q[MAXT];
int ans[MAXT];

LLU pow(LLU a, LLU b, LLU MOD){ // a^b % MOD
  if(!b) return 1;
  if(b==1) return a%MOD;
  LLU ans = pow(a,b/2,MOD);
  ans = ans * ans % MOD;
  if(b&1) ans = ans * a % MOD;
  return ans;
}

int main(void){
  int T; cin>> T;
  FOR(i,0,T){
    cin >> a >> b >> n;
    Q[i] = Que{a,b,n,i};
  }
  sort(Q,Q+T);

  int i = 0;
  while(i<T){
    int j = i+1;
    while(j<T && Q[j].n==Q[i].n) j++;
    
    n = Q[i].n;

    if(n==1){
      FOR(k,i,j) ans[Q[i].num]=0;
      i = j; continue;
    }

    st.clear();
    f[1]=f[2]=1;
    st.insert({1,1});
    int p = 3, m = -1;
    while(true){
      f[p] = (f[p-1]+f[p-2])%n;
      pii t {f[p-1],f[p]};
      if(st.find(t)!=st.end()){
        m = p-2; break;
      }
      st.insert(t);
      p++;
    }

    FOR(k,i,j){
      a = Q[k].a, b = Q[k].b;
      int idx = pow(a%m,b,m);
      if(!idx) idx = m;
      ans[Q[k].num] = f[idx];
    }

    i = j;
  }
  FOR(i,0,T) cout << ans[i] << endl;

  return 0;
}

/*
const int MAX=1000*1000+20;
LLU a, b; int n;
int f[MAX];
typedef pair<int,int> pii;
set<pii> st;

LLU pow(LLU a, LLU b, LLU MOD){ // a^b % MOD
  if(!b) return 1;
  if(b==1) return a%MOD;
  LLU ans = pow(a,b/2,MOD);
  ans = ans * ans % MOD;
  if(b&1) ans = ans * a % MOD;
  return ans;
}

int main(void){
  int T; cin>> T;
  while(T--){
    st.clear();
    cin >> a >> b >> n;
    if(n==1){
      cout << 0 << endl;
      continue;
    }

    f[1]=f[2]=1;
    st.insert({1,1});
    int i = 3, m = -1;
    while(true){
      f[i] = (f[i-1]+f[i-2])%n;
      pii t {f[i-1],f[i]};
      if(st.find(t)!=st.end()){
        m = i-2; break;
      }
      st.insert(t);
      i++;
    }

    int idx = pow(a%m,b,m);
    if(!idx) idx = m;
#ifdef DEBUG
    cout << "m: " << m << ", idx: " << idx <<  endl;
#endif
    cout << f[idx] << endl;
  }

  return 0;
}
*/
