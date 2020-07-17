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
const LL MOD = 1e9 + 7;
int n,m;

LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    if(x&1) ans = ans * a % MOD;
    a = a * a % MOD;
    x >>= 1;
  }
  return ans;
}
LL rev(LL x){
  return pow_mod(x, MOD-2);
}

struct Node{
  int l, r, n, ans;
  VR<int> v, sum, pos, prod; // sum/pos of negative
  void set(int l, int r, const VR<int> &v){
    this->l = l;
    this->r = r;
    this->v = v;
  }
  bool operator < (const Node &b) const {
    return r < b.r;
  }

  void init(){
    n = v.size();
    sum.resize(n); pos.resize(n); prod.resize(n);

    if(v[0] < 0){
      sum[0] = 1;
      pos.push_back(0);
      v[0] += MOD;
    } else sum[0] = 0;
    prod[0] = v[0];

    FOR(i,1,n){
      if(v[i] < 0){
        sum[i] = sum[i-1] + 1;
        pos.push_back(i);
        v[i] += MOD;
      } else sum[i] = sum[i-1];

      prod[i] = 1ll * prod[i-1] * v[i] % MOD;
    }

    if(sum.back() & 1){ // odd
      ans = 0;
      if(pos.front() < n-1)
        ans = max(1ll*ans, 1ll*prod.back() * rev(prod[pos.front()]) % MOD);
      if(pos.back() > 0)
        ans = max(ans, prod[pos.back()-1]);
    }else{  // even
      ans = prod.back();
    }
  }

  int solve(int ql, int qr){  // [ql, qr] -> [ql-l, qr-l]
    ql -= l, qr -= l;
    int s = sum[qr] - (!ql ? 0 : sum[ql-1]);
    if(s & 1){
      int ansMax = 0;
      int nl = lower_bound(ALL(pos), ql) - pos.begin(); // negative left
      int nr = lower_bound(ALL(pos), qr) - pos.begin(); // negative right
      if(nr == pos.size() || pos[nr] > qr) --nr;
      if(nl < qr)
        ansMax = max(1ll*ansMax, 1ll*prod[qr] * rev(prod[nl]) % MOD);
      if(nr > ql)
        ansMax = max(1ll*ansMax, 1ll*prod[nr-1] * (!ql ? 1 : rev(prod[ql-1])) % MOD);
      return ansMax;
    }else{
      return 1ll * prod[qr] * (!ql ? 1 : rev(prod[ql-1])) % MOD;
    }
  }
}node[MAX];

int find(int x){
  static Node t; t.r = x;
  return lower_bound(node, node+n, t) - node;
}

struct ST{
  int f[MAX][18];
  void build(){
    FORR(i,1,n) f[i][0] = node[i-1].ans;
    ROR(i,n,1) for(int j=1;i+(1<<j)-1<=n;j++)
      f[i][j] = max( f[i][j-1], f[i+(1<<(j-1))][j-1] );
  }
  int qMax(int l, int r){
    ++l, ++r;
    int k=log(r-l+1)/log(2);
    return max( f[l][k], f[r-(1<<k)+1][k] );
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  int tail = 0, x, l=1; VR<int> v;
  FORR(i,1,n){
    scanf("%d",&x);
    if(!x){
      if(v.size()){
        node[tail++].set(l, i-1, v);
        v.clear();
      }
      l = i+1;
    } else v.push_back(x);
  }
  if(v.size()){
    node[tail++].set(l, n, v);
    v.clear();
  }
  n = tail;

#ifdef DEBUG
  FOR(i,0,n){
    printf("%d: node [%d, %d]:",i,node[i].l,node[i].r);
    for(int x : node[i].v) printf(" %d",x); putchar('\n');
  }
#endif
  FOR(i,0,n) node[i].init(); sg.build();
#ifdef DEBUG
  FOR(i,0,n) printf("node %d: %d\n",i,node[i].ans);
#endif

  while(m--){
    int l, r; scanf("%d%d",&l,&r);
    if(n == 0) { printf("0\n"); continue; }

    int nl = find(l), nr = find(r);
    if(nl == n) { printf("0\n"); continue; }
    else l = max(l, node[nl].l);  // throw away 0

    if(nr == n || r < node[nr].l) --nr, r = node[nr].r;

    int ml = node[nl].l == l ? nl : nl+1;
    int mr = node[nr].r == r ? nr : nr-1;
    int ansMax = ml <= mr ? sg.qMax(ml, mr) : 0;

    if(ml != nl) ansMax = max(ansMax, node[nl].solve(l, node[nl].r));
    if(mr != nr) ansMax = max(ansMax, node[nr].solve(node[nr].l, r));
    printf("%d\n",ansMax);
  }

  return 0;
}
