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
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<LL,LL> pii;

const int MAX = 100020;
int n,m,a[MAX];
struct ST{
  LL v[MAX<<2], wv[MAX<<2], av[MAX<<2];

  void pushdown(int u, int l, int r, int m){
    if(av[u]){
      v[u<<1] += av[u] * (m-l+1);
      v[u<<1|1] += av[u] * (r-m);
      wv[u<<1] += av[u] * (l + m) * (m-l+1) / 2;
      wv[u<<1|1] += av[u] * (m+1+r) * (r-m) / 2;
      av[u<<1] += av[u];
      av[u<<1|1] += av[u];
      av[u] = 0;
    }
  }
  void pushup(int u){
    v[u] = v[u<<1] + v[u<<1|1];
    wv[u] = wv[u<<1] + wv[u<<1|1];
  }
  void build(int *a, int n){
    build(1,1,n,a);
  }
  void build(int u, int l, int r, int *a){
    if(l == r) { v[u] = a[l]; wv[u] = l * a[l]; return; }
    int m = (l+r)/2;
    build(u<<1,l,m,a);
    build(u<<1|1,m+1,r,a);
    pushup(u);
  }

  void add(int l, int r, LL val){
    add(1,1,n,l,r,val);
  }
  void add(int u, int cl, int cr, int ql, int qr, LL val){
    if(ql <= cl && cr <= qr){
      v[u] += val * (cr-cl+1);
      wv[u] += val * (cl+cr) * (cr-cl+1) / 2;
      av[u] += val;
      return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) add(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) add(u<<1|1, m+1, cr, ql, qr, val);
    pushup(u);
  }

  pii add(pii x, pii y){
    return {x.FI + y.FI, x.SE + y.SE};
  }
  LL query(int l, int r){
    pii p = query(1,1,n,l,r);
    return p.SE - p.FI * (l-1);
  }
  pii query(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return {v[u], wv[u]};
    int m = (cl+cr)/2; pushdown(u,cl,cr,m); pii s;
    if(ql <= m) s = add(s, query(u<<1, cl, m, ql, qr));
    if(m+1 <= qr) s = add(s, query(u<<1|1, m+1, cr, ql, qr));
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  sg.build(a,n);
  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int l,r,v; scanf("%d%d%d",&l,&r,&v);
      sg.add(l,r,v);
    }else{
      int l,r; scanf("%d%d",&l,&r);
      printf("%lld\n",sg.query(l,r));
    }
  }

  return 0;
}
