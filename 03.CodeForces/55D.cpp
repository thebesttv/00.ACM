// Tag: 
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MOD = 2520;
int v[20]; LL l,r,f[20][MOD+4][50];
int mp[50],pos[MOD+4],vlcm[50][10];

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}
int lcm(int a, int b){
  return a/gcd(a,b)*b;
}

LL dfs(int cur, int sum, int div, bool limited){
  if(!cur) return sum%mp[div] == 0;
  LL &a = f[cur][sum][div];
  if(!limited && a!=-1) return a;
  LL ans = 0; int r = limited ? v[cur] : 9;
  FORR(i,0,r){
    //ans += dfs(cur-1, (sum*10+i)%MOD, pos[lcm(mp[div],max(i, 1))], limited && i==r);
    ans += dfs(cur-1, (sum*10+i)%MOD, vlcm[div][i], limited && i==r);
  }

  if(!limited) a = ans;
  return ans;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len]=x%10,x/=10;
  return dfs(len, 0, pos[1], true);
}

int main(void){
  MST(f,-1); int tail = 0;
  FORR(i,1,MOD) if(MOD%i==0)
    mp[tail] = i, pos[i] = tail++;
  FOR(i,0,tail) FORR(j,0,9){
    vlcm[i][j] = pos[lcm(mp[i],max(j,1))];
  }

  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",solve(r)-solve(l-1));
  }

  return 0;
}
