// Tag: 递推 本原串
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

const int MAX = 5e6 + 10;
const LL MOD = 1e9 + 7;
int a,k; LL f[MAX];

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a=a*a%MOD; x>>=1;
  }
  return ans;
}

int main(void){
  scanf("%d%d",&a,&k);
  f[0] = 1; LL ans = 0;
  FORR(i,1,k) f[i] = f[i-1] * a %MOD;
  FORR(i,1,k){
    for(int j = i+i;j<=k;j+=i)
      f[j] = (f[j] - f[i] +MOD)%MOD;
    ans = (ans + f[i])%MOD;
#ifdef DEBUG
    printf("f[%d]: %lld\n",i,f[i]);
#endif
  }
  printf("%lld\n",ans);

  return 0;
}
/*
   int n,k,r[20];
   VR<VR<int>> v;

   void dfs(int cur, int len){
   if(cur == len){
   v.pb(VR<int>(r,r+len));
   return;
   }
   FOR(i,0,n){
   r[cur] = i; dfs(cur+1, len);
   }
   }

   bool ok(VR<int> &v, int x){
   int idx = x;
   while(idx < v.size()){
   FOR(j,0,x) if(v[idx+j] != v[j]) return false;
   idx += x;
   }
   return true;
   }

   int cal(VR<int> &v){
   FORR(i,1,v.size()) if(v.size() % i == 0){
   if(ok(v, i)) return i;
   }
   return -1;
   }

   int main(void){
   scanf("%d%d",&n,&k);
   FORR(i,1,k) dfs(0,i);
   int ans = 0;
   for(auto &p : v){
   if(cal(p) == p.size()){
#ifdef DEBUG
for(int x : p) printf("%d ",x); putchar('\n');
#endif
++ans;
}
}
printf("%d\n",ans);

return 0;
}
 */
