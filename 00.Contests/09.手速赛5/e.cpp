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

const int MAX = 1e5, MAX_ = 1e5 + 20;
int n,cnt[MAX_],mu[MAX_];
bool vis[MAX_];
VR<int> d[MAX_];

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

int coprime(int x){
  int ans = 0;
  for(int i : d[x]){
    ans += mu[i]*cnt[i];
  }
  return ans;
}

void update(int x, int a){
  for(int i : d[x]){
    cnt[i] += a;
  }
}

int main(void){
  FORR(i,1,MAX){
    for(int j=i;j<=MAX;j+=i)
      d[j].push_back(i);
    if(i==1)
      mu[i] = 1;
    else if((i/d[i][1])%d[i][1]==0)
      mu[i] = 0;
    else
      mu[i] = -mu[i/d[i][1]];
  }

  scanf("%d",&n);
  int x; LL ans = 1;
  FOR(i,0,n){
    scanf("%d",&x);
    for(int j : d[x])
      vis[j] = 1;
    ans = max(ans, (LL)x);  // lcm(ai,aj) >= max(ai,aj) 防止a中的数全部一样
  }

  stack<int> st;
  for(int i=MAX;i>=1;--i) if(vis[i]){
    int c = coprime(i);
    while(c){
      if(gcd(i,st.top())==1){
        --c;
        ans = max(ans, 1ll*i*st.top());
      }
      update(st.top(),-1);
      st.pop();
    }
    update(i,1);
    st.push(i);
  }
  printf("%lld\n",ans);

  return 0;
}

/*
const int MAX = 1e5, MAX_ = 1e5 + 20;
int n,cnt[MAX_],mu[MAX_];
bool vis[MAX_];
VR<int> d[MAX_];

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

int coprime(int x){
  int ans = 0;
  for(int i : d[x]){
    ans += mu[i]*cnt[i];
  }
  return ans;
}

void update(int x, int a){
  for(int i : d[x]){
    cnt[i] += a;
  }
}

int main(void){
  FORR(i,1,MAX){
    for(int j=i;j<=MAX;j+=i)
      d[j].push_back(i);
    if(i==1)
      mu[i] = 1;
    else if((i/d[i][1])%d[i][1]==0)
      mu[i] = 0;
    else
      mu[i] = -mu[i/d[i][1]];
  }

  scanf("%d",&n);
  int x; LL ans = 1;
  FOR(i,0,n){
    scanf("%d",&x); vis[x]=1;
    ans = max(ans, (LL)x);  // lcm(ai,aj) >= max(ai,aj) 防止a中的数全部一样
  }

  FORR(g,1,MAX){
    stack<int> st;
    for(int i=MAX/g;i>=1;--i) if(vis[i*g]){
      int c = coprime(i);
      while(c){
        if(gcd(i,st.top())==1){
          --c;
          ans = max(ans, 1ll*i*st.top()*g);
        }
        update(st.top(),-1);
        st.pop();
      }
      update(i,1);
      st.push(i);
    }
    while(!st.empty()){
      update(st.top(),-1);
      st.pop();
    }
  }
  printf("%lld\n",ans);

  return 0;
}
*/
