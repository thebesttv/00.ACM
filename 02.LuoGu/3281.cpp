// Tag: iii 数位DP 坑
// 尼玛的取模
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

const int MAX = 1e5 + 20;
const LL MOD = 20130427;
int b,n,v[MAX];
LL powb[MAX],sumb[MAX],g[MAX];

void sub(){
  ROR(i,n,1){
    if(--v[i] >= 0) break;
    v[i] += b;
  }
  if(n > 1 && v[1]==0){
    FORR(i,2,n) v[i-1] = v[i]; --n;
  }
}

struct Node{
  LL cnt,sum,lsum;
  Node() { cnt = sum = lsum = 0; }
  Node(LL cnt) : cnt(cnt) { sum = lsum = 0; }
  void add(const Node &b, LL i, LL cur){
    cnt = (cnt + b.cnt)%MOD;
    lsum = (lsum + b.lsum + b.cnt * i %MOD * sumb[cur] %MOD)%MOD;
    sum = (sum + b.sum + b.lsum + b.cnt * i %MOD * sumb[cur] %MOD)%MOD;
  }
  void mul(const Node &b, LL l, LL r, LL cur){
    LL len = (r - l + 1); LL sb = 1ll*(r+l)*len/2 % MOD; len %= MOD;
    cnt = (cnt + b.cnt * len)%MOD;
    lsum = (lsum + b.lsum * len %MOD + b.cnt * sb %MOD * sumb[cur]%MOD)%MOD;
    sum = (sum + (b.sum + b.lsum) * len %MOD + b.cnt * sb %MOD * sumb[cur]%MOD)%MOD;
  }
}f[MAX][2];

Node dfs(int cur, bool limited, bool lead){
  if(!cur) return Node(1);
  Node &a = f[cur][lead];
  if(!limited && a.cnt!=-1) return a;
  Node p;

  // dfs的值只与 limited 和 lead 有关，将 O(NB) 优化为 O(N)
  int l = lead ? 1 : 0, r = limited ? v[cur]-1 : b-1;
  if(lead){
    Node t = dfs(cur-1, limited && v[cur]==0, true);
    p.sum = (p.sum + t.sum)%MOD;
  }
  if(limited && !(lead && v[cur]==0)){
    Node t = dfs(cur-1, true, false);
    p.add(t,v[cur],cur);
  }
  if(l <= r){
    Node t = dfs(cur-1, false, false);
    p.mul(t, l, r, cur);
  }

  /*
  // O(NB)
  int l=0,r = limited ? v[cur] : b-1;
  FORR(i,0,r){
    Node t = dfs(cur-1, limited && i==r, lead && !i);
    if(!lead || i) p.add(t,i,cur);
    else p.sum = (p.sum + t.sum)%MOD;
  }
  */

  if(!limited) a = p;
#ifdef DEBUG
  printf("dfs(%d, %d, %d) [%d, %d], cnt: %lld, lsum: %lld, sum: %lld\n",
      cur,limited,lead,l,r,p.cnt,p.lsum,p.sum);
#endif
  return p;
}

LL solve(bool isL){
  scanf("%d",&n); FORR(i,1,n) scanf("%d",&v[i]);
  if(n==1 && v[1] == 0) return 0;

  if(isL) sub();
  reverse(v+1,v+1+n);

  MST(f,-1);
  LL ans = dfs(n,true,true).sum;
  return ans;
}

int main(void){
  scanf("%d",&b); powb[0] = 1;
  FOR(i,1,MAX){
    powb[i] = powb[i-1]*b%MOD;
    sumb[i] = (sumb[i-1] + powb[i-1])%MOD;
  }

  LL l = solve(true);
  LL r = solve(false);
  printf("%lld\n",(r-l+MOD)%MOD);

  return 0;
}
