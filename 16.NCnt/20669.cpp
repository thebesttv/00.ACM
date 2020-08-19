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

const int MOD = 20020219;
int occ[10],v[20],n,f[20][10][20]; LL l,r;

int dfs(int cur, int last, int cnt, bool limited){
  if(!cur) return 1;
  int &a = f[cur][last][cnt];
  if(!limited && a!=-1) return a;
  int sum = 0, r = limited ? v[cur] : 9;
  FORR(i,0,r)
    if(i == last){
      if(cnt + 1 <= occ[i]) sum = (sum + dfs(cur-1, last, cnt+1, limited && i==r))%MOD;
    }else{
      sum = (sum + dfs(cur-1, i, 1, limited && i==r))%MOD;
    }
  if(!limited) a = sum;
  return sum;
}

int solve(LL x){
  int len = 0;
  while(x) v[++len]=x%10,x/=10;
  MST(f,-1);
  return dfs(len, 0, 0, true);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%d",&l,&r,&n); MST(occ,0x3f);
    while(n--){
      int x, c; scanf("%d%d",&x,&c);
      occ[x] = min(occ[x], c);
    }
    printf("%d\n",(solve(r) - solve(l-1) + MOD)%MOD);
  }

  return 0;
}
