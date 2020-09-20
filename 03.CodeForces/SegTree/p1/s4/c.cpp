// Tag: 线段树 逆序对 iii
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

const int MAX = 1e5 + 20;
int n,m,a[MAX];
struct ST{
  struct Node{
    int v[41]; LL inv;  // inv: 区间内逆序对个数
    void clear(LL s = 0) { MST(v,0); inv = s; }
  }node[MAX<<2];

  Node merge(const Node &l, const Node &r){
    Node a; a.clear(l.inv + r.inv); int t = 0;
    ROR(i,40,1){
      a.v[i] = l.v[i] + r.v[i];
      a.inv += 1ll * t * r.v[i];
      t += l.v[i];
    }
    return a;
  }

  void pushup(int u){
    node[u] = merge(node[u<<1], node[u<<1|1]);
  }
  void build(int *a, int n){
    build(1,1,n,a);
  }
  void build(int u, int l, int r, int *a){
    if(l == r) { node[u].v[a[l]] = 1; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    pushup(u);
  }

  void set(int p, int val){
    set(1,1,n,p,val);
  }
  void set(int u, int l, int r, int p, int val){
    if(l == r){
      node[u].v[a[p]] = 0;
      a[p] = val;
      node[u].v[a[p]] = 1;
      return;
    }
    int m = (l+r)/2;
    if(p <= m) set(u<<1, l, m, p, val);
    else set(u<<1|1, m+1, r, p, val);
    pushup(u);
  }
  LL query(int l, int r){
    return query(1,1,n,l,r).inv;
  }
  Node query(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return node[u];
    int m = (cl+cr)/2; Node s; s.clear();
    if(ql <= m) s = merge(s, query(u<<1, cl, m, ql, qr));
    if(m+1 <= qr) s = merge(s, query(u<<1|1, m+1, cr, ql, qr));
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
      int l, r; scanf("%d%d",&l,&r);
      printf("%lld\n",sg.query(l,r));
    }else{
      int x, v; scanf("%d%d",&x,&v);
      sg.set(x,v);
    }
  }

  return 0;
}
