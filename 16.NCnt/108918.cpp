// Tag: 数位DP
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

LL l,r,f[20][2600][50];
int v[20], mp[2600], vec[50];

int lcm(int a, int b) { return a/__gcd(a,b)*b; }

void init(){
  set<int> st;
  FOR(s,1,1<<9){
    int l = 1;
    FOR(j,0,9) if(s&(1<<j)) l = lcm(l, j+1);
    st.insert(l);
  }
  int tail = 0;
  for(int x : st){
    mp[x] = tail; vec[tail++] = x;
  }
#ifdef DEBUG
  printf("%d in total\n",(int)st.size());
#endif
}

LL dfs(int cur, int sum, int lcm, bool limited){
  if(!cur) return sum%vec[lcm] == 0;
  LL &a = f[cur][sum][lcm];
  if(!limited && a!=-1) return a;
  int r = limited ? v[cur] : 9; LL ans = 0;
  FORR(i,0,r){
    ans += dfs(cur-1, (sum*10+i)%2520, i ? mp[::lcm(vec[lcm], i)] : lcm, limited && i==r);
  }
  if(!limited) a = ans;
  return ans;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len]=x%10, x/=10;
  return dfs(len, 0, 0, true);
}

int main(void){
  init(); MST(f,-1);
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",solve(r)-solve(l-1));
  }

  return 0;
}
