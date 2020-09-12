// Tag: 线段树 DP iiii why
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

const int MAX = 3e5 + 20;
int n,m; LL f[MAX],b[MAX],w[MAX];
struct Node { int l,t,c; };
VR<Node> v[MAX];

struct ST{
  int n; LL v[MAX<<2], av[MAX<<2];
  void build(int n){
    this->n = n; build(1,1,n);
  }
  void build(int u, int l, int r){
    v[u] = LLONG_MIN;
    if(l == r) return;
    int m = (l+r)/2;
    build(u<<1, l, m);
    build(u<<1|1, m+1, r);
  }
  void pushdown(int u, int l, int r){
    int m = (l+r)/2;
    if(av[u]){
      v[u<<1] += av[u];
      v[u<<1|1] += av[u];
      av[u<<1] += av[u];
      av[u<<1|1] += av[u];
      av[u] = 0;
    }
  }
  void add(int l, int r, LL v) { add(1,1,n,l,r,v); }
  void add(int u, int cl, int cr, int ql, int qr, LL val){
    if(ql <= cl && cr <= qr){
      av[u] += val; v[u] += val; return;
    }
    pushdown(u, cl, cr);
    int m = (cl + cr)/2;
    if(ql <= m) add(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) add(u<<1|1, m+1, cr, ql, qr, val);
    v[u] = max(v[u<<1], v[u<<1|1]);
  }
  LL qMax() { return qMax(1,1,n,1,n); }
  LL qMax(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return v[u];
    pushdown(u, cl, cr);
    int m = (cl+cr)/2; LL ans = LLONG_MIN;
    if(ql <= m) ans = max(ans, qMax(u<<1,cl,m,ql,qr));
    if(m+1 <= qr) ans = max(ans, qMax(u<<1|1,m+1,cr,ql,qr));
    return ans;
  }
  void set(int p, LL x) { set(1,1,n,p,x); }
  void set(int u, int l, int r, int p, LL val){
    if(l == r) { v[u] = val; return; }
    pushdown(u, l, r);
    int m = (l+r)/2;
    if(p <= m) set(u<<1, l, m, p, val);
    else set(u<<1|1, m+1, r, p, val);
    v[u] = max(v[u<<1], v[u<<1|1]);
  }
}sgb,sgw;

int main(void){
  scanf("%d%d",&n,&m);
  sgb.build(n+1), sgw.build(n+1);
  FORR(i,1,n) scanf("%lld",&b[i]), b[i] += b[i-1];
  FORR(i,1,n) scanf("%lld",&w[i]), w[i] += w[i-1];
  while(m--){
    int l,r,t,c;
    scanf("%d%d%d%d",&t,&l,&r,&c);
    v[r].pb(Node{l,t,c});
  }

  sgb.set(1,0), sgw.set(1,0);
  FORR(i,1,n){
    for(auto &p : v[i])
      if(p.t == 1) sgb.add(1,p.l,p.c);
      else sgw.add(1,p.l,p.c);

    f[i] = max(sgb.qMax() + b[i], sgw.qMax() + w[i]);

    sgb.set(i+1, f[i]-b[i]);
    sgw.set(i+1, f[i]-w[i]);
#ifdef DEBUG
    printf("f[%d]: %lld\n",i,f[i]);
#endif
  }
  printf("%lld\n",f[n]);

  return 0;
}
