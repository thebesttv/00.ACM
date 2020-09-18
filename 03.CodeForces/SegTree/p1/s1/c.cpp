// Tag: 线段树
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

const int MAX = 100000 + 20;
int n,m,a[MAX];

struct ST{
  LL v[MAX<<2]; int vm[MAX<<2], cm[MAX<<2];
  void build(int *a, int n){
    build(1,1,n,a);
  }
  void pushup(int u){
    v[u] = v[u<<1] + v[u<<1|1];
    vm[u] = min(vm[u<<1], vm[u<<1|1]);
    cm[u] = (vm[u<<1] == vm[u] ? cm[u<<1] : 0)
          + (vm[u<<1|1] == vm[u] ? cm[u<<1|1] : 0);
  }
  void build(int u, int l, int r, int *a){
    if(l == r) { v[u] = vm[u] = a[l]; cm[u] = 1; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    pushup(u);
  }
  void set(int p, int val){
    set(1,1,n,p,val);
  }
  void set(int u, int l, int r, int p, int val){
    if(l == r) { v[u] = vm[u] = val; return; }
    int m = (l+r)/2;
    if(p <= m) set(u<<1, l, m, p, val);
    else set(u<<1|1, m+1, r, p, val);
    pushup(u);
  }
  LL sum(int l, int r){
    return sum(1,1,n,l,r);
  }
  LL sum(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return v[u];
    int m = (cl+cr)/2; LL s = 0;
    if(ql <= m) s += sum(u<<1, cl, m, ql, qr);
    if(m+1 <= qr) s += sum(u<<1|1, m+1, cr, ql, qr);
    return s;
  }
  int qMin(int l, int r){
    return qMin(1,1,n,l,r);
  }
  int qMin(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return vm[u];
    int m = (cl+cr)/2, s = INT_MAX;
    if(ql <= m) s = min(s, qMin(u<<1, cl, m, ql, qr));
    if(m+1 <= qr) s = min(s, qMin(u<<1|1, m+1, cr, ql, qr));
    return s;
  }

  pii qmc(int l, int r){
    return qmc(1,1,n,l,r);
  }
  pii qmc(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return {vm[u], cm[u]};
    int m = (cl+cr)/2, s = INT_MAX, c = 0;
    if(ql <= m){
      pii p = qmc(u<<1, cl, m, ql, qr);
      if(p.FI < s) s = p.FI, c = p.SE;
      else if(p.FI == s) c += p.SE;
    }
    if(m+1 <= qr){
      pii p = qmc(u<<1|1, m+1, cr, ql, qr);
      if(p.FI < s) s = p.FI, c = p.SE;
      else if(p.FI == s) c += p.SE;
    }
    return {s,c};
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  sg.build(a,n);
  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int p,v; scanf("%d%d",&p,&v);
      sg.set(p+1,v);
    }else{
      int l,r; scanf("%d%d",&l,&r);
      pii p = sg.qmc(l+1,r);
      printf("%d %d\n",p.FI,p.SE);
    }
  }

  return 0;
}
